// APSS_Strjoin.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>

using namespace std;

int num[100], N;

int getmin(){
	priority_queue<int, vector<int>, greater<int> > pq;
	
	for (int i = 0; i < N; i++)
		pq.push(num[i]);

	int ret = 0;

	while (pq.size() > 1) {
		int min1 = pq.top();
		pq.pop();
		int min2 = pq.top();
		pq.pop();
		pq.push(min1 + min2);
		ret += min1 + min2;
	}
	return ret;
}

int main()
{
	int testcase;

	scanf("%d", &testcase);
	for (int t = 0; t < testcase; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &num[i]);
		}

		cout << getmin() << endl;
	}
    return 0;
}

