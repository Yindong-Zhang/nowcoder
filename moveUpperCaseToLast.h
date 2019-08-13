//
// Created by so_go on 2019/8/13.
//

#ifndef UNTITLED_MOVEUPPERCASETOLAST_H
#define UNTITLED_MOVEUPPERCASETOLAST_H
/*
 * 小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
你能帮帮小Q吗？
输入描述:
输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
输出描述:
对于每组数据，输出移位后的字符串。
输入例子1:
AkleBiCeilD
输出例子1:
kleieilABCD
 */
#include<string>
#include<cctype>
#include<iostream>
using namespace std;

string moveUpperCaseToLast(string s){
    int last = s.size();
    char tmp;
    for(int i = s.size() - 1; i >= 0; i--){
        if(isupper(s[i])){
            tmp = s[i];
            for(int j = i; j < last - 1; j++){
                s[j] = s[j + 1];
            }
            s[last - 1]= tmp;
            last--;
        }
//        cout << s << endl;
    }
    return s;
}
#endif //UNTITLED_MOVEUPPERCASETOLAST_H
