/*
문제 : nQueen
Link : https://www.acmicpc.net/problem/9663
Date : 2026-03-16
Created By: tiglr
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 15

#include <stdio.h>
#include <stdlib.h>

int N;
int arr[MAX_SIZE][MAX_SIZE];
int c_visited[MAX_SIZE];
int diagonal1[MAX_SIZE * 2];
int diagonal2[MAX_SIZE * 3];
int count;

void search(int);
int check_queen(int, int);

int main() {
	(void)scanf("%d", &N);
	search(0);
	printf("%d\n", count);
	return 0;
}

void search(int r) {
	if (r == N) { count++; return; }
	for (int c = 0; c < N; ++c) {
		if (check_queen(r, c)) {
			arr[r][c] = c_visited[c] = diagonal1[r + c] = diagonal2[r - c + N] = 1;
			search(r + 1);
			arr[r][c] = c_visited[c] = diagonal1[r + c] = diagonal2[r - c + N] = 0;
		}
	}
}

int check_queen(int r, int c) {
	if (c_visited[c]) return 0;
	if (diagonal1[r + c]) return 0;
	if (diagonal2[r - c + N]) return 0;
	return 1;
}
