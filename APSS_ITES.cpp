// APSS_ITES.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

int N, K;

int Count() {
	queue<unsigned int> list;
	unsigned int raw_signal = 1983;
	unsigned int input_signal;
	int count=0, sum = 0;
	for (int i = 0; i < N; i++) {
		//1. queue에 signal입력
		//2. sum<K?(다음signal입력):(앞에signal pop)
		//3. 같으면 count++
		input_signal = raw_signal % 10000 + 1;
		list.push(input_signal);
		sum += input_signal;
		if (sum > K)
			while (sum > K) {
				sum -= list.front();
				list.pop();
			}
		if (sum == K) count++;

		raw_signal = raw_signal * 214013u + 2531011u;
	}
	return count;
}

int main()
{
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> K >> N;
		cout << Count() << endl;
	}

    return 0;
}

