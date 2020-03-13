//
// Created by so_go on 2020/3/13.
//

#ifndef UNTITLED_REGEXSUBSTRINGMATCH_H
#define UNTITLED_REGEXSUBSTRINGMATCH_H
#include<bits/stdc++.h>
using namespace std;

bool charMatch(char a, char b){
    if(b == '.'){
        return true;
    }
    else{
        return a == b;
    }
}
bool match(string &s, string &p, int i, int j){
    cout << i << ' ' << j << endl;
    if(j == p.size()){
        return true;
    }
    if(i == s.size()){
        if(p[j] == '$' and j + 1 == p.size()){
            return true;
        }
        else{
            return false;
        }
    }
    if(p[j] == '^'){
        if(i == 0){
            return match(s, p, i, j + 1);
        }
        else{
            return false;
        }
    }
    if(p[j + 1] != '*'){
        return charMatch(s[i], p[j]) and match(s, p, i + 1, j + 1);
    }
    else{
        if(charMatch(s[i], p[j])){
            return match(s, p, i + 1, j) or match(s, p, i, j + 2);
        }
        else{
            return match(s, p, i, j + 2);
        }
    }
}
int solve(string &s, string &p){
    for(int i = 0; i < s.size(); ++i){
        if(match(s, p, i, 0)){
            return 1;
        }
    }
    return 0;
}

int main(){
    string s, p;
    getline(cin, p);
    getline(cin, s);
    cout << solve(s, p) << endl;
    return 0;
}
#endif //UNTITLED_REGEXSUBSTRINGMATCH_H
