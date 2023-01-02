/* 백준 10808번 | 알파벳 개수 https://www.acmicpc.net/problem/10808 */

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

vector<int> alphabet(30, 0);
string paragraph;

void solve() {
    for(int i=0; i<paragraph.length(); i++) {
        alphabet[paragraph[i] - 'a']++;
    }
}

void input_by_cmd() {
     getline(cin, paragraph);
}

void input_by_case() {
    paragraph = "backjoon";
}

void output() {
    for(int i=0; i<26; i++) {
        cout << alphabet[i] << " ";
    }
    cout << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //input_by_case();
    input_by_cmd();
    solve();
    output();

    return 0;
}