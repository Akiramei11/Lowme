#pragma once

#ifdef LM_PLATFORM_WINDOWS

extern Lowme::Application* Lowme::CreateApplication();

int main(int argc, char** argv)
{
	Lowme::Log::Init();
	LM_CORE_WARN("Initialized Log!");
	int a = 5;
	LM_INFO("Hello! Var={0}", a);

	auto app = Lowme::CreateApplication();
	app->Run();
	delete app;
}

#endif