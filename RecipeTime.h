//
// Created by so_go on 2020/8/12.
//

#ifndef UNTITLED_RECIPETIME_H
#define UNTITLED_RECIPETIME_H
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Record{
    ll t;
    ll e;
    ll s;
};

ll dfs(vector<Record> &records, ll &i, ll &t_res, ll &resE){
//    if(records[i].s != 0){
//        cout << "oops" << endl;
//    }
    ll curE = records[i].e;
    ll startT = records[i].t;
    ll s = records[i].s;
//    cout << startT << ' ' << curE << ' ' << s << endl;
    ll t_se = 0;
    i++;
    while (records[i].e != curE){
//        i = i + 1;
        t_se += dfs(records, i, t_res, resE);
    }
    ll endT = records[i].t;
    ll t_last = endT - startT;
    ll t_self = endT - startT - t_se;
    if(t_self > t_res){
        t_res = t_self;
        resE = curE;
    }
    i++;
    return t_last;
}
ll solve(vector<Record> &records){
    ll resT = INT_MIN;
    ll resE = 0;
    ll i = 0;
    while(i < records.size()) {
        dfs(records, i, resT, resE);
    }
    cout << resE << endl;
    return 0;
}
ll recipeTime(){
    ll T;
    cin >> T;
    ll N;
    ll t, e, s;
    for(ll Ti = 0; Ti < T; ++Ti){
        cin >> N;
        vector<Record> records;
        for(ll n = 0; n < N; ++n){
            cin >> t >> e >> s;
            records.push_back({t, e, s});
        }
        solve(records);
        records.clear();
    }
    return 0;
}
#endif //UNTITLED_RECIPETIME_H
