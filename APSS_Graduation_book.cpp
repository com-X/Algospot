// APSS_Graduation.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	//기저 사례: k개 이상의 과목을 이미 들은 경우
	if (bitCount(taken) >= K)
		return 0;
	//기저 사례: m학기가 전부 지난 경우
	if (semester == M)
		return INF;
	//메모이제이션
	int& ret = cache[semester][taken];
	if (ret != -1) return ret;
	ret = INF;
	//이번 학기에 들을 수 있는 과목 중 아직 듣지 않은 과목을 찾는다
	int canTake = (classes[semester] & ~taken);
	//선수 과목을 다 듣지 않은 과목들을 걸러낸다.
	for (int i = 0; i < N; i++)
		if ((canTake & (1 << i)) && (taken & prerequisite[i]) != prerequisite[i])
			canTake &= ~(1 << i);
	//이 집합의 모든 부분집합을 순회한다
	for (int take = canTake; take > 0; take = ((take - 1) & canTake)) {
		//한 학기에 1과목까지만 들을 수 있다.
		if (bitCount(take) > L) continue;
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	//이번 학기에 아무 것도 듣지 않을 경우
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

