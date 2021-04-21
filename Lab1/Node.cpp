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
	// �������� ��������� � ���������� �����
	Print();

	
	while (true)
	{
		// ����
		cout << "�������� ��������: ";
		int n;
		cin >> n;

		// �������� ������������ �����
		if (n > 0 && n <= choices.size())
		{
			// ���������� ����� ����� ��������, ������� ���������� � ������ ������
			return choices[--n].Choose();
		}
		else
		{
			cout << "�������� ����!\n";
		}
	}
	

}
