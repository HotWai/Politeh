#include <iostream>
#include "Choice.h"
#include "Node.h"
#include "nodeLoader.h"
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");

	// ��������� ����� ������ ����� ��������
	Node* node = LoadNode(1);

	// ���� ���������, �� ��������� �� ����
	while (node)
	{
		// � ���� ����, ����� ������� ��������� �����, �� ������� �
		Node* newNode = node->Play();

		// ������ ������
		delete node;

		// � �������� ��������� ���������� �� ��
		node = newNode;
	}

	system("pause");
	return 0;
}