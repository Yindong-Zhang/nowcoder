//
// Created by yindong on 19-10-11.
//
/*
 * 题目描述
定义：数值序列中包含2~16进制整数，如果序列中有一个数，与序列中其他任何一个数大小都不相等，则这个数叫做“异数”。请找出给定数值序列中所有的“异数”.
输入描述:

输入数值序列i行(0<i)，每一行分别是进制和数值，以“#”分割。如：n#m, n是整数，代表n进制（1<n<17）,m是n进制下的数值.
输入序列以结束符”END”结束。
m的字符集为0-9和A-F，保证数值在十进制下不超过1e9，行数不超过100001行。

输出描述:

输出j行(0<j<=i),每一行都是输入序列的“异数”。要求：
1.按照输入序列的原序输出;
2.如果没有”异数”,输出字符串”None”
3.结束符“END”不用输出

示例1
输入
复制

10#15
4#32
4#33
8#17
END

输出
复制

4#32


 */
// 时间复杂度　O(n)
#ifndef UNTITLED_UNIQUENUMBER_H
#define UNTITLED_UNIQUENUMBER_H
#include<string>
#include<vector>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;
long long convert(string s){
    int i = 0;
    for(; s[i] != '#'; i++);
    long long d = stoi(s.substr(0, i + 1));
    long long n = 0;
    for(int j = i + 1; j < s.size(); j++){
        n = n * d;
        if(s[j] >= '0' and s[j] <= '9'){
            n += s[j] - '0';
        }
        else{
            n += s[j] - 'A' + 10;
        }
//        cout << n << endl;
    }
//    cout << d << ' ' << s << ' ' << n << endl;
    return n;
}

int unqiueNumber(){
    string s;
    unordered_set<long long> set_unique;
    unordered_set<long long> set_replica;
    vector<pair<long long, string>> inputs;
    while(true){
        cin >> s;
        if(s == "END"){
            break;
        }
        long long n = convert(s);
        inputs.push_back({n, s});
        if(set_replica.find(n) != set_replica.end()){
            continue;
        }
        else{
            auto ptr = set_unique.find(n);
            if(ptr != set_unique.end()){
                set_unique.erase(ptr);
                set_replica.insert(n);
            }
            else{
                set_unique.insert(n);
            }

        }

    }

    if(set_unique.size() == 0){
        cout << "None";
    }
    else{
        for(auto ptr = inputs.begin(); ptr != inputs.end(); ptr++){
            if(set_unique.find(ptr->first) != set_unique.end()){
                cout << ptr->second << endl;
            }
        }
    }
    return 0;
}
#endif //UNTITLED_UNIQUENUMBER_H
