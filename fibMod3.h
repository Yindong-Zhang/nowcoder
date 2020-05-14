//
// Created by so_go on 2020/5/6.
//

#ifndef UNTITLED_FIBMOD3_H
#define UNTITLED_FIBMOD3_H
#include<bits/stdc++.h>
using namespace std;

int solve(int a, int b, int N){
//    vector<int> res = {a % 3, b % 3};
    int gi2 = a % 3, gi1 = b % 3, gi;
    int cyc = N;
    for(int i = 2; i <= N; ++i){
        gi = (gi1 + gi2) % 3;
//        res.push_back(gi);
//        if(gi == res[1] and gi1 == res[0]){
//            cyc = i - 1;
//            break;
//        }
        gi2 = gi1;
        gi1 = gi;
        cout << gi << endl;
    }
    return gi;
}

int fibmod3(){
    int T;
    int a, b, n;
    for(int t = 0; t < T; ++t){
        cin >> a >> b >> n;
        if(solve(a, b, n) == 0){
            cout <<  "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
#endif //UNTITLED_FIBMOD3_H
