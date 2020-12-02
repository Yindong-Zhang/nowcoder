//
// Created by so_go on 2020/12/2.
//

#ifndef UNTITLED_UNREPEATEDSUBSTRING_H
#define UNTITLED_UNREPEATEDSUBSTRING_H
#include<bits/stdc++.h>
using namespace std;

int solve(string s){
    map<char, int> loc;
    int l = 0;
    int res = 0;
    for(int r = 0; r < s.size(); ++r){
        if(loc.find(s[r]) != loc.end()) {
            l = loc[s[r]] + 1;
        }
        res = max(res, r - l + 1);
        loc[s[r]] = r;
    }
    return res;
}
int unRepeatedSubstring(){
    string s = "abcabcbb";
    cout << solve(s) << endl;
    return 0;
}
#endif //UNTITLED_UNREPEATEDSUBSTRING_H
