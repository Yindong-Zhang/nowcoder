//
// Created by so_go on 2020/5/6.
//

#ifndef UNTITLED_ADDTOUNIQUE_H
#define UNTITLED_ADDTOUNIQUE_H
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(vector<int> A){
    sort(A.begin(), A.end());
    ll res = 0;
    for(int i = 1; i < A.size(); ++i){
        if(A[i] <= A[i - 1]){
            res += A[i - 1] + 1 - A[i];
            A[i] = A[i - 1] + 1;
        }
    }
    return res;
}

int addToUnique(){
    int n;
    cin >> n;
    vector<int> A(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> A[i];
    }
    cout << solve(A) << endl;
    return 0;
}
#endif //UNTITLED_ADDTOUNIQUE_H
