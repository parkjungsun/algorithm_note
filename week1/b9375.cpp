/* 백준 9375 | 패션왕 신해빈 https://www.acmicpc.net/problem/9375 */

#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int n, m;
string gd_nm, gd_knd;

void solve() {
    cin >> n;

    for(int i=0; i<n; i++) {
        map<string, int> _map;
        cin >> m;

        for(int i=0; i<m; i++) {
            cin >> gd_nm >> gd_knd;
            if(_map.find(gd_knd) == _map.end()) {
                _map[gd_knd] = 1;
            } else {
                _map[gd_knd]++;
            }
        }
        
        long long result = 1;
        for(auto i : _map) {
            result *= ((long long)i.second + 1);
        }

        result--;
        cout << result << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();

    return 0;
}