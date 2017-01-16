// APSS_Brackets2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

string Judge(const string& list) {
	stack<char> brackets;
	for (int i = 0; i < list.size(); i++) {
		//���� ��ȣ�� �ٷ� push
		if (list[i] == '(' || list[i] == '[' || list[i] == '{')
			brackets.push(list[i]);
		else {
			//����ִ� ���
			if (brackets.empty()) return "NO";
			//¦�� �´� ���
			if (list[i] - brackets.top() <= 2)
				brackets.pop();
			else
				return "NO";
		}
	}
	//�����ִ� ���
	if (!brackets.empty()) return "NO";
	return "YES";
}

int main()
{
	int testcase;
	cin >> testcase;
	while (testcase--) {
		string list;
		cin >> list;
		cout << Judge(list) << endl;
	}

    return 0;
}

