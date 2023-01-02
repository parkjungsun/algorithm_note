/* 백준 2979 | 트럭 주차 https://www.acmicpc.net/problem/2979 */

/*
    주차 시간
    - 1분 ~ 100분

    가격표
    - A * 1 : 1대 가격 
    - B * 2: 2대 가격
    - C * 3: 3대 가격
*/

#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

int A, B, C;
int price = 0;
vector<int> timeLine(101, 0);

void solve() {
    for(int i=0; i < timeLine.size(); i++) {
        if(timeLine[i] == 0) { continue; }
        if(timeLine[i] == 1) { price += (A * 1); }
        if(timeLine[i] == 2) { price += (B * 2);}
        if(timeLine[i] == 3) { price += (C * 3);}
    }
}

void input_by_cmd() {
    int s, e;
    cin >> A >> B >> C;
    for(int i=0; i<3; i++) {
        cin >> s >> e;
        for(int j = s; j < e; j++) {
            timeLine[j]++;
        }
    }
}

void input_by_auto1() {
    A = 5; B = 3; C = 1;
    for(int j = 1; j < 6; j++) {
        timeLine[j]++;
    }
    for(int j = 3; j < 5; j++) {
        timeLine[j]++;
    }
    for(int j = 2; j < 8; j++) {
        timeLine[j]++;
    }
}

void input_by_auto2() {
    A = 10; B = 8; C = 6;
    for(int j = 15; j < 30; j++) {
        timeLine[j]++;
    }
    for(int j = 25; j < 50; j++) {
        timeLine[j]++;
    }
    for(int j = 70; j < 80; j++) {
        timeLine[j]++;
    }
}

void output() {
    cout << price << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //input_by_auto1();
    //input_by_auto2();
    input_by_cmd();
    solve();
    output();

    return 0;
}