//
// Created by so_go on 2020/8/13.
//

#ifndef UNTITLED_CONSEQUENTPRIME_H
#define UNTITLED_CONSEQUENTPRIME_H
#include<bits/stdc++.h>
#include"printVector.h"
using namespace std;

int solve(int n){
    vector<int> isNorm(n + 1, 0);
    for(int i = 2; i <= n; ++i){
        if(isNorm[i] == 0){
            for(int k = 2; k * i <= n; ++k){
                isNorm[k * i] = 1;
            }
        }
    }
    vector<int> primes;
    for(int i = 2; i <= n; ++i){
        if(isNorm[i] == 0){
            primes.push_back(i);
        }
    }
    printVector(primes);
    int res = 0;
    int left = 0, right = 0;
    int tmp = primes[0];
    int nP = primes.size();
//    for(int i = 0; i < nP; ++i){
//        int tmp = primes[i];
//        for(int j = i + 1; j < nP; ++j){
//            tmp += primes[j];
//            if(tmp >= n){
//                break;
//            }
//        }
//        if(tmp == n){
//            res++;
//        }
//    }
    while(right < nP){
        cout << left << ' ' << right << endl;
        while(right < nP and tmp < n){
            right++;
            tmp += primes[right];
        }
        if(tmp == n){
            res++;
            right++;
            if(right == nP){
                break;
            }
            tmp += primes[right];
        }
        while(left <= right and tmp > n){
            tmp -= primes[left];
            left++;
        }
        if(tmp == n){
            res++;
            tmp -= primes[left];
            left++;
        }
    }
    return res;
}
int consequentPrime(){
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif //UNTITLED_CONSEQUENTPRIME_H
