// APSS_Potion.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
		//�ִ����� ���
		gcd = rec[0];
		for (int i = 1; i < N; i++)
			gcd = GCD(gcd, rec[i]);
		//���ذ� ���������� ������
		for (int i = 0; i < N; i++)
			rec[i] = rec[i] / gcd;
		//���� ���� �߿� ����ġ�� ���� ����� �� ����
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

