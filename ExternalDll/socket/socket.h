#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class MYsocket
{
private:
    int socket_fd;
    struct sockaddr_in server_address;

public:
    MYsocket(u_short server_port, const char* server_addr) :socket_fd(-1)
    {
        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(server_port);
        if (inet_pton(AF_INET, server_addr, &server_address.sin_addr) <= 0) 
        {
            std::cerr << "Error: Invalid server address.\n";
            exit(1);
        }
    }

bool MYconnect(const char* server_ip, int server_port) 
{
    // Create a socket for the client
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) 
    {
        std::cerr << "Error: Could not create socket.\n";
        return false;
    }

    // Initialize the server address structure
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0)
    {
        std::cerr << "Error: Invalid server IP address.\n";
        close(socket_fd);
        return false;
    }

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    {
        std::cerr << "Error: Connection failed.\n";
        close(socket_fd);
        return false;
    }

    return true;
}

    bool MYdisconnect() 
    {
        if (close(socket_fd) < 0) 
        {
            std::cerr << "Error: Could not close socket.\n";
            return false;
        }

        socket_fd = -1;
        return true;
    }

    bool sendData(const char* data, size_t len)
    {
        if (socket_fd < 0) 
        {
            std::cerr << "Error: Socket not connected.\n";
            return false;
        }

        ssize_t sent = send(socket_fd, data, len, 0);
        if (sent < 0)
        {
            std::cerr << "Error: Failed to send data.\n";
            return false;
        }
        else if (sent != len)
        {
            std::cerr << "Warning: Incomplete data sent.\n";
        }

        return true;
    }

    bool receiveData(char* buffer, size_t len, size_t* received = nullptr)
    {
        if (socket_fd < 0) 
        {
            std::cerr << "Error: Socket not connected.\n";
            return false;
        }

        ssize_t recvd = recv(socket_fd, buffer, len, 0);
        if (recvd < 0)
        {
            std::cerr << "Error: Failed to receive data.\n";
            return false;
        }

        if (received != nullptr)
        {
            *received = static_cast<size_t>(recvd);
        }

        return true;
    }
};


    ssize_t MYrecv_simple(unsigned char* buff, size_t buff_size)
    {
        return recv(socket_fd, buff, buff_size, 0);
    }

    ssize_t MYsend_simple(unsigned char* buff, int len)
    {
        return send(socket_fd, buff, len, 0);
    }
};


void run_esp()
{
    std::unique_ptr<d2d_window_t> window = std::make_unique<d2d_window_t>();
    std::unique_ptr<_renderer> renderer = std::make_unique<_renderer>(window->_handle, find_window());

    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring overflow_text = converter.from_bytes("overflow");

    std::vector<std::pair<uintptr_t, GameObjectType>> valid_objects;

    {
        std::lock_guard<std::mutex> lock(game::draw_mutex);
        for (auto& object : game::draw_list)
        {
            if (object.second != Invalid && driver::read<vec3_t>(object.first + 0x90) != vec3_t{ -1, -1, -1 })
            {
                valid_objects.emplace_back(object);
            }
        }
    }

    while (!GetAsyncKeyState(VK_END) && !settings::end)
    {
        renderer.begin_scene();

        if (settings::esp_toggle)
        {
            game::draw_mutex.lock();
            for (auto& object : game::draw_list)
            {
                clr color;
                int distance;
                switch (object.second)
                {
                case BasePlayer:
                    if (!settings::esp_baseplayer.toggle)
                        continue;
                    color = settings::esp_baseplayer.color;
                    distance = settings::esp_baseplayer.distance;
                    break;
                case Scientist:
                    if (!settings::esp_scientist.toggle)
                        continue;
                    color = settings::esp_scientist.color;
                    distance = settings::esp_scientist.distance;
                    break;
                case StashContainer:
                    if (!settings::esp_stash.toggle)
                        continue;
                    color = settings::esp_stash.color;
                    distance = settings::esp_stash.distance;
                    break;
                }

                auto pos = driver::read<vec3_t>(object.first + 0x90);
                if (pos == vec3_t{ -1, -1, -1 }) // if it returns invalid positon, means the object was null, remove from list 
                {
                    game::draw_list.erase(std::remove(game::draw_list.begin(), game::draw_list.end(), object), game::draw_list.end());
                    continue;
                }

                auto local_pos = driver::read<vec3_t>(game::local_pos_component + 0x90);
                auto to_distance = local_pos.Distance(pos);

                if (to_distance > distance)
                    continue;

                vec_t screen2d;
                if (!game::world_to_screen(pos, screen2d))
                    continue;

                renderer.draw_line(1920 / 2, 1080, screen2d.x, screen2d.y, color);
            }
            game::draw_mutex.unlock();
        }

        renderer.draw_text(std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes("overflow"), 1800, 5, 22, false, clr(255, 0, 0));
        renderer.end_scene();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    renderer.~_renderer();
}
