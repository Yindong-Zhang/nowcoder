//
// Created by so_go on 2020/8/12.
//

#ifndef UNTITLED_QIXINGBUKAO_H
#define UNTITLED_QIXINGBUKAO_H
#include<bits/stdc++.h>
using namespace std;
bool isEqual(char a, char b){
    if(a == b or a == '#'){
        return true;
    }
    return false;
}
bool isMatch(vector<char> &hs, string s){
    for(int i = 0; i < 3; ++i){
        int start = 3 * i;
        if(not isEqual(hs[start], s[0])){
            return false;
        }
        if(not isEqual(hs[start + 1], s[1])){
            return false;
        }
        if(not isEqual(hs[start + 2], s[2])){
            return false;
        }
    }
    return true;
}
bool isBuKao(vector<char> hs){
    if(isMatch(hs, "WBT")){
        return true;
    }
    if(isMatch(hs, "WTB")){
        return true;
    }
    if(isMatch(hs, "BWT")){
        return true;
    }
    if(isMatch(hs, "BTW")){
        return true;
    }
    if(isMatch(hs, "TWB")){
        return true;
    }
    if(isMatch(hs, "TBW")){
        return true;
    }
    return false;
}
bool isQiXingBuKao(vector<int> &nums, vector<char> &huaSe){
    vector<char> hs(9, '#');
    for(int i = 0; i < 7; ++i){
        int ind = nums[i];
        if(hs[ind - 1] == '#'){
            hs[ind - 1] = huaSe[i];
        }
        else{
            return false;
        }
    }
    return isBuKao(hs);
}

int QiXingBuKao(){
    int T;
    cin >> T;
    vector<int> nums(7);
    vector<char> huase(7);
    int i;
    char ch;
    for(int t = 0; t < T; ++t){
        for(int j = 0; j < 7; ++j){
            cin >> i >> ch;
//            cout << i << ' ' << ch << endl;
            nums[j] = i;
            huase[j] = ch;
        }
        if(isQiXingBuKao(nums, huase)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
#endif //UNTITLED_QIXINGBUKAO_H
