#include <fstream>
#include <vector>
#include "Node.h"
#include "Choice.h"
#include "nodeLoader.h"
using namespace std;

// � ���� ��������� ���������� ������, ������ ��� ��������� ������ ���������� ������ Node
// ��� ��������� ������������ ��� ������ �� ����
struct NodeData
{
	int nodeId;

	int strsCount;
	string message;

	int choiceCount;
	vector<Choice> choices;
};

// �������� �� ��������� ������ ����� ������ ��������� NodeData
NodeData NewNodeData(ifstream* fin)
{
	NodeData nodeData;

	// �������� id
	(*fin) >> nodeData.nodeId;
	// �������� ���������� ����� ���������
	(*fin) >> nodeData.strsCount;
	nodeData.message = "";
	char st[100];

	(*fin).get();

	// �������� ��� ������, ���������� ���������
	for (int i = 0; i < nodeData.strsCount; i++)
	{
		(*fin).getline(st, 99);
		nodeData.message += st;
		nodeData.message += '\n';
	}

	// �������� ���������� �������
	(*fin) >> nodeData.choiceCount;
	nodeData.choices = vector<Choice>();

	// �������� ������ �����
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

const char path[] = "input.txt";// ���� � �����, � ������� ���������� ��������

Node* LoadNode(int id)
{
	// ��������� ����
	ifstream* fin = new ifstream(path);

	Node* node = NULL;


	while (!fin->eof())
	{
		// �������� ��������� ����� � �������� �� ����
		NodeData d = NewNodeData(fin);

		// ���� � ������������� ������������� ��������������, �� ������ ������ ����� � ��������
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