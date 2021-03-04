#include "MyForm.h"
#include <Windows.h>
#include <string>
#include <chrono>
#include <msclr/marshal_cppstd.h>
using namespace ProcessCreator;
using namespace System;
using namespace System::Windows::Forms;
using namespace msclr::interop;

int ProcessCount = 0;
PROCESS_INFORMATION pi[8];

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

LPWSTR CharToLPWSTR(LPCSTR char_string)
{
	LPWSTR res;
	DWORD res_len = MultiByteToWideChar(1251, 0, char_string, -1, NULL, 0);
	res = (LPWSTR)GlobalAlloc(GPTR, (res_len + 1) * sizeof(WCHAR));
	MultiByteToWideChar(1251, 0, char_string, -1, res, res_len);
	return res;
}

String^ priority(DWORD code)
{
	switch (code)
	{
	case 32768: return "Above normal";
	case 16384: return "Below normal";
	case 32: return "Normal";
	case 64: return "Idle";
	case 128: return "Hight";
	default: return "";
	}
}

System::Void ProcessCreator::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	Grid1->RowCount = 8;
}

System::Void ProcessCreator::MyForm::Create_Processes_Click(System::Object^ sender, System::EventArgs^ e)
{
	ProcessCount = Convert::ToInt32(comboBox1->Text);
	size_t size = Convert::ToUInt16(textBox1->Text);
	string wLine = "D:\\Лабораторні роботи\\2 курс\\1 семестр\\Операційні системи\\lab 03\\Debug\\lab 03.exe " + marshal_as<string>(textBox1->Text);
	for (int i = 0; i < ProcessCount; ++i)
	{
		STARTUPINFO si;
		PROCESS_INFORMATION p;
		ZeroMemory(&si, sizeof(STARTUPINFO));
		ZeroMemory(&p, sizeof(PROCESS_INFORMATION));
		CreateProcess(NULL,
			CharToLPWSTR(wLine.c_str()),
			NULL,
			NULL,
			FALSE,
			CREATE_SUSPENDED | CREATE_NEW_CONSOLE,
			NULL,
			NULL,
			&si,
			&p);

		pi[i] = p;

		Grid1->Rows[i]->Cells[0]->Value = i + 1;
		Grid1->Rows[i]->Cells[1]->Value = p.dwProcessId;
		Grid1->Rows[i]->Cells[2]->Value = priority(GetPriorityClass(p.hProcess));
		Grid1->Rows[i]->Cells[3]->Value = "Suspended";
	}
}

System::Void ProcessCreator::MyForm::Run_all_Click(System::Object^ sender, System::EventArgs^ e)
{
	int handleCounter = 0;
	HANDLE threadHandles[8];
	for (int i = 0; i < ProcessCount; ++i)
	{
		if (Grid1->Rows[i]->Cells[3]->Value == "Terminated")
		{
			continue;
		}

		threadHandles[++handleCounter] = pi[i].hThread;
	}
	for (int i = 0; i < ProcessCount; ++i)
	{
		if (Grid1->Rows[i]->Cells[3]->Value == "Terminated")
		{
			continue;
		}
		Grid1->Rows[i]->Cells[3]->Value = "Running";
		ResumeThread(pi[i].hThread);
	}
	WaitForMultipleObjects(handleCounter, threadHandles, TRUE, INFINITE);

	FILETIME createTime;
	FILETIME exitTime;
	FILETIME kernelTime;
	FILETIME userTime;
	double res = 0.0;


	for (int i = 0; i < ProcessCount; ++i) {
		if (Grid1->Rows[i]->Cells[3]->Value == "Terminated") {
			continue;
		}

		if (GetProcessTimes(pi[i].hProcess,
			&createTime, &exitTime, &kernelTime, &userTime) != -1)
		{
			SYSTEMTIME userSystemTime;
			if (FileTimeToSystemTime(&userTime, &userSystemTime) != -1)

				res = (double)userSystemTime.wHour * 3600.0 +
				(double)userSystemTime.wMinute * 60.0 +
				(double)userSystemTime.wSecond +
				(double)userSystemTime.wMilliseconds / 1000.0;
		}
		Grid1->Rows[i]->Cells[3]->Value = "Finnished";
	}
	Time_Field->Text = Convert::ToString(res);
}

System::Void ProcessCreator::MyForm::comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{

	switch (comboBox3->SelectedIndex)
	{
	case 0:
	{
		SetPriorityClass(pi[Convert::ToInt32(Process_index->SelectedIndex)].hProcess,
			IDLE_PRIORITY_CLASS);

		Grid1->Rows[Convert::ToInt32(Process_index->SelectedIndex)]->Cells[2]->Value = "Idle";
		break;
	}

	case 1:
	{
		SetPriorityClass(pi[Convert::ToInt32(Process_index->SelectedIndex)].hProcess,
			BELOW_NORMAL_PRIORITY_CLASS);

		Grid1->Rows[Convert::ToInt32(Process_index->SelectedIndex)]->Cells[2]->Value = "Below normal";
		break;
	}

	case 2:
	{
		SetPriorityClass(pi[Convert::ToInt32(Process_index->SelectedIndex)].hProcess,
			NORMAL_PRIORITY_CLASS);

		Grid1->Rows[Convert::ToInt32(Process_index->SelectedIndex)]->Cells[2]->Value = "Normal";
		break;
	}
	case 3:
	{
		SetPriorityClass(pi[Convert::ToInt32(Process_index->SelectedIndex)].hProcess,
			ABOVE_NORMAL_PRIORITY_CLASS);

		Grid1->Rows[Convert::ToInt32(Process_index->SelectedIndex)]->Cells[2]->Value = "Abovenormal";
		break;
	}
	case 4:
	{
		SetPriorityClass(pi[Convert::ToInt32(Process_index->SelectedIndex)].hProcess,
			HIGH_PRIORITY_CLASS);

		Grid1->Rows[Convert::ToInt32(Process_index->SelectedIndex)]->Cells[2]->Value = "High";
		break;
	}
	case 5:
	{
		SetPriorityClass(pi[Convert::ToInt32(Process_index->SelectedIndex)].hProcess,
			REALTIME_PRIORITY_CLASS);

		Grid1->Rows[Convert::ToInt32(Process_index->SelectedIndex)]->Cells[2]->Value = "Real time";
		break;
	}
	}
}

System::Void ProcessCreator::MyForm::MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	for (int i = 0; i < Convert::ToInt32(comboBox1->Text); ++i)
	{
		CloseHandle(pi[i].hThread);
		CloseHandle(pi[i].hProcess);
	}

}



System::Void ProcessCreator::MyForm::Pause_Click(System::Object^ sender, System::EventArgs^ e)
{
	Grid1->Rows[Convert::ToInt32(Process_index->SelectedIndex)]->Cells[3]->Value = "Suspended";
	SuspendThread(pi[Process_index->SelectedIndex].hThread);
}

System::Void ProcessCreator::MyForm::Kill_Click(System::Object^ sender, System::EventArgs^ e)
{
	TerminateProcess(pi[Process_index->SelectedIndex].hProcess, 0);
	Grid1->Rows[Process_index->SelectedIndex]->Cells[3]->Value = ("Terminated");

	Run->Enabled = 0;
	Pause->Enabled = 0;
	Kill->Enabled = 0;

	comboBox3->Enabled = 0;
}

System::Void ProcessCreator::MyForm::Run_Click(System::Object^ sender, System::EventArgs^ e)
{
	Grid1->Rows[Process_index->SelectedIndex]->Cells[3]->Value = "Running";

	ResumeThread(pi[Process_index->SelectedIndex].hThread);
	//WaitForSingleObject(pi[Process_index->SelectedIndex].hProcess, INFINITE);

	Grid1->Rows[Process_index->SelectedIndex]->Cells[3]->Value = "Finnished";

	Grid1->Rows[Process_index->SelectedIndex]->Cells[2]->Value = (priority(GetPriorityClass(pi[Process_index->SelectedIndex].hProcess)));
}

System::Void ProcessCreator::MyForm::Process_index_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (Grid1->Rows[Process_index->SelectedIndex]->Cells[3]->Value == "Terminated") {
		Run->Enabled = 0;
		Pause->Enabled = 0;
		Kill->Enabled = 0;

		comboBox3->Enabled = 0;
	}
	else
	{
		Run->Enabled = 1;
		Pause->Enabled = 1;
		Kill->Enabled = 1;

		comboBox3->Enabled = 1;
	}

	switch ((GetPriorityClass(pi[Process_index->SelectedIndex].hProcess)))
	{

	case 32768: comboBox3->SelectedIndex = 3; break;
	case 16384: comboBox3->SelectedIndex = 1; break;
	case 32: comboBox3->SelectedIndex = 2; break;
	case 64: comboBox3->SelectedIndex = 0; break;
	case 128: comboBox3->SelectedIndex = 4; break;
	}
}