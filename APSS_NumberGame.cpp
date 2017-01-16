// APSS_NumberGame.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N_MAX 50

int num[N_MAX];
int cache[N_MAX][N_MAX];


int getMaxGap(int l, int r) {

	if (cache[l][r] != INT_MIN)
		return cache[l][r];

	int choice[4]; // HyunWoo - SeoHa
	choice[0] = num[l] - getMaxGap(l + 1, r); 	//choice a left num
	choice[1] = num[r] - getMaxGap(l, r - 1);	//choice a right num
	if (r - 1 >= 1) { //left more than two numbers
		choice[2] = -1 * getMaxGap(l + 2, r);	//remove left two nums
		choice[3] = -1 * getMaxGap(l, r - 2);	//remove right two nums
	}
	else { 
		choice[2] = INT_MIN;
		choice[3] = INT_MIN;
	}

	int max = INT_MIN;
	for (int i = 0; i < 4; i++) {
		if (choice[i] > max)
			max = choice[i];
	}

	cache[l][r] = max;
	return max;

}

int main()
{
	int testcase;
	int N;
	int* result;
	scanf("%d", &testcase);
	result = (int*)malloc(sizeof(int)*testcase);

	for (int t = 0; t < testcase; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &num[i]);
		}
		//Initiate memory
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++)
				cache[i][j] = 0;
			cache[i][i] = num[i];
			for (int j = i + 1; j < N; j++)
				cache[i][j] = INT_MIN;
			
		}
		//get maximum gap
		result[t] = getMaxGap(0, N - 1);
	}

	for (int t = 0; t < testcase; t++) {
		printf("%d\n", result[t]);
	}

	free(result);

    return 0;
}

