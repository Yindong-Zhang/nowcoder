//
// Created by yindong on 19-8-24.
//

#ifndef UNTITLED_CHARCOUNT_H
#define UNTITLED_CHARCOUNT_H
/*
 * 题目描述


通过键盘输入一串小写字母(a~z)组成的字符串。
请编写一个字符串归一化程序，统计字符串中相同字符出现的次数，并按字典序输出字符及其出现次数。
例如字符串"babcc"归一化后为"a1b2c2"



输入描述:

每个测试用例每行为一个字符串，以'\n'结尾，例如cccddecca

输出描述:

输出压缩后的字符串ac5d2e

示例1
输入
复制

dabcab

输出
复制

a2b2c1d1


 */
#include<iostream>
#include<map>
using namespace std;

int countChar(){
    map<char, int> count;
    char ch;
    while(cin.peek() != '\n'){
        ch = cin.get();
        auto ptr = count.find(ch);
        if(ptr == count.end()){
            count[ch] = 1;
        }
        else{
            ptr->second++;
        }
    }
    for(auto ptr = count.begin(); ptr != count.end(); ptr++){
        cout << ptr->first << ptr->second;
    }
    return 0;
}

#endif //UNTITLED_CHARCOUNT_H
