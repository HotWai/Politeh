#include <iostream>
#include <string>
#include <map>
#include <Windows.h>
using namespace std;

// ������������� ������, ������� �������� ����� � �� ����������
map<char, int> symbolsMap = map<char, int>();

// ��������� � ������ ����� ����� � ��������� ����������� 1, ��� ����������� ���������� ���� ���� �� 1 ���� ����� ��� ����������
void Add(char c)
{
	// ���� ����� ������� ������ � ���������
	if (c >= 'A' && c <= 'Z')
	{
		c += ('a' - 'A');
	}


	if (c >= '�' && c <= '�')
	{
		c += ('�' - '�');
	}

	// �������� ����� ������ ����� � �������
	map<char, int>::iterator it = symbolsMap.find(c);

	// ���� ��� ��� ����������, ����������� � ���������� �� 1
	if (it != symbolsMap.end())
	{
		it->second++;
	}
	else
	{
		// ���� � ��� ��� � �������, �� ���������
		symbolsMap.insert(make_pair(c, 1));
	}
}

// �������� ��� ����� � �� ����������
void Print()
{
	map<char, int>::iterator it = symbolsMap.begin();

	while (it != symbolsMap.end())
	{
		cout << it->first << ": " << it->second << endl;

		it++;
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string line;
	cout << "������� ������: ";
	getline(cin, line);

	for (int i = 0; i < line.size(); i++)
	{
		char s = line[i];

		// ���� ������ �������� ���������� ������ ��� �������� ������� ������(������ isalpha ��� ��������� ����)
		if (isalpha(s) || (s >= '�' && s <= '�') || (s >= '�' && s <= '�'))
		{
			Add(s); // ��������� �����
		}

	}

	Print();

	system("pause");
	return 0;
}