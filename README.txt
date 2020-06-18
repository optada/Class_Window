HI! My nick is - OPTada. This project - (Сlass_Window), is my pet-project. 
GitHub   : https://github.com/optada/Class_Window

my mail@ : druzhinin.optada@gmail.com

// --------------------------------------------------------------------------------------------------
// Description

The project is aimed at the Windows platform.
This project contains a class that provides organized solutions for more convenient creation.
and window controls in Windows. Also, the project contains a ready-made solution of the reactions on (ALT + TAB),
switching to full-screen mode and vice versa (with monitor tuning), changing the display mode of the window.


// --------------------------------------------------------------------------------------------------
// Functional

OPTada_Window - a class that provides functionality for working with a window under Windows.
It must be initialized before use. During initialization, a window is created.
In the OPTada_Window_Settings.h file, you can configure some automatic settings.

This project also contains various window event handlers and low-level keyboard processing.

project for WIN_x64, but you can rebild it easy to WIN_x32


// --------------------------------------------------------------------------------------------------
// Architecture

To use this class, the following .lib will be required:
winmm.lib (include to your project)

#include <windows.h>
#include <windowsx.h>

OPTada_Window - a class that provides functionality for working with a window under Windows.

// --------------------------------------------------------------------------------------------------
// Integrate 

To integrate the memory manager, follow the instructions:
1) put the folder Class_window in your project. (optada�_Class_Window --> code --> )
2) Include the OPTada_Window.h header file
3) Use global_Window for create and controll window


// --------------------------------------------------------------------------------------------------
// Usage tips

Use this class to create the MAIN window.
Do not create more objects of the OPTada_Window class to avoid errors.
When using additional reactions to keys and their improvements, study the code!
If you switched to full-screen or full-screen-window mode, use ALT + F4 to close the application.


// --------------------------------------------------------------------------------------------------
If you find a mistake|bug|error, please describe it and write to me:
on my mail@ : druzhinin.optada@gmail.com
or GitHub   : https://github.com/optada/Class_Window