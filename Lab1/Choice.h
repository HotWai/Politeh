#pragma once
#include <string>
#include "Node.h"
using namespace std;

class Node;

// ��������� �����
class Choice
{
private:
	string message;  // ���������, ������� ����� ����������, ����� ������������ ����� ��������� �����

	int nodeId;  // ������������� ����� ��������, � ������� �� �������, ���� ������� ���� ���������

public:
	Choice(string mes, int id);
	void Print();  // ���������� ���������

	Node* Choose();  // �������� ����� ��������, � ������� �� ������, ������ ���� �����
};

