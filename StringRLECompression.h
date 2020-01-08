//
// Created by yindong on 19-8-28.
//

/*
 * 题目描述
对字符串进行RLE压缩，将相邻的相同字符，用计数值和字符值来代替。例如：aaabccccccddeee，则可用3a1b6c2d3e来代替。

输入描述:

输入为a-z,A-Z的字符串，且字符串不为空，如aaabccccccddeee

输出描述:

压缩后的字符串，如3a1b6c2d3e
 */
#ifndef UNTITLED_STRINGRLECOMPRESSION_H
#define UNTITLED_STRINGRLECOMPRESSION_H
#include<string>
#include<iostream>
using namespace std;
int stringCompression(){
    string s;
    cin >> s;
    string res;
    int i = 0;
    int count, j;
    while( i < s.size()){
        count = 1;
        j = i + 1;
        while(s[j] == s[i]){
            j++;
            count++;
        }
        res.push_back('0' + count);
        res.push_back(s[i]);
        i = j;
    }
    cout << res << endl;
}
#endif //UNTITLED_STRINGRLECOMPRESSION_H
