/* 백준 9012 | 괄호 https://www.acmicpc.net/problem/9012 */

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

    int t, re=0;
    cin >> t;

    string tmp;

    for(int i=0; i<t; i++) {
        cin >> tmp;
        re = 0;
        stack<char> s;
        for(int j=0; j<tmp.size(); j++) {
            if(tmp[j] == '(') s.push('(');
            else {
                if(s.empty() || s.top() == ')') {
                    re = 1; break;
                } else {
                    s.pop();
                }
            }
        }
        
        if(re == 0 && s.empty()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}


