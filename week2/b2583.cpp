/* 백준 2583 | 영역 구하기 https://www.acmicpc.net/problem/2583 */

/* 
    영역 구하기
    1. 영역의 개수
    2. 각 영역의 크기
*/

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

int m, n, k;
int px1, py1, px2, py2;
int _map[101][101] = {0,};
int visited[101][101] = {0,};
int cnt = 0;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

vector<int> area;

void printM();

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y}); 

    int lx, ly, result = 1;
    while(!q.empty()) {
        tie(lx,ly) = q.front(); 
        q.pop();
        for(int i=0; i<4; i++) {
            int ny = ly + dy[i];
            int nx = lx + dx[i];

            if(ny < 0 || nx < 0 || ny >= m || nx >= n || _map[ny][nx] == 1 || visited[ny][nx] == 1) continue;
            q.push({nx, ny});
            visited[ny][nx] = 1;
            result++; 
        }
    }
    area.push_back(result);
}

void solve() {
    for(int y=0; y<m; y++) {
        for(int x=0; x<n; x++) {
            if(!visited[y][x] && _map[y][x] == 0) {
                //cout << "Start " << x << " " << y << " \n";

                visited[y][x] = 1;
                bfs(x, y);
                cnt++;
            }
        }
    }
}

void input_by_cmd() {
    cin >> m >> n >> k;
    for(int i=0; i<k; i++) {
        cin >> px1 >> py1 >> px2 >> py2;
        
        for(int y=py1; y<py2; y++) {
            for(int x=px1; x<px2; x++) {
                _map[y][x] = 1;
            }
        }
    }
    //printM();
}

void printM() {
    for(int y=0; y<m; y++) {
        for(int x=0; x<n; x++) {
            cout << _map[y][x] << " ";
        }
        cout << "\n";
    }
    cout <<"\n";
}

void output() {
    cout << cnt << "\n";
    sort(area.begin(), area.end(), less<int>());
    for(auto i : area) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input_by_cmd();
    solve();
    output();

    return 0;
}


