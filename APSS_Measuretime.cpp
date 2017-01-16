// APSS_Measuretime.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//���� Ʈ���� ����. ������ �迭 A[]�� �κ� ����
//������ ������ �� �ֵ��� �Ѵ�. �ʱ�ȭ�ÿ��� A[]��
//���Ұ� ���� 0�̶�� ����.
struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n) : tree(n+1) {}
	//0���� pos������ �κ��� ��ȯ
	int sum(int pos) {
		//�ε��� 1���� ����
		++pos;
		int ret = 0;
		while (pos) {
			ret += tree[pos];
			//���� ������ ã�� ���� ���� ��Ʈ�� �����
			pos &= (pos - 1);
		}
		return ret;
	}
	//A[pos]�� val�� ���Ѵ�.
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


