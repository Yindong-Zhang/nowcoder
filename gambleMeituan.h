//
// Created by so_go on 2020/3/19.
//

#ifndef UNTITLED_GAMBLEMEITUAN_H
#define UNTITLED_GAMBLEMEITUAN_H
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll> &a, vector<ll> &b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll sa = a[a.size() - 1] + a[a.size() - 2] + a[a.size() - 3];
    ll sb = b[b.size() - 1] + b[b.size() - 2] + b[b.size() - 3];
    return max(sa, sb);
}
int gamble(){
    int n;
    ll num;
    vector<ll> a, b;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> num;
        a.push_back(num);
    }
    for(int i = 0; i < n; ++i){
        cin >> num;
        b.push_back(num);
    }
    cout << solve(a, b) << endl;
    return 0;
}
#endif //UNTITLED_GAMBLEMEITUAN_H
