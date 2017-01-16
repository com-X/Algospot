// APSS_Hanoi4B.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

const int MAX_DISCS = 12;
//
int c[1 << (MAX_DISCS * 2)];
//index�� ������ �ִ� ��� ��ȯ
int get(int state, int index) {
	return (state >> (2 * index)) & 3;
}
//index�� ������ value�� ������� �ű�
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
		//�� ��տ��� ���� ���� �ִ� ������ ��ȣ ���.
		int top[4] = { -1,-1,-1,-1 };
		for (int i = discs - 1; i >= 0; i--)
			top[get(now, i)] = i;
		//i�� ����� �� ���� �ִ� ������ j�� ������� �ű�
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

