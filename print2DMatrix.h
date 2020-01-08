//
// Created by LCY on 2019/10/14.
//
/*
 * 题目描述
给定一个空的int类型的二维数组array[n][m]。
按下面的填充规则, 请编写一个函数将此二维数组填满并打印出来.

输入描述:
输入的包括两个正整数，表示二维数组的大小n，m(1 <= n, m <= 10)。
输出描述:
打印结果，每行行末无空格。
示例1
输入
复制
4 4
输出
复制
1 2 4 7
3 5 8 11
6 9 12 14
10 13 15 16
 */
#ifndef UNTITLED_PRINT2DMATRIX_H
#define UNTITLED_PRINT2DMATRIX_H
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

void solve(int m, int n){
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    int i = 0, j = 0;
    int sum = 0;
    for(int k = 1; k <= m * n; k++){
        matrix[i][j] = k;
        if((i == m - 1 )or (j == 0)){
            sum = i + j + 1;
            j = min(sum, n - 1);
            i = sum - j;
        }
        else{
            i = i + 1;
            j = j - 1;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

}

int print2DMatrix(){
    int m, n;
    cin >> m >> n;
    solve(m, n);
    return 0;
}
#endif //UNTITLED_PRINT2DMATRIX_H
