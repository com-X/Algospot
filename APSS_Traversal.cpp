// APSS_Traversal.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int preorder[101], inorder[101];
int inIdx[1000];
int N;

void printPost(int preStart, int inStart, int inEnd) {
	// 주어진 subtree에서 root값 찾고(preorder[preStart])
	//   그 root의 inorder idx 찾는다(place[rootNum])
	// rootIdx-inIdx : left tree 노드 개수
	if (inStart >= inEnd) return;
	int rootNum = preorder[preStart];
	int rootIdx = inIdx[rootNum];

	printPost(preStart + 1, inStart, rootIdx);
	printPost(preStart + rootIdx - inStart + 1, rootIdx + 1, inEnd);
	cout << rootNum << " ";
}


int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> preorder[i];
		for (int i = 0; i < N; i++)
			cin >> inorder[i];
		for (int i = 0; i < N; i++)
			inIdx[inorder[i]] = i;
		
		printPost(0, 0, N);
		cout << endl;
	}
	return 0;
}
