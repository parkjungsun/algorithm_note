/* 백준 2828 | 사과 담기 게임 https://www.acmicpc.net/problem/2828 */

/* 
    1. 처음 시작 위치 정하기
       1) 모든 바구니의 수
    2. 움직인 거리 구하기
       1) 바구니의 오른쪽 끝과 왼쪽 끝 사이에 공이 있으면 성공 
*/

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

int n, m, j;
int ball[21];
vector<pair<int,int>> point;

int solve(int lx, int rx) {
    int move = 0;
    int t, nb;
    for(int i=0; i<j; i++) {
        nb = ball[i];
        // 범위내에 있으면 통과
        if(nb >= lx && nb <= rx) continue;
        // 왼쪽에 있을때
        if(nb < lx) {
            t = (lx - nb); 
            lx -= t;
            rx -= t;
        }
        // 오른쪽에 있을 때
        if(nb > rx) {
            t = (nb - rx);
            lx += t;
            rx += t;
        }
        move += t;
    }
    return move;
}

void firstPoint() {
    int fix = ball[0];
    int term = m - 1;
    for(int i = fix - term; i <= fix + term; i++) {
        if(i <= 0 || i > n) continue;
        point.push_back({i, i + term});
    }
} 

void input_by_cmd() {
    cin >> n >> m;
    cin >> j;
    for(int i=1; i<=j; i++) {
        cin >> ball[i-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int q, qq;
    int result = 9999;
    input_by_cmd();
    firstPoint();
    for(int i=0; i<point.size(); i++) {
        tie(q, qq) = point[i];
        result = min(solve(q,qq), result);
    }
    cout << result << "\n";
    return 0;
}


