/* 백준 4949 | 균형잡힌 세상 https://www.acmicpc.net/problem/4949 */

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
    
    string para;

    while(1) {
        stack<char> s;
        getline(cin, para);
        if(para.size() == 1 && para[0] == '.') break;
        for(int i=0; i<para.size(); i++) {
            if(para[i] == '(' || para[i] == '[') s.push(para[i]);
            if(para[i] == ')') {
                if(!s.empty() && s.top() == '(') s.pop();
                else s.push(para[i]);
            }
            if(para[i] == ']') {
                if(!s.empty() && s.top() == '[') s.pop();
                else s.push(para[i]);
            } 
        }
        if(s.empty()) cout << "yes" << "\n";
        else cout << "no" << "\n"; 
    }

    return 0;
}


