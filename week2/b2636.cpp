/* 백준 2636 | 치즈 https://www.acmicpc.net/problem/2636 */

/* 
*/

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

int dx = { -1, 0, 1, 0 };
int dy = { 0, 1, 0, -1 };

int time, cheeze;

int _map[104][104] = { 0, };
int visited[104][104] = { 0, };

vector<pair<int,int>> v;

void bfs(int y, int x) {
	visited[y][x] = 1;
    if(_map[y][x]==1){
        v.push_back({y,x});
        return;
    }
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx])continue; 
        bfs(ny,nx);
    }
    return;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int h, w;
    cin >> h >> w;
    
    for(int i=0; i<h; i++) {  
        for(int j=0; j<w; j++) {
            cin >> _map[h][w];
        }
    }

    while(1) {
        cheeze = 0;
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);

        v.clear();
        bfs(0,0);

        for(pair<int, int> b : v){
			cnt2++;
			a[b.first][b.second] = 0;
		}   

        bool chk = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(_map[i][j] != 0) chk = 1;
            }
        }

        time++;
        if(!chk) break;
    }
    cout << time << "\n" << cheeze << "\n";

    return 0;
}


