#pragma once

#ifdef UNICODE
	#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else 
	#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif


#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

#include <string>

#include <map>
#include <vector>
#include <string>
#include <atlimage.h>

#include "GameState_2D.h"
#include "SingleTon.h"
#include "GameTimer.h"
#include "Sound.h"

#include "GraphicObject_2D.h"
#include "SpriteObject_2D.h"

#include "RenderManager_2D.h"

#include "MyFunction.h"

#include "GameObject_2D.h"

//
#include "Draw_2D.h"

#include "Lusian_Scrool.h"

#define _OPTIMIZATION

#define WIDTH 1280
#define HEIGHT 600

#define WIDTH_POSITION 0
#define HEIGHT_POSITION 0

#define OBSTACLE_COUNT 8


//싱글톤
#define FRAMEWORK_2D	 CGameFrameWork_2D::GetInstance()
#define RENDERMGR_2D	 CRenderManager_2D::GetInstance()
#define SOUNDMGR		SoundManager::GetInstance()
#define TIMEMGR			CGameTimer::GetInstance()

static HINSTANCE g_hInstance;
static HWND g_Hwnd;

#define VK_A 0x41
#define VK_B 0x42
#define VK_C 0x43
#define VK_D 0x44	
#define VK_E 0x45
#define VK_F 0x46
#define VK_G 0x47
#define VK_H 0x48
#define VK_I 0x49
#define VK_J 0x4A
#define VK_K 0x4B
#define VK_L 0x4C
#define VK_M 0x4D
#define VK_N 0x4E
#define VK_O 0x4F
#define VK_P 0x50
#define VK_Q 0x51
#define VK_R 0x52
#define VK_S 0x53
#define VK_T 0x54
#define VK_U 0x55
#define VK_V 0x56
#define VK_W 0x57
#define VK_X 0x58
#define VK_Y 0x59
#define VK_Z 0x5A

static void gotoxy(int x, int y, const char *msg, ...)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	va_list arg;
	va_start(arg, msg);
	vprintf(msg, arg);
	va_end(arg);
	printf("\n");
}