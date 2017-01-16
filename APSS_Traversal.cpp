// APSS_Traversal.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int preorder[101], inorder[101];
int inIdx[1000];
int N;

void printPost(int preStart, int inStart, int inEnd) {
	// �־��� subtree���� root�� ã��(preorder[preStart])
	//   �� root�� inorder idx ã�´�(place[rootNum])
	// rootIdx-inIdx : left tree ��� ����
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
