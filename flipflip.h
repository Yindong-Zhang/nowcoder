//
// Created by LCY on 2019/10/16.
//
/*
 * 题目描述
给定一个N*M的矩阵，在矩阵中每一块有一张牌，我们假定刚开始的时候所有牌的牌面向上。
现在对于每个块进行如下操作：
> 翻转某个块中的牌，并且与之相邻的其余八张牌也会被翻转。
XXX
XXX
XXX
如上矩阵所示，翻转中间那块时，这九块中的牌都会被翻转一次。
请输出在对矩阵中每一块进行如上操作以后，牌面向下的块的个数。
输入描述:
输入的第一行为测试用例数t(1 <= t <= 100000),
接下来t行，每行包含两个整数N,M(1 <= N, M <= 1,000,000,000)
输出描述:
对于每个用例输出包含一行，输出牌面向下的块的个数
示例1
输入
复制
5 1 1 1 2 3 1 4 1 2 2
输出
复制
1 0 1 2 0
 */
#ifndef UNTITLED_FLIPFLIP_H
#define UNTITLED_FLIPFLIP_H
#include<algorithm>
#include<iostream>
using namespace std;
// 超时。。。
/*
int solve(int m, int n){
    int res = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if( (min(j + 1, n - 1) - max(j - 1, 0)) % 2 == 0 and (min(i + 1, m - 1) - max( i - 1, 0)) % 2 == 0){
                res++;
            }
        }
    }
    return res;
}
*/

int project(int n){
    if(n == 1){
        return 1;
    }
    else{
        return n - 2;
    }
}
int solve(int m, int n){
//    TODO:
    int nrows, ncols;
    if(m == 1){

    }
}

int flipflip(){
    int n_sample;
    cin >> n_sample;
    int m, n;
    for(int i = 0; i < n_sample; i++){
        cin >> m >> n;
        cout << solve(m, n) << endl;
    }
    return 0;
}
#endif //UNTITLED_FLIPFLIP_H
