//
// Created by yindong on 19-9-18.
//
// 电信
#ifndef UNTITLED_ISOMORPHSIM_H
#define UNTITLED_ISOMORPHSIM_H
#include<string>
#include<map>
#include<iostream>
using namespace std;

bool solve(string a, string b){
    if(a.size() != b.size()){
        return false;
    }
    map<char, char> aDict;
    for(int i = 0; i < a.size(); i++){
//        cout << i << endl;
        auto aptr = aDict.find(a[i]);

        if(aptr == aDict.end() ){
            aDict.insert({a[i], b[i]});
            continue;
        }
        else if(aptr != aDict.end() and aptr->second == b[i]){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
int stringCompare(){
    string a, b;
    char ch;
    while(true){
        cin.get(ch);
        if(ch != ';'){
            a.push_back(ch);
        }
        else{
            break;
        }
    }

    cin >> b;
    if(solve(a, b)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
}
#endif //UNTITLED_ISOMORPHSIM_H
