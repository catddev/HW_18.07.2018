#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{
			// **Написать программу, которая заполняет массив случайными числами и меняет
			// порядок элементов в каждом столбце на обратный(массив до и после показать на экран).
			// Например:
			// 11 10 9 8   = >  3 7 0 11
			// 6 4 12 5         6 4 12 5
			// 3 7 0 11        11 10 9 8

			int a[100][100];
			int n = 3, m = 4;
			int i, j;

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					a[i][j] = rand() % 10;
					cout << right << setw(3) << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;
			for (i = 0; i <= n/2; i++)
			{
				for (j = 0; j < m; j++)
				{
					swap(a[i][j], a[n - i - 1][j]);
				}
			}

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
					cout << right << setw(3) << a[i][j] << " ";
				cout << endl;
			}
			cout << endl << endl;
		}
		break;
		case 2:
		{
			// *Написать программу, которая заполняет массив 5х5 оценками по 12 бальной
			// системе, преобразовать их в оценки по 5 бальной системе.Двойкой считается
			// оценка ниже 4, тройкой – от 4 до 6 и т.д.

			const int n = 5;
			int a[n][n];
			int i, j;

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					a[i][j] = 1 + rand() % 12;
					cout << right << setw(3) << a[i][j] << " ";
				}
				cout << "   =>   ";
				for (j = 0; j < n; j++)
				{
					if (a[i][j] > 0 && a[i][j] < 4) a[i][j] = 2;
					else if (a[i][j] > 3 && a[i][j] < 7) a[i][j] = 3;
					else if (a[i][j] > 6 && a[i][j] < 10) a[i][j] = 4;
					else if (a[i][j] > 9 && a[i][j] <= 12) a[i][j] = 5;
					cout << right << setw(3) << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;
		}
		break;
		case 3:
		{
			// **Заполнить двухмерный массив 8х8 значениями 0 и 1 случайным образом,
			// но так, чтобы нулей было в два раза больше, чем единичек.

			const int n = 8;
			int a[n][n];
			int i, j;
			int zero = 0, one = 0;

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					a[i][j] = rand() % 2;
					if (a[i][j] == 0) zero++;
					else one++;

					if (one > n*n/3)
						if (a[i][j] == 1) a[i][j] = 0;
						else if (zero > n*n/3*2)
							if (a[i][j] == 0) a[i][j] = 1;

					cout << right << setw(3) << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}