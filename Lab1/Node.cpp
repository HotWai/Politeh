#include "Node.h"
#include <iostream>
using namespace std;

void Node::Print()
{
	system("cls");

	cout << message << endl;

	for (int i = 0; i < choices.size(); i++)
	{
		cout << i + 1 << ' ';
		choices[i].Print();
	}
}

Node::Node(string mes, vector<Choice> ch)
{
	message = mes;
	choices = ch;
}

Node* Node::Play()
{
	// Печатаем сообщение и предлагаем выбор
	Print();

	
	while (true)
	{
		// Ввод
		cout << "Выберите действие: ";
		int n;
		cin >> n;

		// Проверка корректности ввода
		if (n > 0 && n <= choices.size())
		{
			// Возвращаем новую точку сценария, которая содержится в данном выборе
			return choices[--n].Choose();
		}
		else
		{
			cout << "Неверный ввод!\n";
		}
	}
	

}
