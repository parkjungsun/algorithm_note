/* 백준 1992 |  쿼드 트리 https://www.acmicpc.net/problem/1992 */

/* 
    0000 -> 0
    1111 -> 1
    abcd -> abcd
*/

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

char _map[70][70];

string solve(int y, int x, int size) {
    if(size == 1) return string(1, _map[y][x]);

    char tmp = _map[y][x];
    string result = "";

    for(int i=y;i<y+size;i++) {
        for(int j=x;j<x+size;j++) {
            if(tmp != _map[i][j]) {
                result += "(";
                result += solve(y, x, size / 2);
                result += solve(y, x + size / 2, size / 2);
                result += solve(y + size / 2, x, size / 2);
                result += solve(y + size / 2, x + size / 2, size / 2);
                result += ")";
                return result;
            }
        }
    }

    return string(1, _map[y][x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    for(int i=0; i<n; i++) {
        string s;
        getline(cin, s);

        for(int j=0; j<n; j++) {
            _map[i][j] = s[j];    
        }
    }
    
    cout << solve(0, 0, n) << "\n";

    return 0;
}


