//
// Created by yindong on 19-9-7.
//

#ifndef UNTITLED_DRINKCOFFEE_H
#define UNTITLED_DRINKCOFFEE_H
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

int solve(vector<int> d, uint k){
    int n = d.size();
    if(n == 0){
        return ceil(30 / float(k + 1));
    }
    uint sum = 0;
    int interval = d[0] - 1;
    if(interval > k){
        sum += ceil((interval - k) / float(k + 1));
    }
    for(int i = 1; i < d.size(); i++){
        interval = d[i] - d[i - 1];
        if(interval >= 2 * k + 1){
            sum += ceil((interval - 2 * k - 1)/ float(k + 1));
        }
    }
    if(d[n - 1] + k < 30){
        sum += ceil((30 - d[n - 1] - k) / float(k + 1));

    }
    return sum + n;
}

int drinkCoffee(){
    int n;
    cin >> n;
    int k, m, di;
    vector<int> d;
    for(int i = 0; i < n; i++){
        d.clear();
        cin >> k >> m;
        for(int i = 0; i < m; i++){
            cin >> di;
            d.push_back(di);
        }
        cout << solve(d, k) << endl;
    }
    return 0;
}
#endif //UNTITLED_DRINKCOFFEE_H
