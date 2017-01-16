// APSS_Arctic.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
		// ��ǥ �Է�
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			pos.push_back(make_pair(x, y));
		}
		// �� �������� �ٸ� �������� �Ÿ� �� �ּҰŸ� ���
		for (int i = 0; i < N-1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (mindist[i] > sqrt(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2)))
					mindist[i] = sqrt(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2));
			}
		}
		// ���� �ּҰŸ� �� �ִ밪 ���
		for (int i = 0; i < N-1; i++)
			if (ans < mindist[i])
				ans = mindist[i];
		printf("%.2lf\n", round(ans));
	}

	fclose(stdin);
	fclose(stdout);

    return 0;
}

