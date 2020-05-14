//
// Created by so_go on 2020/4/29.
//

#ifndef UNTITLED_SHUFFLECOUNT_H
#define UNTITLED_SHUFFLECOUNT_H
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll jiecheng(int n){
    ll res = 1;
    for(int i = 1; i <= n; ++i){
        res *= i;
    }
    return res;
}
ll solve(string s){
    if(s.size() == 0){
        return 0;
    }
    map<char, int> ch_count;
    for(char ch : s){
        if(ch_count.find(ch) == ch_count.end()){
            ch_count[ch] = 1;
        }
        else{
            ch_count[ch] += 1;
        }
    }
    ll res = jiecheng(s.size());
    for(auto ptr = ch_count.begin(); ptr != ch_count.end(); ++ptr){
        res /= jiecheng(ptr->second);
    }
    return res;
}

int shuffleCount(){
    string s;
    getline(cin, s);
    cout << solve(s) << endl;
    return 0;
}
#endif //UNTITLED_SHUFFLECOUNT_H
