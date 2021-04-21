#include <iostream>
#include "Choice.h"
#include "Node.h"
#include "nodeLoader.h"
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");

	// Загружаем самую первую точку сценария
	Node* node = LoadNode(1);

	// Пока указатель, не указывает на ноль
	while (node)
	{
		// В ходе игры, игрок выберет следующию точку, мы получим её
		Node* newNode = node->Play();

		// Удалим старую
		delete node;

		// И заставим указатель показывать на неё
		node = newNode;
	}

	system("pause");
	return 0;
}