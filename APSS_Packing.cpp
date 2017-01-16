// APSS_Packing.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int N=0;//stuff���� 

typedef struct _stuff{
	char name[20];
	int volume;
	int value;
}Stuff;

typedef struct _result {
	int count;
	int value;
	char picked[100][20];
}Result;

int getMaximumValue(Stuff* stuff, int* picked, int capacity, int i) {
	//������ ���� ����
	if (i == N)
		return 0;
	//����� ���� Ž�� ��
	picked[i] = 0;
	int noPick= getMaximumValue(stuff,picked, capacity, i + 1);
	picked[i] = 1;
	int yesPick = 0;
	if (capacity >= stuff[i].volume) {
		yesPick = (getMaximumValue(stuff,picked, capacity - stuff[i].volume, i + 1)) + stuff[i].value;
	}
	
	if (noPick < yesPick) {
		picked[i] = 1;
		return yesPick;
	}
	else {
		picked[i] = 0;
		return noPick;
	}
}


int main()
{
	int testcase, t;
	int capacity;
	int i;
	Result* result;
	int* picked;
	Stuff* stuff;

	scanf("%d", &testcase);
	result = (Result*)malloc(sizeof(Result)*testcase);

	for (t = 0; t < testcase; t++) {
		result[t].count = 0;
		scanf("%d %d", &N, &capacity);
		stuff = (Stuff*)malloc(sizeof(Stuff)*N);
		picked = (int*)malloc(sizeof(int)*N); //�Է¹��� ���� �� ���� �� �� üũ�ϴ� �迭
		for (i = 0; i < N; i++) {
			scanf("%s", stuff[i].name);
			scanf("%d%d", &stuff[i].volume, &stuff[i].value);
		}
		result[t].value = getMaximumValue(stuff, picked, capacity, 0);

		//���õ� ������ ���� ������� �Է� �� free
		for (i = 0; i < N; i++) {
			if (picked[i] == 1) {
				strcpy(result[t].picked[result[t].count], stuff[i].name);
				result[t].count++;
			}
		}
		free(stuff);
		free(picked);
	}
	for (t = 0; t < testcase; t++) {
		printf("%d %d\n", result[t].value, result[t].count);
		for (i = 0; i < result[t].count; i++)
			printf("%s\n", result[t].picked[i]);
	}
	free(result);
    return 0;
}
