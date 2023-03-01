/* 백준 10709 |  기상캐스터 https://www.acmicpc.net/problem/10709 */

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string line;
    int h, w, c;
    cin >> h >> w;

    for(int i=0; i<h; i++) {
        cin >> line;
        c = -1;
        for(int j=0; j<w; j++) {
            if(line[j] == 'c') {
                c = 0;
            } else {
                if(c != -1) c++;
            }
            cout << c << " ";
        }
        cout << "\n";
    }

    return 0;
}


