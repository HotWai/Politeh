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
	// Идентификатор -1, означает конец игры, поэтому возвращаем ноль
	if (nodeId == -1)
	{
		return NULL;
	}

	// Загружаем из файл точку сценария, с данным идентификатором
	return LoadNode(nodeId);
}
