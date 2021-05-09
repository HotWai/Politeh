#pragma once
#include <string>
#include "Node.h"
using namespace std;

class Node;

// Возможный выбор
class Choice
{
private:
	string message;  // Сообщение, которое будет напечатано, когда пользователю будет предложен выбор

	int nodeId;  // Идентификатор точки сценария, в которую мы перейдём, если выберем этот экземпляр

public:
	Choice(string mes, int id);
	void Print();  // Напечатать сообщение

	Node* Choose();  // Получить точку сценария, к которой мы перйдём, сделав этот выбор
};

