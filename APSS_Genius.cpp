// APSS_Genius.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n, k, lengh[50];
int m, order[50];
double T[50][50];
vector<double> result;

vector<double>getProb() {
	//c[time][song] : time분 후에 song번 노래가 시작할 확률
	double c[5][50];
	memset(c, 0, sizeof(c));
	c[0][0] = 1.0;
	for(int time=1;time<=k;++time)
		for (int song = 0; song < n; ++song) {
			double& prob = c[time % 5][song];
			prob = 0;
			for (int last = 0; last < n; ++last)
				prob += c[(time - lengh[last] + 5) % 5][last] * T[last][song];
		}

	vector<double> ret(n);
	//song번 노래가 재생되고 있을 확률을 계산한다.
	for (int song = 0; song < n; ++song)
		//song번 노래가 시작했을 시간을 모두 찾아 더한다.
		for (int start = k - lengh[song] + 1; start <= k; ++start)
			ret[song] += c[start % 5][song];

	return ret;
}



int main()
{
	int testcase;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &testcase);
	
	for (int t = 0; t < testcase; t++) {
		cin >> n >> k >> m;
		for (int i = 0; i < n; i++)
			cin >> lengh[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> T[i][j];
		for (int i = 0; i < n; i++)
			cin >> order[i];
		
		for (int i = 0; i < n; i++)
			printf("%.8lf ", getProb()[order[i]]);
			
		cout << endl;
	}

	fclose(stdin);
	fclose(stdout);
    return 0;
}

