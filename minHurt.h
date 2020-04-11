//
// Created by so_go on 2020/4/7.
//

#ifndef UNTITLED_MINHURT_H
#define UNTITLED_MINHURT_H
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &a, vector<int> &b, vector<bool> &isDefeat, int d, int resCount, int n){
    if(resCount == 0) {
        return 0;
    }
    int res = 0;
    bool isFind = false;
    for(int i = 0; i < n; ++i) {
        if (not isDefeat[i]) {
            if (a[i] < d) {
                isDefeat[i] = true;
                d++;
                resCount--;
                isFind = true;
                continue;
            }
            if (a[i] >= d + resCount) {
                isDefeat[i] = true;
                d++;
                resCount--;
                res += b[i];
                isFind = true;
                continue;
            }
        }
    }

    if(not isFind) {
        int minHurt = INT_MAX, minInd = -1;
        for (int i = 0; i < n; ++i) {
            if (not isDefeat[i]) {
                if (b[i] < minHurt) {
                    minHurt = b[i];
                    minInd = i;
                }
            }
        }
        isDefeat[minInd] = true;
        d++;
        res += minHurt;
        resCount--;
    }
    res += solve(a, b, isDefeat, d, resCount, n);
    return res;
}
int minHurt(){
    int n, D;
    cin >> n >> D;
    vector<int> A, B;
    int a , b;
    for(int i = 0; i < n; ++i){
        cin >> a;
        A.push_back(a);
    }
    for(int i = 0; i < n; ++i){
        cin >> b;
        B.push_back(b);
    }
    vector<bool> isDefeat(n, false);
    cout << solve(A, B, isDefeat, D, n, n) << endl;
    return 0;
}
#endif //UNTITLED_MINHURT_H
