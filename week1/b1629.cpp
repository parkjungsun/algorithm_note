/* 백준 1629 | 곱셈 https://www.acmicpc.net/problem/1629 */

#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

/* 
    제곱으로 가야할듯
*/

long long a, b, c;

long long solve(long long a, long long b) {
    if(b == 1) return a % c;
    long long result = solve(a, b / 2);

    result = (result * result) % c;
    if(b % 2) result = (result * a) % c;

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c;

    cout << solve(a, b) << "\n";

    return 0;
}