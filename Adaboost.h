//
// Created by so_go on 2020/4/11.
//
// 网易互娱第一题
#ifndef UNTITLED_ADABOOST_H
#define UNTITLED_ADABOOST_H
#include<bits/stdc++.h>
#include<cmath>
#include"printVector.h"
using namespace std;


int sign(double m){
    if(m >= 0){
        return 1;
    }
    return -1;
}


void solve(vector<vector<int>> &train, vector<int> &label, vector<vector<int>> &test,int M, int N, int K){
    vector<float> weight(N, 1. / N);
    vector<double> A;
    for(int m = 0; m < M; ++m){
        double e = 0;
        double a;
        for(int i = 0; i < N; ++i){
            if(label[i] != train[m][i]){
                e += weight[i];
            }
        }
        if(e == 0){
            a = 1;
        }
        else if(e == 1){
            a = 0;
        }
        else{
            a = 1. / 2 * log( ( 1 - e ) / e );
        }
        A.push_back(a);

        for(int i = 0; i < N; ++i){
            weight[i] = weight[i] * exp( -a * label[i] * train[m][i]);
        }
        double w_sum = 0;
        for(int i = 0; i < N; ++i){
            w_sum += weight[i];
        }
        for(int i = 0; i < N; ++i){
            weight[i] /= w_sum;
        }
    }
//    printVector(A);
    for(int k = 0; k < K; ++k){
        double p = 0;
        for(int m = 0; m < M; ++m){
            p += A[m] * test[k][m];
        }
        cout << sign(p) << endl;
    }
}

int adaboost(){
    int N, M, K;
    cin >> M >> N >> K;
    vector<vector<int>> G(M, vector<int>(N, 0));
    vector<int> l(N, 0);
    vector<vector<int>> T(K, vector<int>(M, 0));
    for(int i = 0; i < N; ++i){
        cin >> l[i];
    }
    for(int m = 0; m < M; ++m){
        for(int i = 0; i < N; ++i){
            cin >> G[m][i];
        }
    }
    for(int k = 0; k < K; ++k){
        for(int m = 0; m < M; ++m){
            cin >> T[k][m];
        }
    }
    solve(G, l, T, M, N, K);
    return 0;
}
#endif //UNTITLED_ADABOOST_H
