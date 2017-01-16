// APSS_Pass486.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

const int TM = 10000 * 1000;
int factors[TM];

void setFactor() {
	memset(factors, 0, sizeof(factors));
	for (int div = 1; div <= TM; ++div)
		for (int multiple = div; multiple <= TM; multiple += div)
			factors[multiple]++;
}

int main() {
	int testcase;
	setFactor();
	cin >> testcase;
	while (testcase--) {
		int N, lo, hi;
		int count = 0;
		cin >> N >> lo >> hi;
		for (int i = lo; i <= hi; i++)
			if (factors[i] == N)
				count++;

		cout << count << endl;
	}

	return 0;
}



