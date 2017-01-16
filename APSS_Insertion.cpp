// APSS_Insertion.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int shifts[50000];
int N;
vector<int> nums;

void printOrigin(int idx) {
	if (idx == N) return;

	auto itr = --nums.end();
	int shift = shifts[idx];
	for (int i = 0; i < shift; i++)
		itr--;
	int num = nums.at(nums.size()-1-shift);
	nums.erase(itr);
	printOrigin(idx + 1);
	cout << num << " ";
}

int main()
{
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> N;
		
		for (int i = 1; i <= N; i++)
			nums.push_back(i);
		for (int i = N - 1; i >= 0; i--)
			cin >> shifts[i];
		printOrigin(0);
		cout << "\n";
		nums.clear();
	}

    return 0;
}

