/* 백준 9996번 | 한국이 그리울 땐 서버에 접속하지  https://www.acmicpc.net/problem/9996 */

#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int n;
string pattern;
vector<string> words;
vector<string> result;

void solve() {

    int pos = pattern.find('*');
    string pre = pattern.substr(0, pos);
    string suf = pattern.substr(pos + 1);

    for(int i=0; i<n; i++) {
        if(pre.size() + suf.size() > words[i].size()) {
            result.push_back("NE");
        } else {
            if(pre == words[i].substr(0, pre.size()) && suf == words[i].substr(words[i].size() - suf.size())) 
                result.push_back("DA");
            else
                result.push_back("NE");
        }
    }
}

void input_by_cmd() {
    string tmp;

    cin >> n;
    cin >> pattern;
    for(int i=0; i < n; i++) {
        cin >> tmp;
        words.push_back(tmp);
    }
}

void input_by_case1() {
    n = 3;
    pattern = "a*d";
    words.push_back("abcd");
    words.push_back("anestonestod");
    words.push_back("facebook");
}

void input_by_case2() {
    n = 6;
    pattern = "h*n";
    words.push_back("huhovdjestvarnomozedocisvastan");
    words.push_back("honijezakon");
    words.push_back("atila");
    words.push_back("je");
    words.push_back("bio");
    words.push_back("hun");
}

void output() {
    for(int i=0; i<n ;i++) {
        cout << result[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //input_by_case1();
    //input_by_case2();
    input_by_cmd();
    solve();
    output();

    return 0;
}