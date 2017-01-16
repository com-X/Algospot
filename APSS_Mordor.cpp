// APSS_Mordor.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int n, q;

struct RMQ{
	int n; //배열 길이
	vector<int> rangeMin; //각 구간의 최소치

	RMQ(const vector<int>& array){
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n - 1, 1);
	}

	//node 노드가 array[left..right] 배열을 표현할때
	//node를 루트로 하는 서브트리를 초기화하고, 이 구간의 최소치를 반환
	int init(const vector<int>& array, int left, int right, int node){
		//leaf일때
		if (left == right) return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}

	//node가 표현하는 범위가 array[left..right]가 주어질때
	//이 범위와 array[left..right] 의 교집합의 최소치를 구한다.
	int query(int left, int right, int node, int nodeLeft, int nodeRight){
		//두 구간이 겹치지 않으면 아주 큰 값을 반환 : 무시
		if (right < nodeLeft || nodeRight < left) return INT_MAX;
		//node가 표현하는 범위가 array[left..right]에 완전히 포함되는 경우
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];
		//양쪽 구간을 나눠서 푼 뒤 결과를 합친다.
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	//query를 외부에서 호출하기 위한 인터페이스
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