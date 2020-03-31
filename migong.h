//
// Created by so_go on 2020/3/23.
//
// 阿里巴巴笔试第二道
#ifndef UNTITLED_MIGONG_H
#define UNTITLED_MIGONG_H
#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<vector<int>>> &dp, vector<vector<char>> p, int i, int j, int k, int m, int n){
    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }
    else{
        int res = INT_MAX;
        if(i - 1 >= 0 and j - 1 >= 0){
            res = min(res, dfs(dp, p, i - 1, j - 1, k, m, n) + 1);
        }
        if( i - 1 >= 0 and j + 1 < m){
            res = min(res, dfs(dp, p, i - 1, j + 1, k, m, n) + 1);
        }
        if( i + 1 < n and j + 1 < m){
            res = min(res, dfs(dp, p, i + 1, j + 1, k, m, n) + 1);
        }
        if( i + 1 < n and j - 1 >= 0){
            res = min(res, dfs(dp, p, i + 1, j - 1, k, m, n) + 1);
        }
        if( p[n + 1 - i][m + 1 - j] != '#'){
            res = min(res, dfs(dp, p, n + 1 - i, m + 1 - j, k - 1, m, n) + 1);
        }
        dp[i][j][k] = res;
        return res;
    }
}

int solve(vector<vector<char>> &p, int si, int sj, int ei, int ej){
    vector<vector<vector<int>>> dp(p.size(), vector<vector<int>>(p[0].size(), vector<int>(5, INT_MAX)));
    dp[si][sj][0] = 0;
    int res = INT_MAX;
    for(int i = 0; i < 5; ++i){
        dfs(dp, p, ei, ej, i, p[0].size(), p.size());
        res = min(res, dp[ei][ej][i]);
    }
    return res;
}
int main(){
    int m, n;
    cin >> n >> m;
    vector<vector<char>> p(n, vector<char>(m, ' ' ));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char c;
            cin >> c ;
            p[i][j]= c;
            if
        }
    }
    solve(p, )
}
#endif //UNTITLED_MIGONG_H
