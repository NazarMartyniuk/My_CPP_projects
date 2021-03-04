#include "MyForm.h"
#include "windows.h"
#include <chrono>
#include <iostream>
#include <algorithm>

using namespace System;
using namespace System::Windows::Forms;

using namespace std;

HANDLE hMutex;
HANDLE hSemaphore;
volatile unsigned locked = false;

CRITICAL_SECTION cs;

HANDLE* handles;
unsigned int ThreadCount;
unsigned long param;
int step;
std::chrono::duration<double> TotalTime;

int* arr;//for 2 task
int* MinElements; //for 2 task
int TotalMinElement;
bool IsFirst = false;

int** Parametrs; // for Func1,Func2 arguments

void(_stdcall* FuncPtr)(int* curent_thread);
[STAThreadAttribute]
void main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Lab7OS::MyForm form; // Here you should set your project namespace
	Application::Run(% form);
}

void FreeMemory() // free memory of global values
{
	if (handles)
	{
		for (size_t i = 0; i < ThreadCount; i++)
		{
			CloseHandle(handles[i]);
		}

		delete[] handles;
		handles = nullptr;
		
	}

	if (hMutex)
	{
		CloseHandle(hMutex);
	}

	if (hSemaphore)
	{
		CloseHandle(hSemaphore);
	}

	if (arr)
	{
		delete[] arr;
		arr = nullptr;
	}

	if (MinElements)
	{
		delete[] MinElements;
		MinElements = nullptr;
	}
	if (Parametrs)
	{
		for (size_t i = 0; i < ThreadCount; i++)
		{
			delete[] Parametrs[i];
		}
		delete[] Parametrs;
		Parametrs = nullptr;
	}
}

void WINAPI Func1(int* curent_thread) // for Task 1
{
	WaitForSingleObject(hMutex, INFINITE);
	//WaitForSingleObject(hSemaphore, INFINITE);
	int start = step * (*curent_thread);
	int end = step * ((*curent_thread) + 1);

	auto StartTime = std::chrono::high_resolution_clock::now();

	for (size_t i = start; i < end; i++)
	{
		cout << "Thread " << *curent_thread + 1 << ":  " << "Martyniuk Nazar\n";
	}
	auto EndTime = std::chrono::high_resolution_clock::now();

	TotalTime += EndTime - StartTime;
	ReleaseMutex(hMutex);
	//ReleaseSemaphore(hSemaphore, 1, nullptr);
}


void WINAPI Func2(int* curent_thread)
{
	int start = step * (*curent_thread);
	int end = step * ((*curent_thread) + 1);

	auto StartTime = std::chrono::high_resolution_clock::now();
	int MinElem = arr[start];
	for (size_t i = start + 1; i < end; i++)
	{
		if (MinElem > arr[i])
		{
			MinElem = arr[i];
		}
	}

	auto EndTime = std::chrono::high_resolution_clock::now();

	TotalTime += EndTime - StartTime;
	MinElements[*curent_thread] = MinElem;

	//EnterCriticalSection(&cs);
	while (InterlockedExchange(&locked, 1) == 1)
		Sleep(0);
	cout << "Thread " << *curent_thread + 1 << ":  min element: " << MinElem << endl;
	
	if (!IsFirst)
	{
		IsFirst = true;
		TotalMinElement = MinElem;
	}
	else
	{
		if (TotalMinElement > MinElem)
		{
			TotalMinElement = MinElem;
		}
	}
	//LeaveCriticalSection(&cs);
	InterlockedExchange(&locked, 0);
}


String^ priority(DWORD code)
{
	switch (code)
	{
	case 1: return "Above normal";
	case -1: return "below normal";
	case 0: return "Normal";
	case -15: return "Idle";
	case 2: return "Hight";
	default: return "";
	}

}

System::Void Lab7OS::MyForm::Task1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	Task_Info->Text = "Iteration count:";
}

System::Void Lab7OS::MyForm::Task2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	Task_Info->Text = "Matrix size(NxN):";
}

System::Void Lab7OS::MyForm::Task3_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	Task_Info->Text = "Array size:";
}

System::Void Lab7OS::MyForm::Create_Threads_Click(System::Object^ sender, System::EventArgs^ e)
{
	FreeMemory();
	TotalTime = chrono::milliseconds::zero();

	ThreadCount = Convert::ToInt32(comboBox1->Text);
	Grid1->RowCount = ThreadCount;
	param = Convert::ToInt64(textBox1->Text);
	handles = new void* [ThreadCount];
	numericUpDown1->Maximum = ThreadCount;

	step = param / ThreadCount;
	DWORD ThreadID;

	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CON", "w", stdout);


	Parametrs = new int* [ThreadCount];

	for (size_t i = 0; i < ThreadCount; i++)
	{
		Parametrs[i] = new int;
		Parametrs[i][0] = i;
	}

	if (Task1->Checked)
	{
		FuncPtr = Func1;
		cout << "=================================================  CYCLIC OUTPUT TASK  =================================================\n";
		hMutex = CreateMutexA(nullptr, FALSE, nullptr);
		//hSemaphore = CreateSemaphoreA(NULL, 1, 1, NULL);
	}

	else
	{
		arr = new int[param];

		for (size_t i = 0; i < param; i++)
		{
			arr[i] = rand() % 501 - 250;
		}

		cout << "=================================================  ARRAY TASK  =================================================\n";
		for (size_t i = 0; i < param; i++)
		{
			cout << " " << arr[i];
		}

		MinElements = new int[ThreadCount];
		cout << endl;
		FuncPtr = Func2;
		//InitializeCriticalSection(&cs);
	}

	for (size_t i = 0; i < ThreadCount; i++)
	{

		if (!(handles[i] = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)FuncPtr, Parametrs[i], CREATE_SUSPENDED, &ThreadID)))
		{
			MessageBox::Show("ERROR!\nThread wasn't created");
		}


		Grid1->Rows[i]->Cells[0]->Value = i + 1;
		Grid1->Rows[i]->Cells[1]->Value = ThreadID;
		Grid1->Rows[i]->Cells[2]->Value = priority(GetThreadPriority(handles[i]));
		Grid1->Rows[i]->Cells[3]->Value = "Suspended";
	}
}

System::Void Lab7OS::MyForm::MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	FreeMemory();
}

System::Void Lab7OS::MyForm::Run_all_Click(System::Object^ sender, System::EventArgs^ e)
{
	TotalMinElement = 0;
	int handleCounter = 0;
	HANDLE threadHandles[16];
	for (int i = 0; i < ThreadCount; ++i)
	{
		if (Grid1->Rows[i]->Cells[3]->Value == "Finnished")
		{
			continue;
		}
		threadHandles[handleCounter++] = handles[i];
	}


	for (int i = 0; i < ThreadCount; ++i)
	{
		if (Grid1->Rows[i]->Cells[3]->Value == "Finnished")
		{
			continue;
		}

		Grid1->Rows[i]->Cells[3]->Value = "Running";

		ResumeThread(handles[i]);
	}

	WaitForMultipleObjects(handleCounter, threadHandles, TRUE, INFINITE);

	if (Task3->Checked)
	{
		cout << "Total min element = " << TotalMinElement << endl;
	}
	
	Time_Field->Text = Convert::ToString(TotalTime.count());

	for (int i = 0; i < ThreadCount; ++i)
	{
		Grid1->Rows[i]->Cells[3]->Value = "Finnished";
	}


}

System::Void Lab7OS::MyForm::comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	switch (comboBox3->SelectedIndex + 1)
	{
	case 1:
	{
		SetThreadPriority(handles[Convert::ToInt32(numericUpDown1->Value) - 1], -15);

		Grid1->Rows[Convert::ToInt32(numericUpDown1->Value) - 1]->Cells[2]->Value = "Idle";
		break;
	}
	case 2:
	{
		SetThreadPriority(handles[Convert::ToInt32(numericUpDown1->Value) - 1], -1);
		Grid1->Rows[Convert::ToInt32(numericUpDown1->Value) - 1]->Cells[2]->Value = "Below normal";
		break;
	}

	case 3:
	{
		SetThreadPriority(handles[Convert::ToInt32(numericUpDown1->Value) - 1], 0);
		Grid1->Rows[Convert::ToInt32(numericUpDown1->Value) - 1]->Cells[2]->Value = "Normal";
		break;
	}

	case 4:
	{
		SetThreadPriority(handles[Convert::ToInt32(numericUpDown1->Value) - 1], 1);
		Grid1->Rows[Convert::ToInt32(numericUpDown1->Value) - 1]->Cells[2]->Value = "Above normal";
		break;
	}
	case 5:
	{
		SetThreadPriority(handles[Convert::ToInt32(numericUpDown1->Value) - 1], 2);
		Grid1->Rows[Convert::ToInt32(numericUpDown1->Value) - 1]->Cells[2]->Value = "High";
		break;
	}
	}
}

System::Void Lab7OS::MyForm::numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (Grid1->Rows[Convert::ToInt32(numericUpDown1->Value) - 1]->Cells[3]->Value == "Finnished")
	{
		Run->Enabled = false;
		Pause->Enabled = false;
		comboBox3->Enabled = false;
	}
	else
	{
		Run->Enabled = true;
		Pause->Enabled = true;
		comboBox3->Enabled = true;
	}
	switch (GetThreadPriority(handles[Convert::ToInt32(numericUpDown1->Value) - 1]))
	{
	case 1: comboBox3->SelectedIndex = 3; break;
	case -1: comboBox3->SelectedIndex = 1; break;
	case 0: comboBox3->SelectedIndex = 2; break;
	case -15: comboBox3->SelectedIndex = 0; break;
	case 2: comboBox3->SelectedIndex = 4; break;
	}

}

System::Void Lab7OS::MyForm::Pause_Click(System::Object^ sender, System::EventArgs^ e)
{
	Grid1->Rows[Convert::ToInt32(numericUpDown1->Value) - 1]->Cells[3]->Value = "Suspended";
	SuspendThread(handles[Convert::ToInt32(numericUpDown1->Value) - 1]);
}

System::Void Lab7OS::MyForm::Run_Click(System::Object^ sender, System::EventArgs^ e)
{
	Grid1->Rows[Convert::ToInt32(numericUpDown1->Value) - 1]->Cells[3]->Value = "Running";

	ResumeThread(handles[Convert::ToInt32(numericUpDown1->Value) - 1]);

	Grid1->Rows[Convert::ToInt32(numericUpDown1->Value) - 1]->Cells[3]->Value = "Finnished";
}
