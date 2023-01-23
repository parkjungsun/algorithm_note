/* 백준 1012 | 유기농 배추 https://www.acmicpc.net/problem/1012 */

/*
    몇개의 순환 그래프가 있는 가
    1. 배추가 있고, 방문 안했으면 ㄱ
*/

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

const int max_n = 55;

int test, m, n, k;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int visited[max_n][max_n] = { 0, };
int _map[max_n][max_n] = {0,};

void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n || nx >= m || nx < 0) continue;
        if(visited[ny][nx] == 0 && _map[ny][nx] == 1) {
            dfs(ny, nx);
        }
    }
}

int solve() {
    int result = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(_map[i][j] == 1 && visited[i][j] == 0) {
                    dfs(i,j); 
                    result++;
                }
            }
        }
    return result;
}

void input_by_cmd() {
    cin >> test;
    for(int i=0; i<test; i++) {
        cin >> m >> n >> k;
        
        fill(&visited[0][0], &visited[0][0]+max_n*max_n, 0);
        fill(&_map[0][0], &_map[0][0]+max_n*max_n, 0);

        for(int j=0; j<k; j++) {
            int y, x; cin >> x >> y; _map[y][x] = 1;
        }

        cout << solve() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input_by_cmd();

    return 0;
}


