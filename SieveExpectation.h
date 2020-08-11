//
// Created by so_go on 2020/8/12.
//
/*
 *

扔n个骰子，第i个骰子有可能投掷出Xi种等概率的不同的结果，数字从1到Xi。所有骰子的结果的最大值将作为最终结果。求最终结果的期望。


输入描述:

第一行一个整数n，表示有n个骰子。（1 <= n <= 50）
第二行n个整数，表示每个骰子的结果数Xi。(2 <= Xi <= 50)


输出描述:

输出最终结果的期望，保留两位小数。


输入例子1:

2
2 2


输出例子1:

1.75


 */
#ifndef UNTITLED_SIEVEEXPECTATION_H
#define UNTITLED_SIEVEEXPECTATION_H
#include<bits/stdc++.h>
using namespace std;

double solve(vector<int> &X, int N){
    int mX = *max_element(X.begin(), X.end());
    vector<double> P(mX + 1, 0);
    for(int i = 1; i <= mX; ++i){
        double pi = 1;
        for(int j = 0; j < N; ++j){
            if(i <= X[j]){
                pi *= double(i) / X[j];
            }
        }
        P[i] = pi;
    }
    double res = 0;
    for(int i = 1; i <= mX; ++i){
        res += i * (P[i] - P[i - 1]);
    }
    return res;
}
int sieveExpectation(){
    int n;
    cin >> n;
    vector<int> X(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> X[i];
    }
    double res= solve(X, n);
    printf("%.2f", res);
    return 0;
}
#endif //UNTITLED_SIEVEEXPECTATION_H
