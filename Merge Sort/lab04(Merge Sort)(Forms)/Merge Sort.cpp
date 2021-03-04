#include "Merge Sort.h"
#include <Windows.h>
using namespace lab04MergeSortForms;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MergeSort);
	return 0;
}