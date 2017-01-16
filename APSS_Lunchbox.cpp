// APSS_Lunchbox.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


#define max(a, b) ((a>=b)?a:b)

int num, e[10000], m[10000];

int heat() {
	//어느 순서대로 데워야 할지를 결정
	vector<pair<int, int>> order;
	for (int i = 0; i < num; i++)
		order.push_back(make_pair(e[i], i));
	sort(order.begin(), order.end());
	reverse(order.begin(), order.end());
	//해당 순서대로 데워먹는 과정을 시뮬레이션
	int ret = 0, beginEat = 0;
	for (int i = 0; i < num; i++) {
		int box = order[i].second;
		beginEat += m[box];
		ret = max(ret, beginEat + e[box]);
	}
	return ret;
}


int main()
{
	int testcase;

	scanf("%d", &testcase);

	for (int t = 0; t < testcase; t++) {
		scanf("%d", &num);
		for (int i = 0; i < num; i++)
			scanf("%d", &m[i]);
		for (int i = 0; i < num; i++)
			scanf("%d", &e[i]);

		cout << heat() << endl;
	}

	return 0;
}