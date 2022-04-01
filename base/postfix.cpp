#include "postfix.h"
#include "stack.h"
#include <iostream>

int TPostfix::prior(char a)
{
	switch (a)
	{
	case 'd':return 3;
	case 'I':return 3;
	case '*':return 3;
	case '/':return 3;
	case '+':return 2;
	case '-':return 2;
	case '(':return 1;
	case ')':return 1;
	case ' ':return -1;
	default:return 0;
	}
}

string TPostfix::to_postfix()
{
	sc.set_size(infix.size());
	sd.set_size(infix.size());
	char tmp;
	for (int i = 0; i < infix.size(); i++)\
	{
		tmp = infix[i];
		if (prior(tmp) == 0)
			postfix += tmp;
		else
		{
			if ((prior(tmp) == 2) || (prior(tmp) == 3))
			{
				if (postfix != "")
					postfix += "|";
				if (sc.is_empty() == true)
					sc.add(tmp);
				else
				{
					if (prior(tmp) > prior(sc.info_top()))
					{
						sc.add(tmp);
					}
					else
					{
						while (prior(tmp) <= prior(sc.info_top()))
						{
							postfix += sc.get_top();
							postfix += "|";
							if (sc.is_empty() == true)
								break;
						}
						sc.add(tmp);
					}
				}
			}
			else
				if (tmp == '(')
					sc.add(tmp);
				else
					if (tmp == ')')
					{
						postfix += "|";
						while (sc.info_top() != '(')
						{
							postfix += sc.get_top();
							postfix += "|";

						}
						sc.get_top();
					}
		}
	}
	while (sc.is_empty() != true)
	{
		postfix += sc.get_top();
		postfix += "|";
	}
	postfix += "_";
	return postfix;
}
double TPostfix::calculate()
{
	Polynom a, b;
	for (int i = 0; postfix[i] != '_'; i++)
	{
		switch (postfix[i])
		{
		case'+':a = sd.get_top(); b = sd.get_top();
			sd.add(a + b);
			break;
		case'-': a = sd.get_top();
			if (sd.is_empty() == true)
				sd.add( -a);
			else
			{
				b = sd.get_top();
				sd.add(b - a);
			}
			break;
		case'*': a = sd.get_top(); b = sd.get_top();
			sd.add(a * b);
			break;
		case'/':a = sd.get_top(); b = sd.get_top();
			sd.add(b / a);
			break;
		default:
			a = p[postfix[i] - 65];
			sd.add(a);
			break;
		}
	}
	a = sd.get_top();
	if (sd.is_empty() != true)
	{
		throw 0;
	}
	return a;
}


