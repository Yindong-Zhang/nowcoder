//
// Created by yindong on 19-8-27.
//
/*
 * 题目描述
我们定义字符串包含关系：字符串A=abc，字符串B=ab，字符串C=ac，则说A包含B，A和C没有包含关系。
输入描述:

两个字符串，判断这个两个字符串是否具有包含关系，测试数据有多组，请用循环读入。

输出描述:

如果包含输出1，否则输出0.

示例1
输入
复制

abc ab

输出
复制

1


 */
#ifndef UNTITLED_STRINGMATCH_H
#define UNTITLED_STRINGMATCH_H
#include<string>
#include<iostream>
using namespace std;
int stringMatch(){
    string a, b;
    while(cin >> a >> b){
        if(a.size() < b.size()){
            swap(a, b);
        }
        if(a.find(b) != string::npos){
            cout << '1' << endl;
        }
        else{
            cout << '0' << endl;
        }
    };

}
#endif //UNTITLED_STRINGMATCH_H
