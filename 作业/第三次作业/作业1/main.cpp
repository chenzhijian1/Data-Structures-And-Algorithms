#include "sq_stack.h"
#include <iostream>
#include <cstring>
using namespace std;

char str[1000];

// 判断字符串是否为回文
bool isPalindrome(const char* str) {
	int len = strlen(str);
	SqStack<char> stack(int(len / 2));

	int i = 0;
	// 前半部分入栈
	for (; i < len / 2; i++)
		stack.Push(str[i]);

	i = int((len + 1) / 2);

	// 后半部分与栈顶比较
	char topChar;
	for (; i < len; i++)
		if (!stack.Pop(topChar) || topChar != str[i])
			return false;
	return true;
}

int main(){
	cout << "请输入要判断的字符串：";
	cin >> str;

	if (isPalindrome(str))
		cout << "是回文字符串" << endl;
	else
		cout << "不是回文字符串" << endl;

	return 0;
}
