/* 백준 2870 | 수학 숙제 https://www.acmicpc.net/problem/2870 */

/* 
*/

#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;

vector<int> result;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string word;
        string tmp = "";
        cin >> word;
        for(int j=0; j<word.size(); j++) {
            if(word[j] < 65) tmp += word[j];
            else {
                if(tmp != "") {
                    result.push_back(stoi(tmp));
                }
                tmp = "";
            }
        }
        if(tmp != "") result.push_back(stoi(tmp));
    }

    sort(result.begin(), result.end(), less<int>());
    for(auto i : result) cout << i << "\n";

    return 0;
}


