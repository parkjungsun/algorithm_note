/* 백준 2559번 | 수열 https://www.acmicpc.net/problem/2559 */

/* 구간 합 문제 */

#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int n, k;
vector<int> temp(100000,0);
vector<int> psum(100000,0);
int result = -99999999;

void solve() {
    // prefix sum
    for(int i=0; i<n; i++) {
        psum[i+1] = psum[i] + temp[i];
    }

    for(int i=k; i<=n; i++) {
        result = max(result, psum[i] - psum[i-k]);
    }
}

void input_by_cmd() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> temp[i];
    }
}

void input_by_case1() {
    n = 10; k = 2;
    temp[0] = 3;
    temp[1] = -2;
    temp[2] = -4;
    temp[3] = -9;
    temp[4] = 0;
    temp[5] = 3;
    temp[6] = 7;
    temp[7] = 13;
    temp[8] = 8;
    temp[9] = -3;
}

void input_by_case2() {
    n = 10; k = 5;
    temp[0] = 3;
    temp[1] = -2;
    temp[2] = -4;
    temp[3] = -9;
    temp[4] = 0;
    temp[5] = 3;
    temp[6] = 7;
    temp[7] = 13;
    temp[8] = 8;
    temp[9] = -3;
}

void output() {
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input_by_cmd();
    //input_by_case1();
    //input_by_case2();
    solve();
    output();

    return 0;
}