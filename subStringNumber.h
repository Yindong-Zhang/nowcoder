//
// Created by so_go on 2020/4/1.
//

#ifndef UNTITLED_SUBSTRINGNUMBER_H
#define UNTITLED_SUBSTRINGNUMBER_H

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(string s, set<char> st){
    int count = 0;
    ll res = 0;
    for(int i = 0; i < s.size(); ++i){
        if(st.find(s[i]) != st.end()){
            count++;
            continue;
        }
        res += (count * (count + 1)) / 2;
        count = 0;
    }
    return res;
}

int subStringCount(){
    int n, k;
    string s;
    char ch;
    set<char> st;
    cin >> n >> k;
//    cout << n << ' ' << k << endl;
    for(int i = 0; i < n; ++i){
        cin >> ch;
        s.push_back(ch);
    }
//    cout << s << endl;
    for(int i = 0; i < k ; ++i){
        cin >> ch;
//        cout << ch;
        st.insert(ch);
    }
    cout << solve(s, st) << endl;
    return 0;
}
#endif //UNTITLED_SUBSTRINGNUMBER_H
