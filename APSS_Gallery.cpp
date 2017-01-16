// APSS_Gallery.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

vector<int> edge[1000];
bool camera[1000];
bool visited[1000];

//깊이우선탐색으로 주어진 갤러리와 연결된 갤러리들 탐색
bool DFS(int gallery) {
	visited[gallery] = true;
	if (edge[gallery].size() == 0)
		return false;
	bool watched = false;
	for (int idx = 0; idx < edge[gallery].size(); idx++) {
		int child = edge[gallery][idx];
		if (!visited[child]) {
			if (!DFS(child)) {
				camera[gallery] = true;
				watched = true;
			}
			else {
				if (camera[child] == true)
					watched = true;
			}
		}
	}
	return watched;
}

int MinCamera(int G) {
	//초기화
	for (int gallery = 0; gallery < G; gallery++) {
		camera[gallery] = false;
		visited[gallery] = false;
	}
	//DFS
	for (int gallery = 0; gallery < G; gallery++) 
		if (!visited[gallery])
			if (!DFS(gallery))
				camera[gallery] = true;
	
	//Counting cameras
	int count = 0;
	for (int gallery = 0; gallery < G; gallery++)
		if (camera[gallery])
			count++;

	return count;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int G, H;
		cin >> G >> H;

		for (int g = 0; g < G; g++)
			edge[g].clear();

		int here, there;
		for (int h = 1; h <= H; h++) {
			cin >> here >> there;
			edge[here].push_back(there);
			edge[there].push_back(here);
		}
		cout << MinCamera(G) << endl;
	}
	return 0;
}

