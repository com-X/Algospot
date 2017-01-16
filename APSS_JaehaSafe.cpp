// APSS_JaehaSafe.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> safes;
int N;

int Count() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		string now = safes[i]+safes[i];
		string next = safes[i + 1];
		while (now != next) {
			//i%2==0은 시계방향,아니면 반시계
			//now=next될 때까지 now 움직임
			int spin = 1;
			if (i % 2 == 0) {
				while (now.at((now.size() - 1) - spin) != next.at(0)) {
					spin++;
				};
				spin += 1;
				string tmp;
				tmp += now.at(now.size()-spin);
				tmp += now.substr(now.size()-spin+1, now.size());
				tmp += now.substr(0, now.size() - spin);
				now = tmp;
			}
			else {
				while (now.at(spin) != next.at(0)) {
					spin++;
				};
				string tmp;
				tmp += now.at(spin);
				tmp += now.substr(spin + 1, now.size());
				tmp += now.substr(0, spin);
				now = tmp;
			}
			count += spin;
		}
	}
	return count;
}

int main()
{
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> N;
		for (int i = 0; i < N + 1; i++) {
			string tmp;
			cin >> tmp;
			safes.push_back(tmp);
		}
		cout << Count() << endl;
		safes.clear();
	}
    return 0;
}

