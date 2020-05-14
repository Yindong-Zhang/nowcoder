//
// Created by so_go on 2020/4/29.
//

#ifndef UNTITLED_HUAWEI2_H
#define UNTITLED_HUAWEI2_H
#include<bits/stdc++.h>
using namespace std;

string solve(string s, int k){
    for(int ki = 0; ki < k; ++ki){
        bool isFind= false;
//        cout << s.size() << ' ' << ki << ' ' << k  << endl;
        for(int i = 0; i + 1 < s.size(); ++i){
            if(s[i] > s[i + 1]){
                s.erase(i, 1);
                isFind = true;
                break;
            }
        }
        if(not isFind){
            s.erase(s.size() - 1, 1);
        }
    }
    return s;
}

int keyProtocal(){
    string s;
    int k;
    cin >> s;
    cin >> k;
    cout << solve(s, k) << endl;
    return 0;
}
#endif //UNTITLED_HUAWEI2_H
