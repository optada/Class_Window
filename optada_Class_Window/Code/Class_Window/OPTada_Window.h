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


// ����� �������� ����
class OPTada_Window
{
private:

	OPTadaE_WindowState_ForClassWindow WindowState = OPTadaE_WindowState_ForClassWindow::NONE; // Current state of window 

	OPTadaS_WindowSize WindowSize;    // Size of window (with borders)
	OPTadaS_WindowSize WorkplaceSize; // Size of workplace

	HWND      main_window_handle;    // window handle (links to access the window)
	HINSTANCE main_window_hinstance; // ��������� ������� ���������  

public:

	MSG       main_window_msg; // ���������� ��������� ���� (��� ��������� ��������� ����)


	// ����� ������� ����������� ����
	// [in] HINSTANCE hinstance_
	bool InitAndCreateStandartWindow(HINSTANCE hinstance_);

	// ����� ������� ��������� ����������� ����
	// [in] OPTadaE_WindowState_ForClassWindow new_WindowState_
	// [in] OPTadaS_WindowSize& new_WorkplaceSize_
	//bool Change_DisplayOfWindow(OPTadaE_WindowState_ForClassWindow new_WindowState_, OPTadaS_WindowSize& new_WorkplaceSize_);



	// �������� ��������� ��� �������!!! (��� ����� ��������....)
	// ������ ������������� �� ������� � �������� (���������� �� ������) +
	//void switchFullscreen();

	// ����� ������ ��������� ���� �� ������������� (���������� �� ������) +
	//void setWindowFullscreen();

	// ����� ������ ��������� ���� �� ������� (���������� �� ������) +
	//void setWindowBordered();

	// ������ ���������� �������� �� ���������� ���� +
	//void setMonitorFullscreen();

	// �������������� ���������� �������� +
	//void setMonitorWindowed();
};


// Created class OPTada_Window for main window
static OPTada_Window global_Window;


// ��������� ��������� �������� ����
static LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);