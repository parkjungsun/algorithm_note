/* 백준 10988번 | 팰린드롬인지 확인하기 https://www.acmicpc.net/problem/10988 */

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

string paragraph;
bool result = true;

void solve() {
    int n = paragraph.size();
    for(int i=0; i < n / 2; i++) {
        if(paragraph[i] != paragraph[n-i-1]) {
            result = false;
            return;
        }
    }
}

void input_by_cmd() {
    getline(cin, paragraph);
}

void input_by_case1() {
    paragraph = "level";
}

void input_by_case2() {
    paragraph = "baekjoon";
}

void output() {
    if(result) cout << 1 << "\n";
    else cout << 0 << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input_by_cmd();
    //input_by_case1();
    //input_by_case2();
    solve();
    output();

    return 0;
}