#include "sq_stack.h"
#include <iostream>
#include <cstring>
using namespace std;

char str[1000];

// �ж��ַ����Ƿ�Ϊ����
bool isPalindrome(const char* str) {
	int len = strlen(str);
	SqStack<char> stack(int(len / 2));

	int i = 0;
	// ǰ�벿����ջ
	for (; i < len / 2; i++)
		stack.Push(str[i]);

	i = int((len + 1) / 2);

	// ��벿����ջ���Ƚ�
	char topChar;
	for (; i < len; i++)
		if (!stack.Pop(topChar) || topChar != str[i])
			return false;
	return true;
}

int main(){
	cout << "������Ҫ�жϵ��ַ�����";
	cin >> str;

	if (isPalindrome(str))
		cout << "�ǻ����ַ���" << endl;
	else
		cout << "���ǻ����ַ���" << endl;

	return 0;
}
