//
// Created by yindong on 19-8-7.
//

#ifndef UNTITLED_MAPSUBSTRACTION_H
#define UNTITLED_MAPSUBSTRACTION_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;

void mapSubtraction() {
    char key;
    int count;
    map<char, int> all, used;
    vector<char> chars;
    while(true){
        cin >> key;
        cin.get();
        cin >> count;
        cout << key << ' ' << count << endl;
        chars.push_back(key);
        all.insert({key, count});
        if(cin.get() == '@'){
            break;
        }
    }
    while(true){
        cin.get(key);
        if(key == '\n'){
            break;
        }
        cin.get();
        cin >> count;
        cout << key << ' ' << count << endl;
        used.insert({key, count});
        if(cin.get() == '\n'){
            break;
        }
    }
    int availCount = 0;
    char ch;
    bool isFirst= true;
    for(int i = 0; i < chars.size(); i++) {
        ch = chars[i];
        auto all_ptr = all.find(ch);
        auto used_ptr = used.find(ch);
        if (used_ptr == used.end()) {
            availCount = all_ptr->second;
        } else {
            availCount = all_ptr->second - used_ptr->second;
        }
        if (availCount != 0) {
            if (isFirst) {
                isFirst = false;
            }
            else{
                cout << ',';
            }
            cout << all_ptr->first << ':' << availCount;

        }
    }
    cout << endl;
}
#endif //UNTITLED_MAPSUBSTRACTION_H
