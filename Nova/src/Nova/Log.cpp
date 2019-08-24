#include "novapch.h"
#include "Log.h"
//#include "spdlog/sinks/stdout_color_sinks.h"
#include <windows.h>
namespace Nova
{
	WORD* Log::colors = new WORD[9];
	HANDLE Log::s_Write_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	const WORD BOLD = FOREGROUND_INTENSITY;
	const WORD RED = FOREGROUND_RED;
	const WORD GREEN = FOREGROUND_GREEN;
	const WORD CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_BLUE;
	const WORD WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	const WORD YELLOW = FOREGROUND_RED | FOREGROUND_GREEN;
	const WORD BLUE = FOREGROUND_RED | FOREGROUND_GREEN;
	const WORD PURPLE = FOREGROUND_RED | FOREGROUND_BLUE;

	void Log::Init()
	{
		//CreateConsoleScreenBuffer(GENERIC_WRITE,0,)
		Log::colors[level_log::trace] = WHITE;
		Log::colors[level_log::debug] = CYAN;
		Log::colors[level_log::info] = GREEN;
		Log::colors[level_log::warn] = YELLOW | BOLD;
		Log::colors[level_log::error] = RED | BOLD;                         // red bold
		Log::colors[level_log::critical] = BACKGROUND_RED | WHITE | BOLD; // white bold on red background
		Log::colors[level_log::fatal] = FOREGROUND_RED | BOLD;
		Log::colors[level_log::special] = PURPLE | BOLD;
		Log::colors[level_log::off] = 0;

		SMALL_RECT window_size = { 0,0,WIDTH - 1,HEIGHT - 1 };
		COORD screen_buffer = { WIDTH,HEIGHT };
		SetConsoleWindowInfo(s_Write_handle, TRUE, &window_size);
		SetConsoleTitle(L"NOVA's Engine Debug Console");
		//SetConsoleScreenBufferSize(s_Write_handle, screen_buffer);
		//SetConsoleCursorPosition(s_Write_handle, { 500,0 });
	}

	void Log::Write(std::string text, Log::level_log lvl)
	{
		//text += '\n';
		SetConsoleTextAttribute(s_Write_handle, colors[lvl]);
		WriteConsoleA(s_Write_handle, text.data(), text.length(), NULL, NULL);
		//GetConsoleCursorInfo(s_Write_handle,)
	}

}