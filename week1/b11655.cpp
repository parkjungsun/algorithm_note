/* 백준 11655번 | ROT13 https://www.acmicpc.net/problem/11655 */

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

string paragraph;

void solve() {
    char tmp;

    for(int i=0; i<paragraph.size(); i++) {
        tmp = paragraph[i];
        
        if('A' <= tmp && 'Z' >= tmp) {
            tmp += 13;
            if(tmp > 'Z') tmp = tmp - 'Z' + 'A' - 1 ;
        } else if('a' <= tmp && 'z' >= tmp) {
            if(tmp + 13 > 'z') {
                tmp = tmp - 'z' + 'a' - 1 + 13;
            } else {
                tmp += 13;
            }
        }

        paragraph[i] = tmp;
    }
}

void input_by_cmd() {
    getline(cin, paragraph);
}

void input_by_case1() {
    paragraph = "Baekjoon Online Judge";
}

void input_by_case2() {
    paragraph = "One is 1";
}

void output() {
    cout << paragraph << "\n";
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


