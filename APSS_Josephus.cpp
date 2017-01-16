// APSS_Josephus.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <list>
#include <iostream>

using namespace std;

int main() {
	int testcase;
	int N, K;
	cin >> testcase;
	while (testcase--) {
		cin >> N >> K;
		list<int> soldier;
		int remain = N;
		for (int i = 0; i < N; i++)
			soldier.push_back(i);
		int kill = 0;

		list<int>::iterator itor = soldier.begin();
		while (remain>2) {
			//iterator가 가리키는 병사 자살
			soldier.erase(itor);
			remain--;
			//남은 병사들 중 다음 죽을 병사 지목
			itor = soldier.begin();
			kill = (kill + K - 1) % remain;
			for (int i = 0; i < kill; i++)
				itor++;
		}

		cout << soldier.front() + 1 << " " << soldier.back() + 1 << endl;
	}

	return 0;
}

