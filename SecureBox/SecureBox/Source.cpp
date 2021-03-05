#include "Header.hpp"

int main()
{
	cout << "\t\t\t\t\t\t\tHello";
	Sleep(2000);
	int rows;
	int cols;
	do
	{
		system("cls");
		cout << "How many rows do you want?\n";
		cin >> rows;
		if (rows <= 0 || rows > 100)
			cout << "Wrong rows input! Try again";
		else
		{
			cout << "How many cols do you want?\n";
			cin >> cols;
			if (cols <= 0 || rows > 100)
			{
				cout << "Wrong cols input! Try again";
				Sleep(1000);
				continue;
			}
			break;
		}
		Sleep(1000);
	} while (true);
	SecureBox secureBox(rows, cols);
	cout << "Your matrix: \n";
	for (size_t i = 0; i < secureBox.getSize().first; i++)
	{
		for (size_t j = 0; j < secureBox.getSize().second; j++)
		{
			cout << secureBox.getState()[i][j] << " ";
		}
		cout << endl;
	}
	if (!OpenBox(secureBox))
		cout << "Box completely opened!\n";
	else
		cout << "Something went wrong. Try with this parametres again\n";
	return 0;
}