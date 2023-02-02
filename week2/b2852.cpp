/* 백준 2852 | 비밀번호 발음하기 https://www.acmicpc.net/problem/2852 */

/* 
    48분 -> 2880초
    [input]
    - 개수
    - 1 20:00
    [output]
    - 1 team 시간
    - 2 team 시간
*/

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

int caltm(string tmi) {
    int i = tmi.find(':');
    cout << tmi.substr(0,i) << "\n";
    tmi.erase(0, i + 1);
    cout << tmi << "\n";

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;

    int win = 0, nxt = 0;
    int team[3] = { 0, };/* nteam 0, ateam 1, bteam 2 */
    string tmi;
    for(int i=0; i< T; i++) {
        cin >> nxt;
        cin >> tmi;

        team[win] += caltm(tmi);
        win = nxt;
    }
    team[win] += caltm("48:00");

    cout << team[1] << '\n';
    cout << team[2] << '\n';

    return 0;
}


