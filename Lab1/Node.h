#pragma once
#include <vector>
#include <string>
#include "Choice.h"
using namespace std;

class Choice;

// ����� � ��������, � ��� ���������� ��������� ������
class Node
{
private:
	
	string message; // ���������, ������� ����� �������� ��� �������� � ��� ����� ��������
	vector<Choice> choices;  // ��������� ������

	void Print(); // ���������� ��������� ��������� � ������

public:
	Node(string mes, vector<Choice> ch);

	Node* Play(); // ���������� ��������� � ���������� ������������ �����
};

