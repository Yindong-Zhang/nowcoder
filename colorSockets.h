//
// Created by so_go on 2020/3/27.
//

#ifndef UNTITLED_COLORSOCKETS_H
#define UNTITLED_COLORSOCKETS_H
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &s){
    int count = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] > 0){
            count++;
            s[i] = s[i] - 1;
        }
    }
    for(int i = 0; i < s.size(); ++i){
        if(s[i] > 0){
            return count + 1;
        }
    }
    return -1;
}

int colorfulSockets(){
    int T, n;
    vector<int> s;
    cin >> T;
    int si;
    for(int i = 0; i < T; ++i){
        cin >> n;
        for(int j = 0; j < n; ++j){
           cin >> si;
           s.push_back(si);
        }
        cout << solve(s) << endl;
        s.clear();
    }
    return 0;
}
#endif //UNTITLED_COLORSOCKETS_H
