/*
문제 : 거울
Link : https://www.acmicpc.net/problem/34201
Date : 2026-03-18
Created By: tiglr
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int N;
long long s;
long long* mirror;
long long result = 0;

int main() {
	scanf("%d %lld", &N, &s);
	mirror = (long long*)calloc(N, sizeof(long long));
	
	if (mirror == NULL) exit(1);
	long long mirror_pos;
	for (long long i = 0; i < N; ++i) {
		scanf("%lld", &mirror_pos);
		mirror[i] = mirror_pos;
	}
	int l = 0, r = N-1;
	if (N % 2 == 0) {
		while (l <= r) {
			result += -mirror[l] + mirror[r];
			--r;
			++l;
		}
		result *= 2;
		result += s;
	}
	else {
		while (l != r) {
			result += mirror[r] - mirror[l];
			--r;
			++l;
		}
		result += mirror[l];
		result *= 2;
		result -= s;
	}
	free(mirror);
	mirror = NULL;
	printf("%lld", result);
	return 0;
}
