//
// Created by so_go on 2020/3/23.
//

#ifndef UNTITLED_COMBINATIONCOUNT_H
#define UNTITLED_COMBINATIONCOUNT_H
#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long ll;

ll solve(int n){
    ll k = 1;
    for(int i = 0; i < n - 1; ++i){
        k = 2 * k % M;
    }
    ll res = 0;
    for(int j = 0; j < n; ++j){
        res = (res + k ) % M;
    }
    return res;
}
int combinationCount(){
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif //UNTITLED_COMBINATIONCOUNT_H
