// APSS_Hanoi4B.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

const int MAX_DISCS = 12;
//
int c[1 << (MAX_DISCS * 2)];
//index번 원반이 있는 기둥 반환
int get(int state, int index) {
	return (state >> (2 * index)) & 3;
}
//index번 원반을 value번 기둥으로 옮김
int set(int state, int index, int value) {
	return (state & ~(3 << (2 * index))) | (value << (2 * index));
}
int BFS(int discs, int begin) {
	int end = pow(2, discs * 2) - 1;
	if (begin == end) return 0;
	queue<int> q;
	memset(c, -1, sizeof(c));
	q.push(begin);
	c[begin] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		//각 기둥에서 제일 위에 있는 원반의 번호 계산.
		int top[4] = { -1,-1,-1,-1 };
		for (int i = discs - 1; i >= 0; i--)
			top[get(now, i)] = i;
		//i번 기둥의 맨 위에 있는 원반을 j번 기둥으로 옮김
		for(int i=0;i<4;i++)
			if(top[i]!=-1)
				for (int j = 0; j < 4; j++)
					if (i != j && (top[j] == -1) || (top[j] > top[i])) {
						int moved = set(now, top[i], j);
						if (c[moved] != -1) continue;
						c[moved] = c[now] + 1;
						if (moved == end) return c[moved];
						q.push(moved);
					}
	}
	return -1;
}



int main()
{
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int N;
		int start = 0;
		cin >> N;
		for (int i = 0; i < 4; i++) {
			int num, disc;
			cin >> num;
			while (num--) {
				cin >> disc;
				start |= (i << ((disc-1) * 2));
			}
		}
		cout << BFS(N, start) << endl;
	}
    return 0;
}

