//
// Created by so_go on 2020/4/26.
//

#ifndef UNTITLED_TENCENT3_H
#define UNTITLED_TENCENT3_H
#include<bits/stdc++.h>
#define M 100003
using namespace std;
typedef long long ll;
ll kuaisumi(int m, int k){
    if(k == 0){
        return 1;
    }
    ll tmp = kuaisumi(m, k / 2);
    ll res = (tmp * tmp ) % M;
    if( k % 2 == 1){
        res = (res * m) % M;
    }
    return res;
}

ll solve(int n, int m){
    ll res = kuaisumi(m - 1, n - 1);
    res = (res * m ) % M;
    ll je = kuaisumi(m, n);
    if(je < res){
        je = je + M;
    }
    return je - res;
}



int tecent3(){
    int n, m;
    cin >> m >> n;
    cout << (-100 % M);
    return 0;
}
#endif //UNTITLED_TENCENT3_H
