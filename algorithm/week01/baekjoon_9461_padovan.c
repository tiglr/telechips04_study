/*
문제 : 파도반 수열
Link : https://www.acmicpc.net/problem/9461
Date : 2026-03-19
Created By: tiglr
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
long long cache[101] = { 0 };

void calculate_padovan();

int main() {
	int T, N;
	calculate_padovan();
	(void)scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		(void)scanf("%d", &N);
		printf("%lld\n", cache[N]);
	}
}

void calculate_padovan() {
	cache[1] = cache[2] = cache[3] = 1;
	for (int i = 4; i <= 100; ++i) {
		cache[i] = cache[i - 2] + cache[i - 3];
	}
}