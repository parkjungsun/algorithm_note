/* 백준 2309번 | 일곱 난쟁이 https://www.acmicpc.net/problem/2309 */

/*
    9C7 조합문제
    - break 조건 : sum = 100
*/

#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

vector<int> people;

void solve_by_combi() {
    sort(people.begin(), people.end(), less<int>());

    int sum = 0;
    for(int i=0; i < 9; i++) {
        sum += people[i];
    }

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < i; j++) {
            if(sum - people[i] - people[j] == 100) {
                for(int k=0; k < 9; k++) {
                    if(k == i || k == j) continue;
                    cout << people[k] << "\n";
                }
                exit(0);
            }
        }
    }
}

void solve_by_permutation() {
    sort(people.begin(), people.end(), less<int>());
    do {
        if(accumulate(people.begin(), people.begin() + 7, 0) == 100) {
            for(int i=0; i<7; i++) cout << people[i] << "\n"; 
            break;
        }
    } while(next_permutation(people.begin(), people.end()));
}

void input_by_cmd() {
    int n;
    for(int i=0; i < 9; i++) {
        cin >> n;
        people.push_back(n);
    }
}

void input_by_auto() {
    people.push_back(20);
    people.push_back(7);
    people.push_back(23);
    people.push_back(19);
    people.push_back(10);
    people.push_back(15);
    people.push_back(25);
    people.push_back(8);
    people.push_back(13);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //input_by_auto();
    input_by_cmd();

    //solve_by_permutation();
    solve_by_combi();

    return 0;
}