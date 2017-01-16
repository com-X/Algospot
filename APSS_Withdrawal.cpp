// APSS_Withdrawal.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n, k;
int c[1000], r[1000];

bool decision(double average) {
	vector<double> v;
	for (int i = 0; i < n; ++i) 
		v.push_back(average*c[i] - r[i]);
	sort(v.begin(), v.end());
	double sum = 0;
	for (int i = n - k; i < n; ++i)
		sum += v[i];
	return sum >= 0;
}

double optimize() {
	double lo = -1e-9, hi = 1;
	for (int i = 0; i < 100; i++) {
		double mid = (lo + hi) / 2;
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
			cin >> r[i] >> c[i];
		printf("%.10lf\n", optimize());
	}

	getchar();
	getchar();
    return 0;
}

