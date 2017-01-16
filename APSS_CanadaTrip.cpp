// APSS_CanadaTrip.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define min(a,b) ((a<b)?a:b)

int n, k;
int l[5000], m[5000], g[5000];//���ñ��� �Ÿ�, ǥ���� ��ġ, ����



//dist�������� ���鼭 k�� �̻��� ǥ������ ���� �� �ִ°�?
bool decision(int dist) {
	int ret = 0;
	for (int i = 0; i < n; ++i) { //��ġ�� ������ �������� �� ���� �� ǥ���� ����
		if (dist >= l[i] - m[i])
			ret += (min(dist, l[i]) - (l[i] - m[i])) / g[i] + 1;
	}
	return ret >= k;
}

//k��° ǥ������ ������ ������ ��ġ ���
int optimize() {
	int lo = -1, hi = 8030001;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int main()
{
	int testcase;

	cin >> testcase;

	while (testcase--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> l[i] >> m[i] >> g[i];
		cout << optimize() << endl;
	}

    return 0;
}

