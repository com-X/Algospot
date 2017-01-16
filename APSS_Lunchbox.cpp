// APSS_Lunchbox.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	//��� ������� ������ ������ ����
	vector<pair<int, int>> order;
	for (int i = 0; i < num; i++)
		order.push_back(make_pair(e[i], i));
	sort(order.begin(), order.end());
	reverse(order.begin(), order.end());
	//�ش� ������� �����Դ� ������ �ùķ��̼�
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