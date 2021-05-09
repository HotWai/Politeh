#include <iostream>
#include <string>
using namespace std;


// Показывает, что должно быть в ячейке массива: буква, цифра или символ
enum Type
{
	Letter,
	Number,
	Symbol,
	NotYetDetermined
};


const int minLettersCount = 3; // Минимальное кол-во букв
const int minNumbersCount = 2; // Минимальное кол-во цифр
const int minSymbolsCount = 1; // Минимальное кол-во симфолов

 
const int minLength = minLettersCount + minNumbersCount + minSymbolsCount; // Минимальная длина пароля

 // Эти переменные нужны, чтобы указать с какой вероятность у нас в ячейке будет буква, цифра или символ
const int lettersWeight = 4;
const int numbersWeight = 2;
const int symbolsWeight = 1;


// Заполнить минимальным количеством букв, цифр или символов(смотря какой fillType будет указан)
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

// Получить случайный тип
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

// Получить букву
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
// Получить цифру
char GetRandomNumber()
{
	char number = '0' + rand() % 10;
	return number;
}
// Получить символ
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
		cout << "Укажите длину пароля: ";
		cin >> length;

		if (length >= minLength)
		{
			break;
		}
		else
		{
			cout << "Некорректный ввод!" << endl;
		}
	}
	// Создаём массив, длина которого, такая же как и у пароля
	Type* passwordTypes = new Type[length];

	// Указываем в каждой ячейке неопределённый тип
	for (int i = 0; i < length; i++)
	{
		passwordTypes[i] = NotYetDetermined;
	}
	// Помещаем в неопределённые ячейки минимальное кол-во букв
	FillMin(passwordTypes, length, minLettersCount, Letter);
	// Помещаем в неопределённые ячейки минимальное кол-во цифр
	FillMin(passwordTypes, length, minNumbersCount, Number);
	// Помещаем в неопределённые ячейки минимальное кол-во символов
	FillMin(passwordTypes, length, minSymbolsCount, Symbol);


	// Оставшимя неопределённым ячейчкам присваиваем случайный тип
	for (int i = 0; i < length; i++)
	{
		if (passwordTypes[i] == NotYetDetermined)
		{
			passwordTypes[i] = GetRandomType();
		}
	}

	// Создаём пароль
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