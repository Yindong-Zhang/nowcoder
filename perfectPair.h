//
// Created by so_go on 2020/8/17.
//

#ifndef UNTITLED_PERFECTPAIR_H
#define UNTITLED_PERFECTPAIR_H
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isMatch(vector<int> a, vector<int> b){
    int sum = a[0] + b[0];
    for(int i = 1; i < b.size(); ++i){
        if(a[i] + b[i] != sum){
            return false;
        }
    }
    return true;
}
int solve(vector<vector<int>> items){
    int n = items.size();
    ll res = 0;

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
                if(isMatch(items[i], items[j])){
//                    cout << i << ' ' << j << endl;
                    res++;
                }
            }
        }
    return res;
}

int perfertPair(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> items(n, vector<int>(k , 0));
    for(int i = 0; i < n; ++i){
        for(int ki = 0; ki < k; ++ki){
            cin >> items[i][ki];
        }
    }
    cout << solve(items) << endl;
    return 0;
}
#endif //UNTITLED_PERFECTPAIR_H
