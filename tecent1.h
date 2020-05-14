//
// Created by so_go on 2020/4/26.
//

#ifndef UNTITLED_TECENT1_H
#define UNTITLED_TECENT1_H

#include <bits/stdc++.h>
using namespace std;

int tecent1(){
    int n, m;
    int ci, wi;
    cin >> n >> m;
    float res = 0;
    for(int i = 0; i < n; ++i){
        cin >> ci >> wi;
        if(float(ci) / m <= wi){
            res += (wi - float(ci) / m);
        }
    }
    long long ret = ceil(res);
    cout << ret << endl;
    return 0;
}
#endif //UNTITLED_TECENT1_H
