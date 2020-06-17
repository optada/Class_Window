// Created by OPTada // Free for use //
// - - - - - - - - - - - - - - - - - //

#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Class_Window\OPTada_Window.h"

using namespace std;


int WINAPI WinMain(
	HINSTANCE hinstance,     // ���������� ���������� ���������� -- �������� ��� ������������� ������� ���������
	HINSTANCE hprevinstance, // � WIN32 �� ������������
	LPSTR lpcmdline,         // ����� ��� ������� ���� � ������ ��������� ������
	int ncmdshow             // ����� ����������� ���� (����������� ��� ���������� ���-��� WindowShow())
	)
{	

	// �������� ������������ ����
	if (!global_Window.InitAndCreateStandartWindow(hinstance)) { 
		return (global_Window.main_window_msg.wParam); // ���� ���� �� ��������� - ��������
	}

	/*
	if (!global_Window.Change(true, 1280, 720)) {
		MessageBox(NULL, L"main hange error", L"wind", NULL);
	};
	*/


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