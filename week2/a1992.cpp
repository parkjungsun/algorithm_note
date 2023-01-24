/* 백준 1992 |  쿼드 트리 https://www.acmicpc.net/problem/1992 */

/* 
    재귀함수 이용 (큰 -> 좁은)
*/

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

int n;
char _map[70][70];

string solve(int y, int x, int size) {
    if(size == 1) return string(1, _map[y][x]);

    char b = _map[y][x];
    string ret = "";

    for(int i=y; i<y+size; i++) {
        for(int j=x; j<x+size; j++) {
            if(b != _map[i][j]) {
                ret += '(';
                ret += solve(y, x, size / 2); 
                ret += solve(y, x + size / 2, size / 2);
                ret += solve(y + size / 2, x, size / 2);
                ret += solve(y + size / 2, x + size / 2, size / 2); 
                ret += ')';
                return ret; 
            }
        }
    }
    return string(1, _map[y][x]);
}

void input_by_cmd() {
    cin >> n;
    for(int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        for(int j=0; j<n; j++) {
            _map[i][j] = tmp[j];
        }
    }    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input_by_cmd();
    cout << solve(0,0,n) << "\n";

    return 0;
}


