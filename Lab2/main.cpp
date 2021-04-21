#include <iostream>
#include <string>
using namespace std;


// ����������, ��� ������ ���� � ������ �������: �����, ����� ��� ������
enum Type
{
	Letter,
	Number,
	Symbol,
	NotYetDetermined
};


const int minLettersCount = 3; // ����������� ���-�� ����
const int minNumbersCount = 2; // ����������� ���-�� ����
const int minSymbolsCount = 1; // ����������� ���-�� ��������

 
const int minLength = minLettersCount + minNumbersCount + minSymbolsCount; // ����������� ����� ������

 // ��� ���������� �����, ����� ������� � ����� ����������� � ��� � ������ ����� �����, ����� ��� ������
const int lettersWeight = 4;
const int numbersWeight = 2;
const int symbolsWeight = 1;


// ��������� ����������� ����������� ����, ���� ��� ��������(������ ����� fillType ����� ������)
void FillMin(Type* passwordTypes, int length, int min, Type fillType)
{
	for (int i = 0; i < min; i++)
	{
		int index;

		do
		{
			index = rand() % length;
		} while (passwordTypes[index] != NotYetDetermined);

		passwordTypes[index] = fillType;
	}
}

// �������� ��������� ���
Type GetRandomType()
{
	int x = rand() % lettersWeight + numbersWeight + symbolsWeight + 1;

	if (x <= lettersWeight)
	{
		return Letter;
	}
	else if (x <= lettersWeight + numbersWeight)
	{
		return Number;
	}

	return Symbol;
}

// �������� �����
char GetRandomLetter()
{
	char letter;
	bool isBig = rand() % 2;

	if (isBig)
	{
		letter = 'a' + rand() % 26;
	}
	else
	{
		letter = 'A' + rand() % 26;
	}

	return letter;
}
// �������� �����
char GetRandomNumber()
{
	char number = '0' + rand() % 10;
	return number;
}
// �������� ������
char GetRandomSymbol()
{
	char symbols[] = "~!@#$%^&*?";

	return symbols[rand() % 10];
}

int main()
{
	setlocale(LC_CTYPE, "rus");

	srand(time(0));

	int length;

	while (true)
	{
		cout << "������� ����� ������: ";
		cin >> length;

		if (length >= minLength)
		{
			break;
		}
		else
		{
			cout << "������������ ����!" << endl;
		}
	}
	// ������ ������, ����� ��������, ����� �� ��� � � ������
	Type* passwordTypes = new Type[length];

	// ��������� � ������ ������ ������������� ���
	for (int i = 0; i < length; i++)
	{
		passwordTypes[i] = NotYetDetermined;
	}
	// �������� � ������������� ������ ����������� ���-�� ����
	FillMin(passwordTypes, length, minLettersCount, Letter);
	// �������� � ������������� ������ ����������� ���-�� ����
	FillMin(passwordTypes, length, minNumbersCount, Number);
	// �������� � ������������� ������ ����������� ���-�� ��������
	FillMin(passwordTypes, length, minSymbolsCount, Symbol);


	// ��������� ������������� �������� ����������� ��������� ���
	for (int i = 0; i < length; i++)
	{
		if (passwordTypes[i] == NotYetDetermined)
		{
			passwordTypes[i] = GetRandomType();
		}
	}

	// ������ ������
	string password = "";

	for (int i = 0; i < length; i++)
	{
		switch (passwordTypes[i])
		{
		case Letter:
			password += GetRandomLetter();
			break;
		case Number:
			password += GetRandomNumber();
			break;
		case Symbol:
			password += GetRandomSymbol();
			break;
		}
	}

	delete[] passwordTypes;
	cout << password << endl;

	system("pause");
	return 0;
}