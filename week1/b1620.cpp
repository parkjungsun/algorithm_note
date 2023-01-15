/* 백준 1620번 | 나는야 포켓몬 마스터 이다솜 https://www.acmicpc.net/problem/1620 */

/*
    100,000 >= n, m >=1
    20 >= name[A-Za-z] >=2
*/

#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<string> poketmon;
map<int, string> dict_idx;
map<string, int> dict_nm;
vector<string> aaa = {"25", "Raichu", "3", "Pidgey", "Kakuna"};

void solve() {
    for(int i=0; i<poketmon.size(); i++) {
        dict_idx[i+1] = poketmon[i];
        dict_nm[poketmon[i]] = i+1;
    }
    string quest;
    for(int i=0;i<m;i++) {
        cin >> quest;
        if(atoi(quest.c_str()) == 0) {
            cout << dict_nm[quest] << "\n";
        } else {
            cout << dict_idx[atoi(quest.c_str())] << "\n";
        }
    }
}

void input_by_cmd() {
    string tmp;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> tmp;
        poketmon.push_back(tmp);
    }
    solve();
}

void solve_case() {
    for(int i=0; i<poketmon.size(); i++) {
        dict_idx[i+1] = poketmon[i];
        dict_nm[poketmon[i]] = i+1;
    }
    string quest;
    for(int i=0;i<m;i++) {
        quest = aaa[i];
        if(atoi(quest.c_str()) == 0) {
            cout << dict_nm[quest] << "\n";
        } else {
            cout << dict_idx[atoi(quest.c_str())] << "\n";
        }
    }
}

void input_by_case() {
    n = 26; m = 5;
    poketmon.push_back("Bulbasaur");
    poketmon.push_back("Ivysaur");
    poketmon.push_back("Venusaur");
    poketmon.push_back("Charmander");
    poketmon.push_back("Charmeleon");
    poketmon.push_back("Charizard");
    poketmon.push_back("Squirtle");
    poketmon.push_back("Wartortle");
    poketmon.push_back("Blastoise");
    poketmon.push_back("Caterpie");
    poketmon.push_back("Metapod");
    poketmon.push_back("Butterfree");
    poketmon.push_back("Weedle");
    poketmon.push_back("Kakuna");
    poketmon.push_back("Beedrill");
    poketmon.push_back("Pidgey");
    poketmon.push_back("Pidgeotto");
    poketmon.push_back("Pidgeot");
    poketmon.push_back("Rattata");
    poketmon.push_back("Raticate");
    poketmon.push_back("Spearow");
    poketmon.push_back("Fearow");
    poketmon.push_back("Ekans");
    poketmon.push_back("Arbok");
    poketmon.push_back("Pikachu");
    poketmon.push_back("Raichu");
    solve_case();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //input_by_case();
    input_by_cmd();

    return 0;
}