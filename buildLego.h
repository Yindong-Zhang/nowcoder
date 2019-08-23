//
// Created by yindong on 19-8-23.
//

#ifndef UNTITLED_BUILDLEGO_H
#define UNTITLED_BUILDLEGO_H
#include<vector>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
typedef pair<int, int> block;
int LIS(vector<int> v){
    vector<int> dp(v.size() + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < v.size(); i++){
        auto ptr = upper_bound(dp.begin(), dp.end(), v[i]);
        *ptr = v[i];
//        for(int i = 0; i< dp.size();i++){
//            cout << dp[i] << ' ';
//        }
//        cout << endl;
    }
    int i = 1;
    while(i + 1 < dp.size() and dp[i + 1] != INT_MAX){
        i++;
    }
    return i;
}

int solve(vector<block> blocks){
    sort(blocks.begin(), blocks.end());
    vector<int> a(blocks.size(), 0);
    for(int i = 0; i < blocks.size(); i++){
        a[i] = blocks[i].second;
    }
    return LIS(a);
}
int buildLego(){
    int n;
    int w, l;
    vector<block> blocks;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> w >> l;
        blocks.push_back({w, l});
    }
    cout << solve(blocks) << endl;

}
#endif //UNTITLED_BUILDLEGO_H
