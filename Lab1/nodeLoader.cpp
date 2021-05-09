#include <fstream>
#include <vector>
#include "Node.h"
#include "Choice.h"
#include "nodeLoader.h"
using namespace std;

// В этой структуре содержатся данные, нужные для получения нового экземпляра класса Node
// Эта структура используется для чтения из файл
struct NodeData
{
	int nodeId;

	int strsCount;
	string message;

	int choiceCount;
	vector<Choice> choices;
};

// Получить из файлового потока новый объект экземпляр NodeData
NodeData NewNodeData(ifstream* fin)
{
	NodeData nodeData;

	// Получаем id
	(*fin) >> nodeData.nodeId;
	// Получаем количество строк сообщения
	(*fin) >> nodeData.strsCount;
	nodeData.message = "";
	char st[100];

	(*fin).get();

	// Получаем все строки, содержащие сообщение
	for (int i = 0; i < nodeData.strsCount; i++)
	{
		(*fin).getline(st, 99);
		nodeData.message += st;
		nodeData.message += '\n';
	}

	// Получаем количество выборов
	(*fin) >> nodeData.choiceCount;
	nodeData.choices = vector<Choice>();

	// Получаем каждый выбор
	for (int i = 0; i < nodeData.choiceCount; i++)
	{
		int choiceId;
		(*fin) >> choiceId;

		fin->get();
		fin->getline(st, 99);

		string choiceMessage = st;
		nodeData.choices.push_back(Choice(choiceMessage, choiceId));
	}

	return nodeData;
}

const char path[] = "input.txt";// Путь к файлу, в котором содержится сценарий

Node* LoadNode(int id)
{
	// Открываем файл
	ifstream* fin = new ifstream(path);

	Node* node = NULL;


	while (!fin->eof())
	{
		// Получаем возможную точку в сценария из файл
		NodeData d = NewNodeData(fin);

		// Если её идентификатор соответствует запрашиваемуму, то создаём новыую точку в сценарии
		if (d.nodeId == id)
		{
			node = new Node(d.message, d.choices);
			break;
		}
	}

	fin->close();

	delete fin;

	return node;
}