// APSS_Brackets2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

string Judge(const string& list) {
	stack<char> brackets;
	for (int i = 0; i < list.size(); i++) {
		//여는 괄호는 바로 push
		if (list[i] == '(' || list[i] == '[' || list[i] == '{')
			brackets.push(list[i]);
		else {
			//비어있는 경우
			if (brackets.empty()) return "NO";
			//짝이 맞는 경우
			if (list[i] - brackets.top() <= 2)
				brackets.pop();
			else
				return "NO";
		}
	}
	//남아있는 경우
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

