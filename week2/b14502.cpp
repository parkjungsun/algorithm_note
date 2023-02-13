/* 백준 14502 | 연구소 https://www.acmicpc.net/problem/14502 */

/* 
    1. 벽세우기
    2. 바이러스
    3. 안전영역
*/

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

    int n, m, ret=0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int _map[10][10] = {0,};
vector<pair<int,int>> emptylist;
vector<pair<int,int>> viruslist;
int visited[10][10];

void dfs(int y, int x) {
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || _map[ny][nx] == 1) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
    return ;
}
int defuse() {
    fill(&visited[0][0], &visited[0][0] + 10*10, 0);
    for(int i=0; i < viruslist.size(); i++) {
        int ny = viruslist[i].first;
        int nx = viruslist[i].second;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(_map[i][j] == 0 && !visited[i][j]) cnt++;
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> _map[i][j];
            if(_map[i][j] == 0) emptylist.push_back({ i, j }); 
            if(_map[i][j] == 2) viruslist.push_back({ i, j });
        }
    }

    for(int i=0; i< emptylist.size(); i++) {
        for(int j=0; j < i; j++) {
            for(int k = 0; k < j; k++) {
                _map[emptylist[i].first][emptylist[i].second] = 1;
                _map[emptylist[j].first][emptylist[j].second] = 1;
                _map[emptylist[k].first][emptylist[k].second] = 1;
                ret = max(ret, defuse());
                _map[emptylist[i].first][emptylist[i].second] = 0;
                _map[emptylist[j].first][emptylist[j].second] = 0;
                _map[emptylist[k].first][emptylist[k].second] = 0;
            }
        }
    }


    cout << ret << "\n";
    return 0;
}


