/* 백준 2468 | 안전 영역 https://www.acmicpc.net/problem/2468 */

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

int n, _max = 0;
int result = 0, tmp = 0;
int visited[101][101] = { 0, };
int _map[101][101] = { 0, };

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void dfs(int y, int x, int d) {
    visited[y][x] = 1;

    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(visited[ny][nx] == 0 && _map[ny][nx] > d) dfs(ny, nx, d);
    }
}

void solve() {
    for(int d = 1; d < 101; d++) {
        fill(&visited[0][0], &visited[0][0]+101*101, 0);
        tmp = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(visited[i][j] == 0 && _map[i][j] > d) {
                    dfs(i, j, d);
                    tmp++;
                }
            }
        }
        result = max(result, tmp);
    }
}

void input_by_cmd() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> _map[i][j];
        }
    }
}

void output() {
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    input_by_cmd();
    solve();
    output();

    return 0;
}


