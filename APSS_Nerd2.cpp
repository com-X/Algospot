// APSS_Nerd2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;

map<int, int> nerds;
int N;
int p, q;

bool canInsert(int p, int q) {
	auto itr = nerds.upper_bound(p);
	if (itr == nerds.end()) return true;
	return itr->second < q;
}

void eraseNoNerd(int p, int q) {
	auto itr_start = nerds.lower_bound(p);
	auto itr_last = itr_start;
	if (itr_last == nerds.begin()) return;

	for (--itr_last; itr_last != nerds.begin(); --itr_last)
		if (itr_last->second > q) break;


	if (itr_last->second > q)itr_last++;

	nerds.erase(itr_last, itr_start);
}

int main()
{
	int testcase;
	int N;
	cin >> testcase;

	while (testcase--) {
		cin >> N;
		int result=0;
		//1. ���� �� �ִ� �� Ȯ���ϰ�
		//2. �ְ� �������� �͵� ó��
		for (int i = 0; i < N; i++) {
			cin >> p >> q;
			if (canInsert(p, q)) {
				eraseNoNerd(p, q);
				nerds.insert(make_pair(p, q));
			}
			result += nerds.size();
		}
		cout << result << endl;
		nerds.clear();
	}

    return 0;
}

