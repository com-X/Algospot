// APSS_Hanoi4_Interactive.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

//x�� ��ȣ�� ��ȯ(���/0/����:1/0/-1)
int sgn(int x) {
	if (!x) return 0;
	return x > 0 ? 1 : -1;
}
//x�� ���밪�� 1 ������Ŵ
int incr(int x) {
	if (x < 0) return x - 1;
	return x + 1;
}
//index�� ������ �ִ� ��� ��ȯ
int get(int state, int index) {
	return (state >> (2 * index)) & 3;
}
//index�� ������ value�� ������� �ű�
int set(int state, int index, int value) {
	return (state & ~(3 << (2 * index))) | (value << (2 * index));
}
//begin�� �־��� �� �ּ� �������� �� ���
int interdir(int begin) {
	int end = pow(2, N * 2) - 1;
	if (begin == end) return 0;
	queue<int> q;
	//�ʱ�ȭ�� 0���� �ϴ� �� ����
	memset(c, 0, sizeof(c));
	//������ Ž���� �����, ������ Ž���� ������ ǥ��
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
						//���� �湮���� ���� ������ ���
						if (c[moved] == 0) {
							c[moved] += incr(c[now]);
							q.push(moved);
						}
						//����� ���� ���
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


