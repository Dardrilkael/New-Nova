#pragma once
#include "Core.h"

extern Nova::Application* Nova::CreateApplication();
int main()
{
	Nova::Log::Init();

	auto app = Nova::CreateApplication();
	app->Run();
	delete app;
	system("pause");
	return 0;
}