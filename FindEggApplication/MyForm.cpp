#include "MyForm.h"

#include <opencv2/opencv.hpp>

#include <Windows.h>

using namespace FindEggApplication;

[STAThreadAttribute]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}