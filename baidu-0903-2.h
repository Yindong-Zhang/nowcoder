//
// Created by so_go on 2020/9/3.
//

#ifndef UNTITLED_BAIDU_0903_2_H
#define UNTITLED_BAIDU_0903_2_H
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &boxes, vector<vector<bool>> &isVisited, int i, int j){
    if(i == 0 and j == 0){
        return 0;
    }
    int n = boxes.size();
    int tmp = boxes[i][j];
    int res = 100000;
    isVisited[i][j] = true;
    if( i > 0 and not isVisited[i-1][j]){
        res = min(res, solve(boxes, isVisited, i - 1, j) + abs(tmp - boxes[i-1][j]));
    }
    if( j > 0 and not isVisited[i][j - 1]){
        res = min(res, solve(boxes, isVisited, i, j - 1) + abs(tmp - boxes[i][j- 1]));
    }
    if( i < n - 1 and not isVisited[i + 1][j]){
        res = min(res, solve(boxes, isVisited, i + 1, j) + abs(tmp - boxes[i + 1][j]));
    }
    if( j < n - 1 and not isVisited[i][j + 1]){
        res = min(res, solve(boxes, isVisited, i, j+ 1) + abs(tmp - boxes[i][j + 1]));
    }
    isVisited[i][j]= false;
    cout << i << ' ' << j << ' ' << res << endl;
    return res;
}
int bd_2(){
    int n;
    cin >> n;
    vector<vector<int>> boxes(n, vector<int>(n, 0));
    vector<vector<bool>> isVisit(n, vector<bool>(n, false));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> boxes[i][j];
        }
    }

    cout << solve(boxes, isVisit, n - 1, n - 1);
    return 0;
}
#endif //UNTITLED_BAIDU_0903_2_H
