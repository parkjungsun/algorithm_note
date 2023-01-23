/* 백준 2178 | 미로 탐색 https://www.acmicpc.net/problem/2178 */

/*
    (1,1) -> (n,m)
    1. BFS 거리 탐색
        1) 갈 수 있는가
        2) 자기보다 큰가 -> 업데이트
    2. 미로 범위
        1) 1 <= x <= m
        2) 1 <= y <=n
*/

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

int n, m;
int _map[105][105] = { 0, };
int visited[105][105] = { 0, };

void printM();

void solve(int y, int x) {
    //printM();
    // 상
    if(y-1 >= 1 && _map[y-1][x] != 0) {
        if(visited[y-1][x] == 0 || visited[y-1][x] > visited[y][x] + 1) {
            visited[y-1][x] = visited[y][x] + 1;
            solve(y-1, x);
        }
    }
    // 하
    if(y+1 <= n && _map[y+1][x] != 0) {
        if(visited[y+1][x] == 0 || visited[y+1][x] > visited[y][x] + 1) {
            visited[y+1][x] = visited[y][x] + 1;
            solve(y+1, x);
        }
    }
    // 좌
    if(x-1 >= 1 && _map[y][x-1] != 0) {
        if(visited[y][x-1] == 0 || visited[y][x-1] > visited[y][x] + 1) {
            visited[y][x-1] = visited[y][x] + 1;
            solve(y, x-1);
        }
    }
    // 우
    if(x+1 <=m && _map[y][x+1] != 0) {
        if(visited[y][x+1] == 0 || visited[y][x+1] > visited[y][x] + 1) {
            visited[y][x+1] = visited[y][x] + 1;
            solve(y, x+1);
        }
    }
}

void input_by_cmd() {
    cin >> n >> m;

    string tmp;    
    for(int i=1; i<=n; i++) {
        cin >> tmp;

        for(int j=1; j<=m; j++) {
            _map[i][j] = tmp[j-1] - '0';
        }
    }
}

void output() {
    cout << visited[n][m] << "\n";
}

void printM() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout << visited[i][j] << " "; 
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input_by_cmd();
    
    visited[1][1] = 1;
    solve(1,1);

    output();

    return 0;
}


