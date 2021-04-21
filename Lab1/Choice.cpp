#include <iostream>
#include "Choice.h"
#include "nodeLoader.h"

Choice::Choice(string mes, int id)
{
	message = mes;
	nodeId = id;
}

void Choice::Print()
{
	cout << message << endl;
}

Node* Choice::Choose()
{ 
	// ������������� -1, �������� ����� ����, ������� ���������� ����
	if (nodeId == -1)
	{
		return NULL;
	}

	// ��������� �� ���� ����� ��������, � ������ ���������������
	return LoadNode(nodeId);
}
