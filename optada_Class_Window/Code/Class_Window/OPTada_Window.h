// Created by OPTada // Free for use //
// - - - - - - - - - - - - - - - - - //

#pragma once

#include <windows.h>

#include "OPTada_Window_Settings.h"


// enum for class window - window states
enum OPTadaE_WindowState_ForClassWindow
{
	NONE                                   = 0, // - 
	ENUM_WindowState_Windowed              = 1, // Windowed
	ENUM_WindowState_WindowedWithNoBurders = 2, // Windowed with no borders
	ENUM_WindowState_FullScreen            = 3, // Fullscreen
};


// Structure of size (Width - X  | Height - Y)
struct OPTadaS_WindowSize
{
	int Width  = 0; // X
	int Height = 0; // Y
};


// Класс главного окна
class OPTada_Window
{
private:

	OPTadaE_WindowState_ForClassWindow WindowState = OPTadaE_WindowState_ForClassWindow::NONE; // Current state of window 

	OPTadaS_WindowSize WindowSize;    // Size of window (with borders)
	OPTadaS_WindowSize WorkplaceSize; // Size of workplace

	HWND      main_window_handle;    // window handle (links to access the window)
	HINSTANCE main_window_hinstance; // индикатор оконной процедуры  

public:

	MSG       main_window_msg; // дескриптор сообщений окна (для обработки сообщений окна)


	// метод создает стандартное окно
	// [in] HINSTANCE hinstance_
	bool InitAndCreateStandartWindow(HINSTANCE hinstance_);

	// метод менеяет настройки отображения окна
	// [in] OPTadaE_WindowState_ForClassWindow new_WindowState_
	// [in] OPTadaS_WindowSize& new_WorkplaceSize_
	//bool Change_DisplayOfWindow(OPTadaE_WindowState_ForClassWindow new_WindowState_, OPTadaS_WindowSize& new_WorkplaceSize_);



	// дописать изменение при графике!!! (все вроде работает....)
	// Меняет полноэкранный на оконный и наоборот (разрешение не меняет) +
	//void switchFullscreen();

	// метод меняет настройки окна на полноэкранные (разрешение не меняет) +
	//void setWindowFullscreen();

	// метод меняет настройки окна на оконные (разрешение не меняет) +
	//void setWindowBordered();

	// меняем разрешение монитора на разрешение окна +
	//void setMonitorFullscreen();

	// восстанавливам разрешение монитора +
	//void setMonitorWindowed();
};


// Created class OPTada_Window for main window
static OPTada_Window global_Window;


// обработка сообщений главного окна
static LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);