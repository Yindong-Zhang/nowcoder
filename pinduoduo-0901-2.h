//
// Created by so_go on 2020/9/1.
//

#ifndef UNTITLED_PINDUODUO_0901_2_H
#define UNTITLED_PINDUODUO_0901_2_H
#include<bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> &grids, int n, int m){
    vector<vector<bool>> isVisit(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    int res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grids[i][j] and not isVisit[i][j]){
                q.push({i, j});
                isVisit[i][j] = true;
            }
            int tmp = 0;
            while(not q.empty()){
                auto p = q.front();
                int i = p.first, j = p.second;
                q.pop();
                tmp++;
                if( i < n - 1 and grids[i + 1][j] == 1 and not isVisit[i + 1][j]){
                    q.push({ i + 1, j});
                    isVisit[i + 1][j] = true;
                }
                if( i > 0 and grids[i - 1][j] == 1 and not isVisit[i - 1][j]){
                    q.push({i - 1, j});
                    isVisit[i - 1][j] = true;
                }
                if( j < m - 1 and grids[i][j + 1] == 1 and not isVisit[i][j + 1]){
                    q.push({i, j + 1});
                    isVisit[i][j + 1]= true;
                }
                if(j > 0 and grids[i][j - 1] == 1 and not isVisit[i][j - 1]){
                    q.push({i, j - 1});
                    isVisit[i][j - 1]= true;
                }
            }
            res = max(res, tmp);
        }
    }
    return res;
}
int solve(vector<vector<int>> &grids, int n, int m, int sum){
    int res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grids[i][j] == 0){
                if((i > 0 and grids[i - 1][j]) or (i < n - 1 and grids[i + 1][j]) or (j > 0 and grids[i][j - 1]) or (j < m - 1 and grids[i][j + 1])){
                    grids[i][j] = 1;
                    int tmp = bfs(grids, n, m);
                    if(tmp == sum + 1)
                    {
                        res = max(tmp - 1, res);
                    }
                    else{
                        res = max(tmp, res);
                    }
//                    cout << i << ' ' << j << ' ' << tmp << endl;
                    grids[i][j] = 0;
                }
            }
        }
    }
    return res;
}
int pinduoduo_2(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grids(n, vector<int>(m, 0));
    int sum = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grids[i][j];
            sum += grids[i][j];
        }
    }
    cout << solve(grids, n, m, sum) << endl;
    return 0;
}
#endif //UNTITLED_PINDUODUO_0901_2_H
