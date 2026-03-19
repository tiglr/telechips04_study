/*
문제 : 저글링 방사능 오염
Link : https://jungol.co.kr/problem/1078
Date : 2026-03-18
Created By: tiglr
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int row_size, col_size;
int x, y; // 방사능 시작 위치
int **map;

int second, survived;

typedef struct _node {
	int r, c, t;
}node;

node queue[102 * 102];
int front = 0, rear = 0;

int dR[4] = { -1, 1, 0, 0 };
int dC[4] = { 0, 0, -1, 1 };

void init();
void print();
void BFS(int, int);
void setup(int, int, int);


int main() {
	init();
	BFS(x, y);
	printf("%d\n%d", second, survived);
	return 0;
}
void init() {
	(void)scanf("%d %d", &col_size, &row_size);
	row_size += 2;
	col_size += 2;

	// 맵 동적할당
	map = (int**)calloc(row_size, sizeof(int*));
	for (int i = 0; i < row_size; ++i) {
		map[i] = (int*)calloc(col_size, sizeof(int));
	}

	// 맵 입력, 저장
	for (int i = 1; i < row_size-1; ++i) {
		for (int j = 1; j < col_size-1; ++j) {
			int tmp;
			(void)scanf(" %1d", &tmp);
			if (tmp) ++survived;
			map[i][j] = tmp;
		}
	}

	// 방사능 공격 위치
	(void)scanf("%d %d", &y, &x);
}

// 배열 출력 함수
void print() {
	for (int i = 0; i < row_size; ++i) {
		for (int j = 0; j < col_size; ++j) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

void BFS(int sR, int sC) {
	int time = 3; // 죽을 때까지 걸리는 시간
	int nR, nC; // 다음 위치를 저장하는 변수
	node data; // 다음 위치를 받는 구조체

	setup(sR, sC, time);

	while (front != rear) {
		data = queue[front++];

		for (int i = 0; i < 4; ++i) {
			nR = data.r + dR[i];
			nC = data.c + dC[i];
			if (map[nR][nC]) setup(nR, nC, data.t+1);
		}
	}

	second = data.t;
}

void setup(int x, int y, int t) {
	queue[rear++] = (node){ x, y, t };
	map[x][y] = 0;
	--survived;
}