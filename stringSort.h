//
// Created by yindong on 19-8-25.
//

#ifndef UNTITLED_STRINGSORT_H
#define UNTITLED_STRINGSORT_H
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int stringSort(){
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        string lstr = s.substr(s.size() - 6, 6);
        sort(lstr.begin(), lstr.end());
        cout << lstr << endl;
    }
}
#endif //UNTITLED_STRINGSORT_H
