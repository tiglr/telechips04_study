/*
문제 : 바이러스
Link : https://www.acmicpc.net/problem/2606
Date : 2026-03-16
Created By: tiglr
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_N (100+1)

#include <stdio.h>

int adjM[MAX_N][MAX_N]; // 인접 행렬
int adjL[MAX_N][MAX_N]; // 인접 리스트
int visited[MAX_N];
int V, E; // 정점 개수(컴퓨터 개수), 간선 개수(연결 개수)

// 데이터 입력
void inputDataM();
void inputDataL();

// 데이터 출력
void print_adjM();
void print_adjL();

// 탐색(재귀)
int rec_adjM(int);
int rec_adjL(int);


int main() {
	inputDataL();
	//print_adjL();
	printf("%d\n", rec_adjL(1) - 1);
}

void inputDataM(void) {
	int v1, v2;

	(void)scanf("%d", &V);
	(void)scanf("%d", &E);

	for (int i = 0; i < E; ++i) {
		(void)scanf("%d %d", &v1, &v2);
		adjM[v1 - 1][v2 - 1] = 1;
		adjM[v2 - 1][v1 - 1] = 1;
	}
}

void inputDataL(void) {
	int v1, v2;

	(void)scanf("%d", &V);
	(void)scanf("%d", &E);

	for (int i = 0; i < E; ++i) {
		(void)scanf("%d %d", &v1, &v2);
		int index1 = ++adjL[v1 - 1][0];
		int index2 = ++adjL[v2 - 1][0];
		adjL[v1 - 1][index1] = v2;
		adjL[v2 - 1][index2] = v1;
	}
}

void print_adjM(void) {
	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			printf("%d ", adjM[i][j]);
		}
		printf("\n");
	}
}

void print_adjL(void) {
	for (int i = 0; i < V; ++i) {
		printf("computer number: %d, Count: %d, Link: ", i + 1, adjL[i][0]);
		for (int j = 1; j <= adjL[i][0]; ++j) {
			printf("%d ", adjL[i][j]);
		}
		printf("\n");
	}
}

int rec_adjM(int vertex) {
	int index = vertex - 1;
	int count = 1;

	if (visited[index]) return 0;
	visited[index] = 1;

	for (int i = 0; i < V; ++i) {
		// 컴퓨터끼리 연결이 안되있거나 다음 목적지를 이미 방문했으면 실행 X
		if (adjM[index][i] && !visited[i]) {
			count += rec_adjM(i + 1);
		}
	}

	return count;
}

int rec_adjL(int vertex) {
	int index = vertex - 1;
	int count = 1;
	int* list = adjL[index];

	if (visited[index]) return 0;
	visited[index] = 1;

	for (int i = 1; i <= list[0]; ++i) {
		// 다음 목적지를 이미 방문했으면 실행 X
		if(!visited[list[i] -1]) count += rec_adjL(list[i]);
	}

	return count;
}
