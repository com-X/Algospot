// APSS_Hanoi4_Interactive.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <queue>
#include <string.h>

using namespace std;

const int MAX_DISCS = 12;
int c[1 << (MAX_DISCS*2)];
int N;

//x의 부호를 반환(양수/0/음수:1/0/-1)
int sgn(int x) {
	if (!x) return 0;
	return x > 0 ? 1 : -1;
}
//x의 절대값을 1 증가시킴
int incr(int x) {
	if (x < 0) return x - 1;
	return x + 1;
}
//index번 원반이 있는 기둥 반환
int get(int state, int index) {
	return (state >> (2 * index)) & 3;
}
//index번 원반을 value번 기둥으로 옮김
int set(int state, int index, int value) {
	return (state & ~(3 << (2 * index))) | (value << (2 * index));
}
//begin이 주어질 때 최소 움직임의 수 계산
int interdir(int begin) {
	int end = pow(2, N * 2) - 1;
	if (begin == end) return 0;
	queue<int> q;
	//초기화를 0으로 하는 데 주의
	memset(c, 0, sizeof(c));
	//정방향 탐색은 양수로, 역방향 탐색은 음수로 표시
	q.push(begin); c[begin] = 1;
	q.push(end); c[end] = -1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int top[4] = { -1,-1,-1,-1 };
		for (int i = N - 1; i >= 0; i--)
			top[get(now, i)] = i;
		for(int i=0;i<4;i++)
			if(top[i]!=-1)
				for(int j=0;j<4;j++)
					if (i != j && (top[j] == -1) || (top[j] > top[i])) {
						int moved = set(now, top[i], j);
						//아직 방문하지 않은 정점인 경우
						if (c[moved] == 0) {
							c[moved] += incr(c[now]);
							q.push(moved);
						}
						//가운데서 만난 경우
						else if (sgn(c[moved]) != sgn(c[now]))
							return abs(c[moved]) + abs(c[now]) - 1;
					}
	}
	return -1;
}

int main()
{
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int start = 0;
		cin >> N;
		for (int i = 0; i < 4; i++) {
			int num, disc;
			cin >> num;
			while (num--) {
				cin >> disc;
				start |= (i << ((disc - 1) * 2));
			}
		}
		cout << interdir(start) << endl;
	}
	return 0;
}


