// APSS_Ratio.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		long long N, M;
		cin >> N >> M;
		long long W = (M * 100) / N;
		if (W >= 99)
			cout << -1 << endl;
		else {
			long long count = ceil(((W + 1)*N - 100 * M) / (double)(99 - W));
			if (count > 2000000000)
				cout << -1 << endl;
			else
				cout << count << endl;
		}
	}
	return 0;
}

