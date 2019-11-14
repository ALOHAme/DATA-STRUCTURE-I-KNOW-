#include<iostream>
#include <fstream>
#include<string>
#include<stack>
using namespace std;

void reverse(string& infix, int l) {//利用stack的FILO特性将string倒置
	stack<char> reverse_stack;
	for (int i = 0; i < l; ++i)
		reverse_stack.push(infix[i]);

	for (int i = 0; i < l; ++i) {
		infix[i] = reverse_stack.top();
		reverse_stack.pop();
	}
}

int getPriority(char C)
{
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	return 0;
}

string infixToPostfix(string infix)
{
	infix = '('+infix + ')';
	int l = infix.size();
	stack<char> char_stack;
	string output;

	for (int i = 0; i < l; i++) {

		if (isalpha(infix[i]))
			output += infix[i];

		else if (infix[i] == '(')
			char_stack.push('(');

		else if (infix[i] == ')') {

			while (char_stack.top() != '(') {
				output += char_stack.top();
				char_stack.pop();
			}
			char_stack.pop();
		}
		else {
			while (getPriority(infix[i])
				<= getPriority(char_stack.top())) {
				output += char_stack.top();
				char_stack.pop();
			}
			char_stack.push(infix[i]);
		}
	}

	return output;
}

string infixToPrefix(string infix)
{
	int l = infix.size();

	reverse(infix, l);
	// Replace '(' with ')' and vice versa 
	for (int i = 0; i < l; i++) {

		if (infix[i] == '(') {
			infix[i] = ')';
			i++;
		}
		else if (infix[i] == ')') {
			infix[i] = '(';
			i++;
		}
	}

	string prefix = infixToPostfix(infix);
	int s = prefix.size();

	reverse(prefix, s);
	return prefix;
}

int main()
{
	string exp1; // "A+B*(C-D)-E/F";
	string exp2; // "(A+B)*D+E/(F+A*D)+C";
	ifstream inOld1("old1.dat");
	ifstream inOld2("old2.dat");

	if (!inOld1)
	{
		cerr << "Unable to open old1.dat\n";
		exit(1);
	} // end if

	if (!inOld2)
	{
		cerr << "Unable to open old2.dat\n";
		exit(1);
	} // end if
	while (!inOld1.eof())
	{
		inOld1 >> exp1;
	}
	while (!inOld2.eof())
	{
		inOld2 >> exp2;
	}
	cout << "表达式1中缀表示法： \n";
	cout << exp1<<endl;
	cout << "表达式1前缀表示法： \n";
	cout << infixToPrefix(exp1) << endl;
	cout << "表达式1后缀表示法： \n";
	cout << infixToPostfix(exp1)<<endl<<endl;
	cout << "表达式2中缀表示法： \n";
	cout << exp2 << endl;
	cout << "表达式2前缀表示法： \n";
	cout << infixToPrefix(exp2) << endl;
	cout << "表达式2后缀表示法： \n";
	cout << infixToPostfix(exp2)<<endl;
	system("pause");
	return 0;
}
//知识点：
//通过ifstream读取文件
//string的基本运算
//中缀转后缀、前缀
