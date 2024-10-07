#pragma once

#ifdef BB_PLATFORM_WINDOWS

// ���� CreateApplication ����λ�ڱ���ļ���
extern Bamboo::Application* Bamboo::CreateApplication();

int main(int argc, char** argv)
{
	BB_CORE_TRACE("Welcome To Bamboo Game Engine!!!");
	Bamboo::Application* app = Bamboo::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Bamboo only supports windows now!
#endif // BB_PLATFORM_WINDOWS

