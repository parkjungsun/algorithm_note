/* 백준 1159번 | 농구 경기 https://www.acmicpc.net/problem/1159 */

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

 
int number;
vector<string> player;
vector<int> first(26, 0);

void solve() {
    for(int i=0; i<player.size(); i++) {
        first[player[i][0] - 'a']++;
    }
}

void input_by_cmd() {
    string tmp;
    cin >> number;
    for(int i =0; i < number; i++){
        cin >> tmp;
        player.push_back(tmp);
    }
}

void input_by_case1() {
    number = 18;
    player.push_back("babic");player.push_back("keksic");
    player.push_back("boric");player.push_back("bukic");
    player.push_back("sarmic");player.push_back("balic");
    player.push_back("kruzic");player.push_back("hrenovkic");
    player.push_back("beslic");player.push_back("boksic");
    player.push_back("krafnic");player.push_back("pecivic");
    player.push_back("klavirkovic");player.push_back("kolacic");
    player.push_back("kukumaric");player.push_back("kovacic");
    player.push_back("sunkic");player.push_back("prijestonlonaslijednikovi");
}

void input_by_case2() {
    number = 6;
    player.push_back("michael");player.push_back("jordan");
    player.push_back("lebron");player.push_back("james");
    player.push_back("kobe");player.push_back("bryant");
}

void output() {
    bool result = false;
    for(int i=0; i<26; i++) {
        if(first[i] >= 5) {
            cout << (char)('a' + i);
            result = true;
        }
    }
    if(!result) cout << "PREDAJA";
    cout << "\n";
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