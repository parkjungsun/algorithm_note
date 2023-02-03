/* 백준 1436 | 영화감독 숌 https://www.acmicpc.net/problem/1436 */

/* 
    1) 1
    2) 1 + 1 ~ (1 + 19)  //  2 ~ 380
    3) (1 + 19) * 19 + 1 ~ ((1 + 19) * 19 + 1) * 19 //  381 ~ 7239
    4) 7239 ~ 10000
*/

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int s = 666;
    while(1) {
        if(to_string(s).find("666") != string::npos) n--;
        if(n == 0) break;
        s++;
    }
    cout << s << "\n";

    return 0;
}


