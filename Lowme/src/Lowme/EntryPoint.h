#pragma once

#ifdef LM_PLATFORM_WINDOWS

extern Lowme::Application* Lowme::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Lowme::CreateApplication();
	app->Run();
	delete app;
}

#endif