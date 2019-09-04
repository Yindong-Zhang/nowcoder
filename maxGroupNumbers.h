//
// Created by yindong on 19-9-4.
//

#ifndef UNTITLED_MAXGROUPNUMBERS_H
#define UNTITLED_MAXGROUPNUMBERS_H
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
vector<int> solve(string s){
    map<char, int> last;
    vector<int> res;
    for(int i = 0; i < s.size(); i++){
        if(last.find(s[i]) == last.end()){
            last.insert({s[i], i});
        }
        else{
            last[s[i]] = i;
        }
    }
    int curLast = 0, count = 1;
    for(int i = 0; i < s.size(); i++){
        if(last[s[i]] > curLast){
            curLast = last[s[i]];
        }
        if(i == curLast){
            res.push_back(count);
            count = 1;
            curLast = i + 1;
        }
        else{
            count++;
        }
    }
    return res;
}
int maxGroup(){
    string s;
    cin >> s;
    vector<int> res = solve(s);
    for(int i = 0; i < res.size(); i++){
        cout << res[i];
        if(i != res.size() - 1){
            cout << ',';
        }
    }
    return 0;
}
#endif //UNTITLED_MAXGROUPNUMBERS_H
