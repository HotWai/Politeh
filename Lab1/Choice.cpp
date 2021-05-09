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
	// Èäåíòèôèêàòîð -1, îçíà÷àåò êîíåö èãðû, ïîýòîìó âîçâðàùàåì íîëü
	if (nodeId == -1)
	{
		return NULL;
	}

	// Çàãðóæàåì èç ôàéë òî÷êó ñöåíàðèÿ, ñ äàííûì èäåíòèôèêàòîðî
	return LoadNode(nodeId);
}
