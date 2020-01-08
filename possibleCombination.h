//
// Created by yindong on 19-9-8.
//

#ifndef UNTITLED_POSSIBLECOMBINATION_H
#define UNTITLED_POSSIBLECOMBINATION_H
#include<string>
#include<iostream>
#include<vector>
using namespace std;
void dfs(string &s, uint j, string &res){
    if(j == s.size()){
        cout << res << endl;
        return;
    }
    if(s[j] == '0'){
        return;
    }
    res.push_back(s[j] - '0' + 'A' - 1);
    dfs(s, j + 1, res);
    res.pop_back();
    if( j + 2 <= s.size() and (s[j] == '1' or s[j] == '2')){
        int n = (s[j] - '0') * 10 + s[j + 1] - '0';
        if(n <= 26){
            res.push_back('A' + n - 1);
            dfs(s, j + 2, res);
            res.pop_back();
        }
    }
}
void solve(string s){
    string res;
    dfs(s, 0, res);
}
int possibleCombination(){
    string s;
    cin >> s;
    solve(s);
    return 0;
}
#endif //UNTITLED_POSSIBLECOMBINATION_H
