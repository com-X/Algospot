// APSS_Measuretime.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//펜윅 트리의 구현. 가상의 배열 A[]의 부분 합을
//빠르게 구현할 수 있도록 한다. 초기화시에는 A[]의
//원소가 전부 0이라고 생각.
struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n) : tree(n+1) {}
	//0부터 pos까지의 부분합 반환
	int sum(int pos) {
		//인덱스 1부터 시작
		++pos;
		int ret = 0;
		while (pos) {
			ret += tree[pos];
			//다음 구간을 찾기 위해 최종 비트를 지운다
			pos &= (pos - 1);
		}
		return ret;
	}
	//A[pos]에 val을 더한다.
	void add(int pos, int val) {
		++pos;
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & (-pos));
		}
	}
};

long long countMoves(const vector<int>& A) {
	FenwickTree tree(1000000);
	long long ret = 0;
	for (int i = 0; i < A.size(); i++) {
		ret += tree.sum(999999) - tree.sum(A[i]);
		tree.add(A[i], 1);
	}
	return ret;
}


int main()
{
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int N, val;
		cin >> N;
		vector<int> A;
		for (int i = 0; i < N; i++) {
			cin >> val;
			A.push_back(val);
		}
		cout << countMoves(A) << endl;
	}
	return 0;
}


