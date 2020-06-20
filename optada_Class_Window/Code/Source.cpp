// Created by OPTada // Free for use //
// - - - - - - - - - - - - - - - - - //

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Class_Window\OPTada_Window.h"


// process messages of the main window
static LRESULT CALLBACK WindowProc(
	HWND hwnd,
	UINT msg,
	WPARAM wparam,
	LPARAM lparam)
{
	PAINTSTRUCT	ps;  // using in WM_PAINT
	HDC			hdc; // getting device context

	// get massage
	switch (msg)
	{

	case WM_KEYDOWN: {
		switch (wparam)
		{

		case 0x46: { // pressed 'F' button

			global_Window.Do_SwapMode_Fullscreen_LastWindowed();

		} break;

		default: break;

		}
	} break;

	case WM_ACTIVATE: {

		OPTadaE_WindowState_ForClassWindow windowState;
		global_Window.Get_WindowState(windowState);

		// if fullscreen and focus occurs
		if (windowState == OPTadaE_WindowState_ForClassWindow::ENUM_WindowState_FullScreen
			&& IsIconic(hwnd) && WA_ACTIVE == LOWORD(wparam)) {

			global_Window.Do_RestoreFocusInFullscreenMode();
		}
		else {
			// if fullscreen and loss of focus occurs
			if (windowState == OPTadaE_WindowState_ForClassWindow::ENUM_WindowState_FullScreen
				&& WA_INACTIVE == LOWORD(wparam)) {

				global_Window.Do_LooseFocusInFullscreenMode();
			}
		}

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
};


// enter point
int WINAPI WinMain(
	HINSTANCE hinstance,     // application instance descriptor - acts as an identifier for a window procedure
	HINSTANCE hprevinstance, // in WIN32 is not used
	LPSTR lpcmdline,         // needed to run the window in command line mode
	int ncmdshow             // window display mode (needed for further WindowShow () functions)
	)
{	

	// create a standard window
	if (!global_Window.InitAndCreateStandartWindow(hinstance, WindowProc)) {
		return (global_Window.main_window_msg.wParam); // if the window did not create, close
	}

	OPTadaS_Window_Size newWindowSize;
	newWindowSize.width = 700;
	newWindowSize.height = 700;
	if (!global_Window.Change_DisplayOfWindow(OPTadaE_WindowState_ForClassWindow::ENUM_WindowState_WindowedWithNoBurders, newWindowSize)) {
		MessageBox(NULL, L"main hange error", L"wind", NULL);
	};

	newWindowSize.width = 800;
	newWindowSize.height = 600;
	if (!global_Window.Change_DisplayOfWindow(OPTadaE_WindowState_ForClassWindow::ENUM_WindowState_FullScreen, newWindowSize)) {
		MessageBox(NULL, L"main hange error", L"wind", NULL);
	};

	newWindowSize.width = 800;
	newWindowSize.height = 600;
	if (!global_Window.Change_DisplayOfWindow(OPTadaE_WindowState_ForClassWindow::ENUM_WindowState_Windowed, newWindowSize)) {
		MessageBox(NULL, L"main hange error", L"wind", NULL);
	};

	//newWindowSize.width = 1280;
	//newWindowSize.height = 720;
	//if (!global_Window.Change_DisplayOfWindow(OPTadaE_WindowState_ForClassWindow::ENUM_WindowState_Windowed, newWindowSize)) {
	//	MessageBox(NULL, L"main hange error", L"wind", NULL);
	//};


	float lastTime = (float)timeGetTime();

	// entering the program cycle
	while (true)
	{
		if (PeekMessage(&global_Window.main_window_msg, NULL, 0, 0, PM_REMOVE)) {
			if (global_Window.main_window_msg.message == WM_QUIT) { // check for exit command	
				break;
			}
			TranslateMessage(&global_Window.main_window_msg); // This function translates virtual-key format messages into character messages.			
			DispatchMessage(&global_Window.main_window_msg); // check, send WindowProc () commands to process window commands
		} 
		else {
			float currTime = (float)timeGetTime();
			float timeDelta = (currTime - lastTime) * 0.001f;

			// Tick(timeDelta); 

			lastTime = currTime;
		}
	}

	// Return window close command to window event handler
	return(global_Window.main_window_msg.wParam);
}