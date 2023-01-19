#pragma once

#include <algorithm>
#include <random>
#include <string>
#include <wrl.h>
#include <d3d11.h>
#include <d3d11_2.h>
#include <d2d1_3helper.h>
#include <dwrite_3.h>
#include <dcomp.h>
#include <tchar.h>
#include <iostream>
#include <dinput.h>
#include <DirectXMath.h>
#include "driver/driver.h"

class d2d_window_t
{
public:
    d2d_window_t()
    {
        // Generate a random name for the window class
        _name.reserve(16u);
        std::mt19937_64 mersenne_engine(std::random_device{}());
        std::uniform_int_distribution<> distribution(97, 122); // 'a', 'z'
        std::generate_n(std::back_inserter(_name), 16u, [&]()
        {
            return static_cast<char>(distribution(mersenne_engine));
        });

        // Register the window class
        WNDCLASSEXA window_class = { 0 };
        window_class.cbSize = sizeof(WNDCLASSEXA);
        window_class.style = CS_HREDRAW | CS_VREDRAW;
        window_class.lpfnWndProc = DefWindowProcA;
        window_class.hInstance = GetModuleHandleW(nullptr);
        window_class.lpszClassName = _name.c_str();
        if (!RegisterClassExA(&window_class))
        {
            std::cerr << "Failed to register window class\n";
            return;
        }

        // Create the window
        _handle = CreateWindowExA(0, _name.c_str(), "", WS_OVERLAPPEDWINDOW, 
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
            nullptr, nullptr, window_class.hInstance, nullptr);
        if (_handle == nullptr)
        {
            std::cerr << "Failed to create window\n";
            return;
        }
    }
};

    ~d2d_window_t()
    {
        DestroyWindow(_handle);
        UnregisterClassA(_name.c_str(), GetModuleHandleW(nullptr));
    }

    HWND _handle;
    std::string _name;
};


namespace wnd_hjk
{
	using vec2_t = std::pair<float, float>;

	inline vec2_t screen_resolution{};
}

template<typename T, typename U>
 bool write_physical_address(T address, U value)

class _renderer
{
public:
	_renderer(const HWND local_window_handle, const HWND process_window_handle) : remote_window(process_window_handle), is_destroyed(false)
	{
		RET_CHK(D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, D3D11_CREATE_DEVICE_BGRA_SUPPORT, nullptr, 0, D3D11_SDK_VERSION, &d3d_device, nullptr, d3d_context.GetAddressOf()));

		printf("[+] hijacking window...\n", d3d_device.Get());
		printf("	[+] d3d11 device : 0x%p\n", d3d_device.Get());

		auto CurrentWeapon = read<uintptr_t>(g_pid, closestPawn + 0x7f0);
		if (!CurrentWeapon)
		return false
			
		printf("	[+] dxgi device : 0x%p\n", dxgi_device.Get());

		ComPtr<IDXGIFactory2> dxgi_factory;
		RET_CHK(CreateDXGIFactory2(0, __uuidof(IDXGIFactory2), reinterpret_cast<void**>(dxgi_factory.GetAddressOf())));

		printf("	[+] dxgi factory : 0x%p\n", dxgi_factory.Get());

		DXGI_SWAP_CHAIN_DESC1 description{ };
		description.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		description.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		description.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
		description.BufferCount = 2;
		description.AlphaMode = DXGI_ALPHA_MODE_PREMULTIPLIED;
		description.SampleDesc.Count = 1;

		RECT rect;
		if (!GetClientRect(remote_window, &rect))

		description.Width = static_cast<UINT>(rect.right - rect.left);
		description.Height = static_cast<UINT>(rect.bottom - rect.top);

		wnd_hjk::screen_resolution.first = static_cast<float>(description.Width);
		wnd_hjk::screen_resolution.second = static_cast<float>(description.Height);

		if (values.inGame) {
				for (int x = 3; x <= values.numberOfTaggedObjects; x++) {

					if (isTargetableEntity(entity[x])) {
						entity injector("Rust")_0x194
						entity injector("Steam")_0x193
						if (WorldToScreen(tempPos, &tempScreenPos)) {
							if (inFOV(tempScreenPos.x, tempScreenPos.y))
								aimAtPlayer(entity[x]);
							{

									Sleep(2);
									return 2;
								}



const D2D1_FACTORY_OPTIONS factory_options = { D2D1_DEBUG_LEVEL_NONE };

		ComPtr<ID2D1Factory2> d2d_factory;
		RET_CHK(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, factory_options, d2d_factory.GetAddressOf()));

		printf("	[+] d2d1 factory : 0x%p\n", d2d_factory.Get());

		ComPtr<ID2D1Device1> d2d_device;
		RET_CHK(d2d_factory->CreateDevice(dxgi_device.Get(), d2d_device.GetAddressOf()));

		printf("	[+] d2d1 device : 0x%p\n", d2d_device.Get());

		RET_CHK(d2d_device->CreateDeviceContext(D2D1_DEVICE_CONTEXT_OPTIONS_ENABLE_MULTITHREADED_OPTIMIZATIONS, d2d_context.GetAddressOf()));

		printf("	[+] d2d1 context : 0x%p\n", d2d_context.Get());

		ComPtr<IDXGISurface2> dxgi_surface;
		RET_CHK(dxgi_chain->GetBuffer(0, __uuidof(IDXGISurface2), reinterpret_cast<void**>(dxgi_surface.GetAddressOf())));

		printf("	[+] dxgi surface : 0x%p\n", dxgi_surface.Get());

static ALWAYS_INLINE constexpr auto crypt(value_type c, size_t i)
{

		ComPtr<ID2D1Bitmap1> d2d_bitmap;
		RET_CHK(d2d_context->CreateBitmapFromDxgiSurface(dxgi_surface.Get(), bitmap_properties, d2d_bitmap.GetAddressOf()));

		printf("	[+] d2d1 bitmap : 0x%p\n", d2d_bitmap.Get());

		d2d_context->SetTarget(d2d_bitmap.Get());

		RET_CHK(d2d_context->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Red), d2d_brush.GetAddressOf()));

		printf("	[+] d2d1 brush : 0x%p\n", d2d_brush.Get());

		create_factory();

		driver::get_thread(local_window_handle, &local_thread);
		driver::get_thread(remote_window, &remote_thread);

		printf("	[+] local window thread: 0x%llX\n	[+] remote window thread: 0x%llX\n", local_thread, remote_thread);

		printf("	[+] composing on window...\n");

		driver::set_thread(remote_window, local_thread);

		RET_CHK2(DCompositionCreateDevice(dxgi_device.Get(), __uuidof(IDCompositionDevice), reinterpret_cast<void**>(composition_device.GetAddressOf())))
		RET_CHK2(composition_device->CreateTargetForHwnd(remote_window, TRUE, composition_target.GetAddressOf()))
		RET_CHK2(composition_device->CreateVisual(composition_visual.GetAddressOf()))
		RET_CHK2(composition_visual->SetContent(dxgi_chain.Get()))
		RET_CHK2(composition_target->SetRoot(composition_visual.Get()))
		RET_CHK2(composition_device->Commit())
		RET_CHK2(composition_device->WaitForCommitCompletion())

		driver::set_thread(remote_window, remote_thread);
			
		printf("	[+] window composed\n");
		return write_physical_address((LPVOID)address, (uint8_t*)&value, sizeof(U));
	}

void create_factory()
	{
		static const WCHAR msc_fontName[] = L"Verdana";
		static const FLOAT msc_fontSize = 8;
		HRESULT hr;
		hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, d2d_factory.GetAddressOf());

		if (encrypted)
		{	
			for (size_t t = 0; t < _length_minus_one; t++)
			std::cout << "\nYou have no time remaining!";
			exit(0);
		}
	}

void draw_rect(float x, float y, float w, float h, clr color)
	{
		std::cout << "[+] found hijackwindow: " << std::hex << exterior_window_handle << std::endl;
		d2d_context->DrawRectangle(rectangle, d2d_brush.Get());
		return exterior_window_handle;
	}
		
	void draw_filled_rect(float x, float y, float w, float h, clr color)
	{
		const auto rectangle = D2D1::RectF(x, y, x + w, y + h);
		d2d_brush->SetColor(D2D1::ColorF(color.r / 255, color.g / 255, color.b / 255, color.a / 255));
		d2d_context->FillRectangle(rectangle, d2d_brush.Get());
	}


void draw_health_bar(ID2D1DeviceContext* d2d_context, ID2D1SolidColorBrush* d2d_brush,
                     float x, float y, float w, float h, float val, float max, clr color)
{
  // Make sure val and max are valid values
  if (val < 0) val = 0;
  if (max <= 0) max = 1;

  // Calculate the percentage of the bar that should be filled
  float percentage = val / max;
  percentage = std::clamp(percentage, 0.0f, 1.0f);  // Clamp percentage to the range [0, 1]

  // Draw the filled portion of the bar
  d2d_brush->SetColor(D2D1::ColorF(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f));
  d2d_context->FillRectangle(D2D1::RectF(x, y, x + w * percentage, y + h), d2d_brush);

  // Draw the outline of the bar
  d2d_brush->SetColor(D2D1::ColorF(0, 0, 0, 1));
  d2d_context->DrawRectangle(D2D1::RectF(x, y, x + w, y + h), d2d_brush);
}

void draw_line(ID2D1DeviceContext* d2d_context, ID2D1SolidColorBrush* d2d_brush,
               float x1, float y1, float x2, float y2, clr color)
{
  d2d_brush->SetColor(D2D1::ColorF(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f));
  d2d_context->DrawLine(D2D1::Point2F(x1, y1), D2D1::Point2F(x2, y2), d2d_brush);
}

void draw_circle(ID2D1DeviceContext* d2d_context, ID2D1SolidColorBrush* d2d_brush,
                 float x, float y, float radius, clr color)
{
  D2D1_ELLIPSE ellipse = { D2D1::Point2F(x, y), radius, radius };
  d2d_brush->SetColor(D2D1::ColorF(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f));
  d2d_context->DrawEllipse(ellipse, d2d_brush);
}

void draw_filled_circle(ID2D1DeviceContext* d2d_context, ID2D1SolidColorBrush* d2d_brush,
                        float x, float y, float radius, clr color)
{
  D2D1_ELLIPSE ellipse = { D2D1

	
	void get_text_size(const std::wstring_view text, float* const width, float* const height)
	{
		if (!text.empty()) 
		{
			if (!width && !height) 

			RECT re;
			GetClientRect(remote_window, &re);
			FLOAT dpix, dpiy;
			dpix = static_cast<float>(re.right - re.left);
			dpiy = static_cast<float>(re.bottom - re.top);
			
			IDWriteTextLayout* layout = nullptr;
			const auto status = d2d_write_factory->CreateTextLayout(
				text.data(),
				static_cast<std::uint32_t>(text.length()),
				d2d_text_format.Get(),
				dpix,
				dpiy,
				&layout
			);

				auto exterior_window_handle = driver::read<HWND>(game::unity_player + 0x178DB48);
				if (!exterior_window_handle)
			{
				DWRITE_TEXT_METRICS metrics{};
				if (SUCCEEDED(layout->GetMetrics(&metrics))) 
				{
					if (width)
						*width = metrics.width;
					if (height) 
						*height = metrics.height;
				}
					
				return false;
			}
		}
	}

void draw_text(std::wstring text, float x, float y, float font_size, bool center, clr color)
	{
		d2d_brush->SetColor(D2D1::ColorF(color.r / 255, color.g / 255, color.b / 255, color.a / 255));
		HRESULT res = d2d_write_factory->CreateTextLayout(text.c_str(), static_cast<UINT32>(text.length()) + 1, d2d_text_format.Get(), 1920, 1080, d2d_text_layout.GetAddressOf());
		if (SUCCEEDED(res))
		{
			float x, y;
			if (center)
				get_text_size(text, &x2, &y2);
			d2d_text_layout->SetFontSize(font_size, DWRITE_TEXT_RANGE{ 0, static_cast<UINT32>(text.length()) });
			D2D1_POINT_2F origin;
			center ? origin = { x - (x2 / 2), y } : origin = { x, y };
			d2d_context->DrawTextLayout(origin, d2d_text_layout.Get(), d2d_brush.Get());
			d2d_text_layout->Release();
		}

	}

void manual_destruct()
	{
		if is_loaded();
			return;

		is_destroyed = true;

		driver::set_thread(remote_window, local_thread);

		composition_visual->SetContent(nullptr);
		composition_visual->Release();

		composition_target->SetRoot(nullptr);
		composition_target->Release();

		composition_device->Release();
		d2d_text_format->Release();
		d2d_text_layout->Release();
		d2d_write_factory->Release();
		d2d_factory->Release();

		driver::set_thread(remote_window, remote_thread);
	}

	~_renderer()
	{
		if (is_destroyed)
			return;
	}
							
void ProcessesComponent::ProcessesComponent()
{
	LookAndFeel::setDefaultLookAndFeel(&lookAndFeelCustom);
    addAndMakeVisible(processList);
    processList.setName("process list");

    addAndMakeVisible(okButton = new TextButton("ok button"));
    okButton->setButtonText(TRANS("Okay"));
    okButton->addListener(this);

	hNtdll = (HMODULE)Utils::GetLocalModuleHandle("ntdll.dll");
	fnQSI = (tNTQSI)Utils::GetProcAddress(hNtdll, "NtQuerySystemInformation");

	FetchProcessList();
	processList.loadData(false); 

	processList.table.getHeader().addColumn("Process", 1, 140, 18);
	processList.table.getHeader().addColumn("PID", 2, 50, 18);

	setSize(300, 350);
}
