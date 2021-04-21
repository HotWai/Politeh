#include <iostream>
using namespace std;

// Если descending = true, то идёт сортировка по убыванию
void sort(double* mass, int length, bool descending)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (descending ^ mass[j] > mass[j + 1])
			{
				double d = mass[j];

				mass[j] = mass[j + 1];

				mass[j + 1] = d;
			}
		}
	}
}

// Отображает массив
void print(double* mass, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << mass[i] << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Укажите количество чисел: ";
	int n;
	cin >> n;

	double* mass = new double[n];

	cout << "Введите числа:\n";

	for (int i = 0; i < n; i++)
	{
		cin >> mass[i];
	}

	sort(mass, n, false);

	cout << endl << endl;
	cout << "По возрастанию:\n";
	print(mass, n);

	sort(mass, n, true);

	cout << endl << endl;
	cout << "По убыванию:\n";

	print(mass, n);

	system("pause");
	return 0;
}