/* 백준 2910 | 빈도 정렬 https://www.acmicpc.net/problem/2910 */

/* 
*/

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

int n, c;
map<int, int> _map;
vector<pair<int,int>> arr;
int seq[1004]; 

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.second != b.second) return a.second > b.second;
    else return seq[a.first] < seq[b.first];
}

void input_by_cmd() {
    int tmp;
    cin >> n >> c;
    for(int i=0; i<n; i++) {
        cin >> tmp;
        seq[i] = tmp;
        if(_map.find(tmp) == _map.end()) {
            _map[tmp] = 0;
            seq[tmp] = i;
        }
        _map[tmp]++;
    }
    for(auto i : _map) {
        arr.push_back({i.first, i.second});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input_by_cmd();

    sort(arr.begin(), arr.end(), cmp);

    for(auto i : arr) {
        for(int j=0;j<i.second;j++) {
            cout << i.first << " ";
        }
    }
    cout << "\n";

    return 0;
}


