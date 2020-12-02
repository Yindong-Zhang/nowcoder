//
// Created by so_go on 2020/8/15.
//

#ifndef UNTITLED_TIME4INVERSEORDERNUMBER_H
#define UNTITLED_TIME4INVERSEORDERNUMBER_H
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inverse(ll n){
    vector<ll> nums;
    while(n > 0){
        ll r = n % 10;
        n = n / 10;
        nums.push_back(r);
    }
    ll res = 0;
    for(ll num: nums){
        res *= 10;
        res += num;
    }
    return res;
}
vector<ll> solve(ll n){
    ll l = 0, tn = n;
    while(tn > 0){
        l++;
        tn /= 10;
    }
    vector<ll> res;
    ll base = 10;
    for(ll li = 2; li <= l; li++){
        ll start = base + 1, end = base * 10 / 4;
        for(ll i = start; i < end and 4 * i <= n; ++i){

            if(inverse(i) == 4 * i){
                res.push_back(i);
            }
        }
        base *= 10;
    }
//    for(ll i = 1; i <= n; ++i){
//        if(inverse(i) == 4 * i){
//            res.push_back(i);
//        }
//    }
    return res;
}

int times4ION(){
    ll n;
    cin >> n;
    vector<ll> res = solve(n);
    cout << res.size() << endl;
    if(res.size() > 0){
        for(ll k : res){
            cout <<  k << ' ' << 4 *k << endl;
        }
    }
    return 0;
}
#endif //UNTITLED_TIME4INVERSEORDERNUMBER_H
