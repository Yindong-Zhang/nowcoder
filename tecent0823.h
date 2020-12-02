//
// Created by so_go on 2020/8/23.
//

#ifndef UNTITLED_TECENT0823_H
#define UNTITLED_TECENT0823_H
#include<bits/stdc++.h>
using namespace std;

double f(int A, int B, int x){
    double res = 0;
    res = res + double(A) * x * x * x / double(3);
    res = res + double(x) * x / double(2);
    res = res + B * x;
    return res;
}
double solve(int A, int B, int C, int D){

    double fD = f(A, B, D);
    double fC = f(A, B, C);
    // cout << fD << ' ' << fC << endl;
    return fD - fC;
}
int tecent0823(){
    int T;
    cin >> T;
    int A, B, C, D;
    for(int t= 0; t < T; ++t){
        cin >> A >> B >> C >> D;
        //cout << A << ' ' << B << ' ' << C << ' ' << D << endl;
        double res = solve(A, B, C, D);
        printf("%.6f", res);
    }
    return 0;
}
#endif //UNTITLED_TECENT0823_H
