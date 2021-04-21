#include <iostream>
using namespace std;

// ���� descending = true, �� ��� ���������� �� ��������
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

// ���������� ������
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
	cout << "������� ���������� �����: ";
	int n;
	cin >> n;

	double* mass = new double[n];

	cout << "������� �����:\n";

	for (int i = 0; i < n; i++)
	{
		cin >> mass[i];
	}

	sort(mass, n, false);

	cout << endl << endl;
	cout << "�� �����������:\n";
	print(mass, n);

	sort(mass, n, true);

	cout << endl << endl;
	cout << "�� ��������:\n";

	print(mass, n);

	system("pause");
	return 0;
}