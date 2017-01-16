// APSS_Josephus.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
			//iterator�� ����Ű�� ���� �ڻ�
			soldier.erase(itor);
			remain--;
			//���� ����� �� ���� ���� ���� ����
			itor = soldier.begin();
			kill = (kill + K - 1) % remain;
			for (int i = 0; i < kill; i++)
				itor++;
		}

		cout << soldier.front() + 1 << " " << soldier.back() + 1 << endl;
	}

	return 0;
}

