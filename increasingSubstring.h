//
// Created by so_go on 2020/3/19.
//

#ifndef UNTITLED_INCREASINGSUBSTRING_H
#define UNTITLED_INCREASINGSUBSTRING_H
#include<bits/stdc++.h>
#include"printVector.h"
#define ll long long
using namespace std;

int solve(vector<int> &v){
    int n = v.size();
    vector<int> I(n , 1), D(n, 1);
    int res = 1;
    for(int i = 1; i < v.size(); i++){
        if(v[i] > v[i - 1]){
            I[i] = I[i - 1] + 1;
            res = max(res, I[i]);
        }
        else{
            I[i] = 1;
        }
    }
    for(int j = n - 2; j >= 0; --j){
        if(v[j] < v[j + 1]){
            D[j] = D[j + 1] + 1;
        }
        else{
            D[j] = 1;
        }
    }
//    printVector(I);
//    printVector(D);
    for(int i = 1; i < v.size() - 1; ++i){
        if(v[i + 1] > v[i - 1]){
            res = max(res, I[i - 1] + D[i + 1]);
        }
    }
    return res;
}

int deleteIncresingString(){
    int n, num;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> num;
        v.push_back(num);
    }
    cout << solve(v) << endl;
    return 0;
}

#endif //UNTITLED_INCREASINGSUBSTRING_H
