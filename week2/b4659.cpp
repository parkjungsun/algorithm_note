/* 백준 4659 | 비밀번호 발음하기 https://www.acmicpc.net/problem/4659 */

/* 
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

    string test_word;
    string mo = "aeiou";
    while(1) {
        cin >> test_word;
        if(test_word == "end") return 0;

        int chk = 0;
        int cnt = 0;            // 모음 개수
        int m = 0;              // 모음 연속 개수
        int j = 0;              // 자음 연속 개수
        char prev = 'A';              // 이전 단어 check
        for(int i=0; i<test_word.size(); i++) {
            if(mo.find(test_word[i]) != string::npos) {
                // 모음일 경우
                cnt++; m++; j=0;
            } else {
                // 자음일 경우
                m=0; j++;
            }

            if(m == 3 || j == 3 || 
                (prev == test_word[i] && 'e' != test_word[i] && 'o' != test_word[i])) {
                chk = 1;
                break;
            }
            prev = test_word[i];
        }
        if(cnt == 0 || chk == 1) {
            cout << "<" << test_word << "> is not acceptable." << "\n";
        } else {
            cout << "<" << test_word << "> is acceptable." << "\n";    
        }
    }

    return 0;
}


