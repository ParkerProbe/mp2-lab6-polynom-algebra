#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"

using namespace std;

class TPostfix
{
	string infix;
	string postfix;
	TStack <char> sc;//���� ��������
	TStack <double> sd;//���� ���������
	double* p;//��� �������� �������� ����������
public:
	TPostfix()
	{
		p = new double[10];
	}
	~TPostfix()
	{
		delete[] p;
	}
	int prior(char a);
	void SetInfix(string t);
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	string ToPostfix();
	double Calculate(); // ���� ����������, ���������� �� ����������� �����
};

#endif
