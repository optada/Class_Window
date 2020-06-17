// Created by OPTada // Free for use //
// - - - - - - - - - - - - - - - - - //

#include "OPTada_Window.h"


bool OPTada_Window::InitAndCreateStandartWindow(HINSTANCE hinstance_)
{
	WNDCLASSEX winclass; // this will hold the class we create
	HWND	   hwnd;	 // generic window handle              
	//MSG	     msg;	   // generic message                    
	//HDC        hdc;      // graphics device context            

	// filling the class structure
	winclass.cbSize        = sizeof(WNDCLASSEX);                              // structure value (in bytes)
	winclass.style         = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW; // window style, declared by flags
	winclass.lpfnWndProc   = WindowProc;                                      // pointer to the name of the user-defined function (for processing window messages)
	winclass.cbClsExtra    = 0;										          // the number of bytes freed at the end of the structure
	winclass.cbWndExtra    = 0;                                               // number of bytes freed when creating an instance of the structure
	winclass.hInstance     = hinstance_;                                      // ... application instance
	winclass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);                 // ... icon handle
	winclass.hCursor       = LoadCursor(NULL, IDC_ARROW);                     // ... cursor
	winclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);             // ... window background color
	winclass.lpszMenuName  = NULL;                                            // pointer to a string containing the name of the menu used for the class
	winclass.lpszClassName = L"WIN3DCLASS";                                   // pointer to a string containing the class name
	winclass.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);                 // ... small icon (in tray)

	// class registration
	if (!RegisterClassEx(&winclass)) {
		MessageBox(NULL, L"Class registration ERROR!", L"ERROR optada_window", MB_OK);
		return(0);
	}

	// create window
	if (!(hwnd = CreateWindowEx( 
		NULL,                                                                  // styles
		L"WIN3DCLASS",                                                         // class name
		L"WINDOW NAME",                                                        // ... window name(inscription above)
		WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX | WS_VISIBLE, // ... window display modes 
		0, 0,	                                                               // window display along x and y axes respectively
		OPTADA_CLASSWINDOW_DEFAULT_WIDTH, OPTADA_CLASSWINDOW_DEFAULT_HEIGHT,   // ... the width and height of the window (width || height), respectively
		NULL,	                                                               // parent window handle
		NULL,	                                                               // setting the menu handle
		hinstance_,                                                            // ... install an application instance
		NULL))                                                                 // (do not pass anything from WndProc)
		) 
	{
		MessageBox(NULL, L"Creating window ERROR!", L"ERROR optada_window", MB_OK);
		return(0);
	}

	main_window_hinstance = hinstance_; // save window indicator
	main_window_handle    = hwnd;       // save window handle
	//main_window_msg       = msg;        // saving the window message descriptor (for processing window messages)

	return (1);
}



LRESULT CALLBACK WindowProc(HWND hwnd,
	UINT msg,
	WPARAM wparam,
	LPARAM lparam)
{
	PAINTSTRUCT	ps;		   // using in WM_PAINT
	HDC			hdc;	   // getting device context

	// get massage
	switch (msg)
	{

	case WM_KEYDOWN: {
		switch (wparam)
		{
		case 0x46: // pressed 'F' button
			// global_Window.switchFullscreen();
			break;
		default:
			break;
		}
	} break;

	case WM_ACTIVATE: {
		/*
		if (!Screen_Windowed && IsIconic(hwnd) && WA_ACTIVE == LOWORD(wparam)) // если полноэкранный и происходит фокусировка
		{
			global_Window.setMonitorFullscreen();
			SetWindowPlacement(hwnd, &fullscreenPlacement);
		}
		else
		{
			if (!Screen_Windowed && WA_INACTIVE == LOWORD(wparam)) // если полноэкранный и происходит потеря фокуса
			{
				ShowWindow(global_Window.main_window_handle, SW_MINIMIZE);
			}
		}
		*/
	} break;

	case WM_CREATE: {
		// all necessary initialization when creating a window occurs here
		return(0);
	} break;

	case WM_PAINT: {
		// start drawing
		hdc = BeginPaint(hwnd, &ps);
		// end of drawing
		EndPaint(hwnd, &ps);
		return(0);
	} break;

	case WM_DESTROY: {
		// delete window	
		PostQuitMessage(0);
		return(0);
	} break;

	default:break;

	} // end switch

	// window completionand windows control return
	return (DefWindowProc(hwnd, msg, wparam, lparam));
} 

