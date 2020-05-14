//
// Created by so_go on 2020/4/29.
//

#ifndef UNTITLED_HUAWEI3_H
#define UNTITLED_HUAWEI3_H
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Road{
    int s;
    int d;
    int l;
    int t;

};
ll dfs(int i, int k, vector<vector<Road>> &R, vector<bool> &isVisit){
    if(i == 0){
        return 0;
    }
    ll res = LONG_LONG_MAX;
    for(Road &r: R[i]){
        int s = r.s;
        if(not isVisit[s] and k - r.t >= 0){
            isVisit[s] = true;
            ll tmp = dfs(s, k - r.t, R, isVisit);
            if(tmp != LLONG_MAX){
                res = min(res, tmp + r.l);
            }
            isVisit[s] = false;
        }
    }
    return res;
}

ll solve(vector<vector<Road>> &R, int k, int n){
    vector<bool> isVisit(n, false);
    ll res = dfs(n - 1, k, R, isVisit);
    if(res == LLONG_MAX){
        return -1;
    }
    return res;
}



int constraintShortestPath(){
    int k, n, r;
    cin >> k >> n >> r;
    vector<vector<Road>> R(n);
    int s, d, l, t;
    for(int i = 0; i < r; ++i){
        cin >> s >> d >> l >> t;
        R[d - 1].push_back(Road{s - 1, d - 1, l, t});
    }
    cout << solve(R, k, n);
}
#endif //UNTITLED_HUAWEI3_H
