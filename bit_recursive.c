#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N = 4;
int arr[10] = { 0 };
int data[10] = { 8, 4, 2, 1 };
int Target = 5;

void print_arr() {
	for (int i = 1; i <= N; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void make_num(int L, int cnt) {
	if (L > N) {
		printf("cnt: %d / ", cnt);
		print_arr();
		return;
	}
	printf("make_num(%d, %d) call make_num(%d, %d)\n", L, cnt, L + 1, cnt);
	arr[L] = 0;
	make_num(L + 1, cnt);
	printf("make_num(%d, %d) call make_num(%d, %d)\n", L, cnt, L + 1, cnt+1);
	arr[L] = 1;
	make_num(L + 1, cnt + 1);
}

int main() {
	make_num(1, 0);
	return 0;
}
