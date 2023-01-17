/* 백준 3986 | 좋은 단어 https://www.acmicpc.net/problem/3986 */

#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

/*
    stack을 이용해서 푸는 문제
    -> 1. top() 검사
        1) 현재 값과 동일하면 pop()
        2) 현재 값과 다르면 push()
        3) 비어 있으면 push()
    -> 2. 끝났을 때 size가 0 이면 true
*/

void solve() {
    int n, result = 0;
    string _input;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> _input;
        stack<char> _stack;
        for(int i=0; i<_input.size(); i++) {
            if(_stack.empty()) {
                _stack.push(_input[i]);
            } else
            if(_stack.top() == _input[i]) {
                _stack.pop();
            } else
            if(_stack.top() != _input[i]) {
                _stack.push(_input[i]);
            }
        }
        if(_stack.empty()) result++;
    }
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();

    return 0;
}