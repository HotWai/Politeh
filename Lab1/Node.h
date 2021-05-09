#pragma once
#include <vector>
#include <string>
#include "Choice.h"
using namespace std;

class Choice;

// Точка в сценарии, в ней содержатся возможные выборы
class Node
{
private:
	
	string message; // Сообщение, которое будет выведено при переходе в эту точку сценария
	vector<Choice> choices;  // Возможные выборы

	void Print(); // Напечатать возможные сообщение и выборы

public:
	Node(string mes, vector<Choice> ch);

	Node* Play(); // Напечатать сообщение и предложить пользователю выбор
};

