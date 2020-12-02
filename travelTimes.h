//
// Created by so_go on 2020/8/15.
//

#ifndef UNTITLED_TRAVELTIMES_H
#define UNTITLED_TRAVELTIMES_H
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int solve(vector<vector<string>> &ticks){
    string curStart;
    int res = 0;
    bool newStart = true;
    for(int i = 0; i < ticks.size(); ++i){
        if(newStart){
            curStart = ticks[i][0];
            newStart = false;
        }
//        string curLoc = ticks[i][0];
        string curDest = ticks[i][1];
        if(curDest == curStart){
            res++;
            newStart = true;
        }
    }
    return res;
}
int travelCount(){
    int n;
    cin >> n;
    string sa, sb;
    vector<vector<string>> ticks;
    for(int i = 0; i < n; ++i){
        cin >> sa >> sb;
        ticks.push_back({sa, sb});
    }
    cout << solve(ticks) << endl;
    return 0;
}
#endif //UNTITLED_TRAVELTIMES_H
