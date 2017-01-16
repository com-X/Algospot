// APSS_Graduation.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <limits.h>
#include <iostream>
#include <intrin.h>

#define min(a,b) (a<b)?a:b

using namespace std;

const int INF = 987654321;
int N, K, M, L;
int prerequisite[12];
int classes[10];
int cache[10][1 << 12];

int bitCount(int n) {
	return __popcnt(n);
}

int graduate(int semester, int taken) {
	//���� ���: k�� �̻��� ������ �̹� ���� ���
	if (bitCount(taken) >= K)
		return 0;
	//���� ���: m�бⰡ ���� ���� ���
	if (semester == M)
		return INF;
	//�޸������̼�
	int& ret = cache[semester][taken];
	if (ret != -1) return ret;
	ret = INF;
	//�̹� �б⿡ ���� �� �ִ� ���� �� ���� ���� ���� ������ ã�´�
	int canTake = (classes[semester] & ~taken);
	//���� ������ �� ���� ���� ������� �ɷ�����.
	for (int i = 0; i < N; i++)
		if ((canTake & (1 << i)) && (taken & prerequisite[i]) != prerequisite[i])
			canTake &= ~(1 << i);
	//�� ������ ��� �κ������� ��ȸ�Ѵ�
	for (int take = canTake; take > 0; take = ((take - 1) & canTake)) {
		//�� �б⿡ 1��������� ���� �� �ִ�.
		if (bitCount(take) > L) continue;
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	//�̹� �б⿡ �ƹ� �͵� ���� ���� ���
	ret = min(ret, graduate(semester + 1, taken));
	return ret;
}


int main()
{
	int testcase;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> testcase;
	while (testcase--) {
		memset(cache, -1, sizeof(cache));
		memset(prerequisite, 0, sizeof(prerequisite));
		memset(classes, 0, sizeof(classes));
		cin >> N >> K >> M >> L;
		for (int n = 0; n < N; n++) {
			int rcount;
			cin >> rcount;
			for (int c = 0; c < rcount; c++) {
				int prerequisited;
				cin >> prerequisited;
				prerequisite[n]|= (1 << prerequisited);
			}
		}
		for (int m = 0; m < M; m++) {
			int mcount;
			cin >> mcount;
			for (int c = 0; c < mcount; c++) {
				int opened;
				cin >> opened;
				classes[m] |= (1 << opened);
			}
		}
		if (graduate(0, 0) == INF)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << graduate(0, 0) << endl;

	}

	fclose(stdin);
	fclose(stdout);
    return 0;
}

