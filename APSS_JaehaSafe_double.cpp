// APSS_JaehaSafe_double.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int testcase;
	cin >> testcase;
	int N;
	while (testcase--) {
		cin >> N;
		string now,next;
		int count = 0;
		cin >> now;
		for (int i = 0; i < N; i++) {
			cin >> next;
			int pos;
			if (i % 2 == 0) count += (next + next).find(now);
			else count += (now + now).find(next);
			now = next;
		}
		cout << count << endl;
	}
    return 0;
}

