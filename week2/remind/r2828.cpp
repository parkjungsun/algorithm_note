/* 백준 2828 |  사과 담기 게임 https://www.acmicpc.net/problem/2828 */

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

int ball[21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, j; // n 스크린, m 바구니, j 사과 개수
    int l, r, tmp, ret = 0;
    cin >> n >> m >> j;

    l = 1;
    for(int i=0; i<j; i++) {
        r = l + m - 1;
        cin >> tmp;
        if(tmp >= l && tmp <= r) continue;
        else {
            if(tmp < l) {
                ret += (l - tmp);
                l = tmp;
            } else {
                l += (tmp - r);
                ret += (tmp - r);
            }
        }
    }

    cout << ret << "\n";

    return 0;
}


