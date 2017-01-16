// APSS_Mordor.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int n, q;

struct RMQ{
	int n; //�迭 ����
	vector<int> rangeMin; //�� ������ �ּ�ġ

	RMQ(const vector<int>& array){
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n - 1, 1);
	}

	//node ��尡 array[left..right] �迭�� ǥ���Ҷ�
	//node�� ��Ʈ�� �ϴ� ����Ʈ���� �ʱ�ȭ�ϰ�, �� ������ �ּ�ġ�� ��ȯ
	int init(const vector<int>& array, int left, int right, int node){
		//leaf�϶�
		if (left == right) return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}

	//node�� ǥ���ϴ� ������ array[left..right]�� �־�����
	//�� ������ array[left..right] �� �������� �ּ�ġ�� ���Ѵ�.
	int query(int left, int right, int node, int nodeLeft, int nodeRight){
		//�� ������ ��ġ�� ������ ���� ū ���� ��ȯ : ����
		if (right < nodeLeft || nodeRight < left) return INT_MAX;
		//node�� ǥ���ϴ� ������ array[left..right]�� ������ ���ԵǴ� ���
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];
		//���� ������ ������ Ǭ �� ����� ��ģ��.
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	//query�� �ܺο��� ȣ���ϱ� ���� �������̽�
	int query(int left, int right){
		return query(left, right, 1, 0, n - 1);
	}
};

int main()
{
	int testcase;

	cin >> testcase;

	while (testcase--){
		cin >> n >> q;
		vector<int> v, w;
		int h, min, max;
		for (int i = 0; i < n; i++)
		{
			cin >> h;
			v.push_back(h);
			w.push_back(-h);
		}
		RMQ r_max(w);
		RMQ r_min(v);
		for (int i = 0; i < q; i++)
		{
			cin >> min >> max;
			cout << -r_max.query(min, max) - r_min.query(min, max) << endl;
		}
	}
	return 0;
}