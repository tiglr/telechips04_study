/*
문제 : 해밀턴 순환회로
Link : https://jungol.co.kr/problem/1681
Date : 2026-03-16
Created By: tiglr
*/

#include <stdio.h>

int N;
int cost[13][13];
int visited[13];
int result = 1000000000;

void solve(int pos, int depth, int sum)
{
    if (sum >= result) return;

    if (depth == N) {
        //마지막 도시에서 회사로 가는 길이 있을때만 반영
        if (cost[pos][0] != 0) {
            int total = sum + cost[pos][0];
            if (total < result)
                result = total;
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        if (cost[pos][i] == 0) continue;

        visited[i] = 1;
        solve(i, depth + 1, sum + cost[pos][i]);
        visited[i] = 0;
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;
    solve(0, 1, 0);

    printf("%d", result);
}
