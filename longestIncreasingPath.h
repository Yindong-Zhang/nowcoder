//
// Created by so_go on 2020/7/26.
//
/*
 * 329. 矩阵中的最长递增路径

给定一个整数矩阵，找出最长递增路径的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

示例 1:

输入: nums =
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
输出: 4
解释: 最长递增路径为 [1, 2, 6, 9]。

示例 2:

输入: nums =
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
输出: 4
解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。

 */
#ifndef UNTITLED_LONGESTINCREASINGPATH_H
#define UNTITLED_LONGESTINCREASINGPATH_H
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int nrows = matrix.size(), ncols = matrix[0].size();
        bool isChange= true;
        vector<vector<int>> dp(nrows, vector<int>(ncols, 1));
        int res = 1;
        while(isChange){
            isChange= false;
            for(int i = 0; i < nrows; ++i){
                for(int j = 0; j < ncols; ++j){
                    int tmp = INT_MIN;
                    if(i + 1 < nrows  and matrix[i][j] > matrix[i + 1][j]){
                        tmp = max(tmp, dp[i + 1][j]);
                    }
                    if(i - 1 >= 0 and matrix[i][j] > matrix[i - 1][j]){
                        tmp = max(tmp, dp[i - 1][j]);
                    }
                    if(j + 1 < ncols and matrix[i][j] > matrix[i][j + 1]){
                        tmp = max(tmp, dp[i][j + 1]);
                    }
                    if(j - 1 >= 0 and matrix[i][j] > matrix[i][j - 1]){
                        tmp = max(tmp, dp[i][j - 1]);
                    }
                    if(tmp > dp[i][j]){
                        dp[i][j] = tmp;
                        res = max(res, tmp);
                        isChange= true;
                    }
                }
            }

        }
        return res;

    }
};
#endif //UNTITLED_LONGESTINCREASINGPATH_H
