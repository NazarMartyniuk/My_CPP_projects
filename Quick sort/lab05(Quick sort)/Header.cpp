#include "Header.h"

void Menu()
{
	srand(time(nullptr));
	size_t size;
	do
	{
		cout << "Enter count of students: ";
		cin >> size;
		if (size <= 1)
		{
			cout << "\nIncorrect data input\n";
			system("cls");
		}
	} while (size <= 1);
	pair<string, size_t>* studentList = new pair<string, size_t>[size];
	string name;
	size_t averageMark;
	for (size_t i = 0; i < size; i++)
	{
		cin.ignore();
		cout << "Enter name of student: ";
		getline(cin, name);
		studentList[i].first = name;
		cout << "Enter average mark: ";
		cin >> averageMark;
		studentList[i].second = averageMark;
	}
	cout << "Your list:\n";
	for (size_t i = 0; i < size; i++)
	{
		cout << "Name: " << studentList[i].first << "\tMark: " << studentList[i].second << "\n";
	}
	size_t newSize = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (studentList[i].second >= 4)
			newSize++;
	}
	pair<string, size_t>* tmp = new pair<string, size_t>[newSize];
	size_t checker = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (studentList[i].second < 4)
		{
			checker++;
			continue;
		}
		tmp[i - checker].first = studentList[i].first;
		tmp[i - checker].second = studentList[i].second;
	}
	delete[]studentList;
	studentList = tmp;
	for (size_t i = 0; i < size; i++)
	{
		cout << "Name: " << studentList[i].first << "\tMark: " << studentList[i].second << "\n";
	}
	QuickSort(studentList, 0, size - 1);
	cout << "\n\n\n\n";
	for (size_t i = 0; i < size; i++)
	{
		cout << "Name: " << studentList[i].first << "\tMark: " << studentList[i].second << "\n";
	}
}

void QuickSort(pair<string, size_t>* students, size_t left, size_t right)
{
	{
		size_t baseElement = (right + left) / 2;
		size_t i = 0;
		size_t j = right;
		if (left < right)
		{
			if (right - left != 1)
			{
				while (i < baseElement && j >= baseElement)
				{
					if (students[i].second >= students[baseElement].second)
					{
						if (students[j].second < students[baseElement].second)
						{
							string tmpName = students[i].first;
							size_t tmpAverageMark = students[i].second;
							students[i].first = students[j].first;
							students[i].second = students[j].second;
							students[j].first = tmpName;
							students[j].second = tmpAverageMark;
						}
						else
						{
							j--;
							continue;
						}
					}
					else
					{
						i++;
						continue;
					}
				}
				QuickSort(students, left, baseElement);
				QuickSort(students, baseElement, right);
			}
			else
			{
				if (students[left].second > students[right].second)
				{
					string tmpName = students[left].first;
					size_t tmpAverageMark = students[left].second;
					students[left].first = students[right].first;
					students[left].second = students[right].second;
					students[right].first = tmpName;
					students[right].second = tmpAverageMark;
				}
			}
		}
	}
}