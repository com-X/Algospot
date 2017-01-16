// APSS_CanadaTrip.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define min(a,b) ((a<b)?a:b)

int n, k;
int l[5000], m[5000], g[5000];//도시까지 거리, 표지판 위치, 간격



//dist지점까지 가면서 k개 이상의 표지판을 만날 수 있는가?
bool decision(int dist) {
	int ret = 0;
	for (int i = 0; i < n; ++i) { //겹치는 구간에 진입했을 때 보게 될 표지판 개수
		if (dist >= l[i] - m[i])
			ret += (min(dist, l[i]) - (l[i] - m[i])) / g[i] + 1;
	}
	return ret >= k;
}

//k번째 표지판을 만나는 지점의 위치 계산
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

