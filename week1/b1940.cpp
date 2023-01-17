/* 백준 1940 | 주몽 https://www.acmicpc.net/problem/1940 */

#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> _vec;

void solve() {
    cin >> n;
    cin >> m;
    int tmp, front, rear;
    int result =0;

    for(int i=0; i<n; i++) {
        cin >> tmp;
        _vec.push_back(tmp);
    }
    sort(_vec.begin(),_vec.end(), less<int>());
    
    front = 0;
    rear = _vec.size() - 1;

    while(!(front == rear || front > rear))  {
        tmp = _vec[front]+_vec[rear];
        if(tmp == m) {
            result++;
            front++;
            rear--;
        }
        if(tmp > m) rear--;
        if(tmp < m) front++;
    }

    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();

    return 0;
}