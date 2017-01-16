// APSS_Arctic.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define round(x) (floor((x)*pow(float(10),2) + 0.5f)/pow(float(10),2))

int N;
vector<pair<double, double>> pos;
double mindist[101];

int main()
{
	int t;
	double x, y;
	double ans = 0;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	while (t--) {
		fill_n(mindist, 101, 999999);
		pos.clear();
		ans = 0;
		cin >> N;
		// 좌표 입력
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			pos.push_back(make_pair(x, y));
		}
		// 각 지점에서 다른 지점까지 거리 중 최소거리 계산
		for (int i = 0; i < N-1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (mindist[i] > sqrt(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2)))
					mindist[i] = sqrt(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2));
			}
		}
		// 구한 최소거리 중 최대값 출력
		for (int i = 0; i < N-1; i++)
			if (ans < mindist[i])
				ans = mindist[i];
		printf("%.2lf\n", round(ans));
	}

	fclose(stdin);
	fclose(stdout);

    return 0;
}

