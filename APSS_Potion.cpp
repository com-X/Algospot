// APSS_Potion.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

int GCD(int p, int q) {
	return q == 0 ? p : GCD(q, p%q);
}

using namespace std;

int rec[200];
int put[200];

int main()
{
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int N, gcd;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> rec[i];
		for (int i = 0; i < N; i++)
			cin >> put[i];
		//최대공약수 계산
		gcd = rec[0];
		for (int i = 1; i < N; i++)
			gcd = GCD(gcd, rec[i]);
		//기준값 비율값으로 재정의
		for (int i = 0; i < N; i++)
			rec[i] = rec[i] / gcd;
		//실제 포션 중에 기준치와 가장 벗어나는 것 선택
		double maxrate = (double)put[0] / rec[0];
		for (int i = 1; i < N; i++)
			if (maxrate < (double)put[i] / rec[i])
				maxrate = (double)put[i] / rec[i];
		maxrate = ceil(maxrate);
		for (int i = 0; i < N; i++) {
			rec[i] *= maxrate;
			printf("%d ", rec[i] - put[i]);
		}
		printf("\n");
	}
    return 0;
}

