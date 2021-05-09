#include <iostream>
#include <string>
#include <map>
#include <Windows.h>
using namespace std;

// Ассоциативный массив, который содержит буквы и их количество
map<char, int> symbolsMap = map<char, int>();

// Добавляет в массив новую букву с указанным количеством 1, или увеличивает количество этих букв на 1 если буква уже содержится
void Add(char c)
{
	// Если буква большая делаем её маленькой
	if (c >= 'A' && c <= 'Z')
	{
		c += ('a' - 'A');
	}


	if (c >= 'А' && c <= 'Я')
	{
		c += ('а' - 'А');
	}

	// Пытаемся найти данную букву в массиве
	map<char, int>::iterator it = symbolsMap.find(c);

	// Если она уже содержится, увеличиваем её количество на 1
	if (it != symbolsMap.end())
	{
		it->second++;
	}
	else
	{
		// Если её ещё нет в массиве, то добавляем
		symbolsMap.insert(make_pair(c, 1));
	}
}

// Печатеем все буквы и их количество
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
	cout << "Введите строку: ";
	getline(cin, line);

	for (int i = 0; i < line.size(); i++)
	{
		char s = line[i];

		// Если символ является английской буквой или является русской буквой(метода isalpha для кириллицы нету)
		if (isalpha(s) || (s >= 'А' && s <= 'Я') || (s >= 'а' && s <= 'я'))
		{
			Add(s); // Добавляем букву
		}

	}

	Print();

	system("pause");
	return 0;
}