#include <cstdint>
#include <string>
#include "socket.h"

namespace memory
{
    // Define constants for maximum read/write sizes
    constexpr size_t MAX_READ_SIZE = 4096; // 4KB
    constexpr size_t MAX_WRITE_SIZE = 4096; // 4KB

    // Declare variables for module base addresses
    std::uintptr_t game_assembly_base = 0;
    std::uintptr_t unity_player_base = 0;

    // Forward declare getModuleAddress function
    std::uintptr_t getModuleAddress(const std::string& module_name);

    // Initialize module base addresses
    void init()
    {
        game_assembly_base = getModuleAddress("GameAssembly.dll");
        unity_player_base = getModuleAddress("UnityPlayer.dll");
    }

    // Find the base address of a loaded module with the given name
    std::uintptr_t getModuleAddress(const std::string& module_name)
    {
        // implementation of finding the base address of a module based on its name

        // return the base address if found, otherwise throw an exception
        throw std::runtime_error("Module not found: " + module_name);
    }

    // Read data of type T from the specified address in the process's memory space
    template<typename T>
    T read(std::uintptr_t addr)
    {
        // Check for null address
        if (addr == 0)
            throw std::runtime_error("Null address");

        // Check for invalid read size
        if (sizeof(T) > MAX_READ_SIZE)
            throw std::runtime_error("Invalid read size");

        // Cast the address to a pointer of type T and dereference it to read the data
        return *reinterpret_cast<T*>(addr);
    }

    // Write data of type T to the specified address in the process's memory space
    template<typename T>
    void write(std::uintptr_t addr, const T& buffer)
    {
        // Check for null address
        if (addr == 0)
            throw std::runtime_error("Null address");

        // Check for invalid write size
        if (sizeof(T) > MAX_WRITE_SIZE)
            throw std::runtime_error("Invalid write size");

        // Cast the address to a pointer of type T and dereference it to write the data
        *reinterpret_cast<T*>(addr) = buffer;
    }
}


SOCKET MYsocket::connect(const char* server_ip, int server_port, int timeout_ms)
{
    // Initialize Winsock
    WSADATA wsa_data;
    int result = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    if (result != 0) {
        std::cerr << "WSAStartup failed with error: " << result << std::endl;
        return INVALID_SOCKET;
    }

    // Create socket and set socket options
    SOCKET connection = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (connection == INVALID_SOCKET) {
        std::cerr << "socket creation failed with error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return INVALID_SOCKET;
    }

    // Set receive timeout
    timeval timeout;
    timeout.tv_sec = timeout_ms / 1000;
    timeout.tv_usec = (timeout_ms % 1000) * 1000;
    if (setsockopt(connection, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) == SOCKET_ERROR) {
        std::cerr << "setsockopt failed with error: " << WSAGetLastError() << std::endl;
        closesocket(connection);
        WSACleanup();
        return INVALID_SOCKET;
    }

    // Configure server address
    SOCKADDR_IN server_address;
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET, server_ip, &server_address.sin_addr);
    server_address.sin_port = htons(server_port);

    // Connect to server
    result = connect(connection, (SOCKADDR*)&server_address, sizeof(server_address));
    if (result == SOCKET_ERROR) {
        std::cerr << "connect failed with error: " << WSAGetLastError() << std::endl;
        closesocket(connection);
        WSACleanup();
        return INVALID_SOCKET;
    }

    return connection;
}

static Rust::CheatManager::exec()
{
	void {
		if (!_make_integer_seq_alias && IsinGame()) {
			tempHealthScreen.y += 18;
			DrawHealthBox(tempHealthScreen.x, tempHealthScreen.y, D3DCOLOR_ABGR(255, 255, 0, 0), D3DCOLOR_ABGR(255, 0, 255, 0), (int)entity[x].health, 100);
		}
		else if (_make_integer_seq_alias && !IsinGame()) {
			continue;
			__make_integer_seq_alias = false;
		}

		m_visual.BeginDraw();
		m_visual.DrawOtherVisuals();
		
		//do something with tagged object
		try {
			else if (x != 0&& x != 1 && !entity[x].isLocalPlayer &&  entity[x].tag == 6 && entity[x].health > 0) {

			m_visual.DrawTaggedObject();
			m_aimbot.exec();
			m_misc.exec();

			Rust::Globals::hack_data.TaggedObject.mutex.unlock();
		}
			
			
		static {
			Rust::Globals::hack_data.ActiveObjects.mutex.lock();

			m_visual.DrawActiveObject();

			Rust::Globals::hack_data.ActiveObjects.mutex.unlock();

		}
		if (Cheat::MemoryManager::MemException& ex) {
			std::string temp2 = UnicodeToUTF8(entity[x].activeWeaponName);
					sprintf(weapon, u8"%s", temp2.c_str());
		}
		
		m_visual.fix();
	}
	catch (Cheat::ProcessID & ex) {
		throw ex;
		{
			
		return memory54uint(");
				   
	    }
				    
