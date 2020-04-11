//
// Created by so_go on 2020/4/7.
//

#ifndef UNTITLED_SEATCOMBINATION_H
#define UNTITLED_SEATCOMBINATION_H

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &res, vector<bool> &isUsed, vector<set<int>> &Bad, vector<int> &cur, int count, int n){
//    for(int i = 0; i < cur.size(); ++i){
//        cout << cur[i] << ' ';
//    }
//    cout << endl;
    if(count == n){
        res.push_back(cur);
    }
    for(int i = 0; i < n; ++i){
        if(isUsed[i]){
            continue;
        }
        if(count > 0 and Bad[cur[count - 1]].find(i)!= Bad[cur[count - 1]].end()){
            continue;
        }

        cur.push_back(i);
        isUsed[i] = true;
        count++;
        dfs(res, isUsed, Bad, cur, count, n);
        cur.pop_back();
        isUsed[i] = false;
        count--;
    }
}

vector<vector<int>> solve(int n, vector<set<int>> Bad){
    vector<vector<int>> res;
    vector<bool> isUsed(n, false);
    vector<int> cur;
    int count = 0;
    dfs(res, isUsed, Bad, cur, count, n);
    return res;
}
int seatCombination(){
    int n, k;
    cin >> n >> k;
    vector<set<int>> Bad(n);
    int a, b;
    for(int i = 0; i < k; ++i){
        cin >> a >> b;
        Bad[a - 1].insert(b - 1);
        Bad[b - 1].insert(a - 1);
    }
    auto res = solve(n, Bad);
    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < res[i].size(); ++j){
            cout << res[i][j] + 1<< ' ';
        }
        cout << endl;
    }
    return 0;
}
#endif //UNTITLED_SEATCOMBINATION_H
