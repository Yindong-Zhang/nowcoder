//
// Created by yindong on 19-8-22.
//
/*
 * 题目描述

小易在学校中学习了关于字符串的理论, 于是他基于此完成了一个字典的项目。

小易的这个字典很奇特, 字典内的每个单词都包含n个'a'和m个'z', 并且所有单词按照字典序排列。

小易现在希望你能帮他找出第k个单词是什么。
输入描述:

输入包括一行三个整数n, m, k(1 <= n, m <= 100, 1 <= k <= 109), 以空格分割。

输出描述:

输出第k个字典中的字符串，如果无解，输出-1。

示例1
输入
复制

2 2 6

输出
复制

zzaa

说明

字典中的字符串依次为aazz azaz azza zaaz zaza zzaa


 */
#ifndef UNTITLED_DICTIONARYORDER_H
#define UNTITLED_DICTIONARYORDER_H
#include<iostream>
#include<string>
using namespace std;
int count = 0;
// 超时。。。
void dfs(string &s, int m, int n, int k){
    if(m + n == 0){
        count++;
        if(count == k){
            cout << s << endl;
        }
    }
    if(m > 0){
        s.push_back('a');
        dfs(s, m - 1, n, k);
        s.pop_back();
    }

    if(n > 0){
        s.push_back('z');
        dfs(s, m, n - 1, k);
        s.pop_back();
    }
}

string greedy(int m, int n, int k){
    string s;
    long long count = 1;
    while(true){
        count = 1;
        for(int i = 0; i < m - 1; i++){
            count *= (m + n - 1- i);
            count /= (i + 1);
            if(count > k){
                break;
            }
        }

//        cout << m << ' ' << n << ' ' << k << ' ' << count << endl;
        if( m == 0 and n == 0){
            break;
        }
        else if (m == 0){
            s.push_back('z');
            n--;
        }
        else if(n == 0){
            s.push_back('a');
            m--;
        }
        else if(m > 0 and k <= count){
            s.push_back('a');
            m--;
        }
        else{
            s.push_back('z');
            k = k - count;
            n--;
        }
        // k > (n, m + n)的情况
    }
    if(k == 1){
        return s;
    }
    else{
        return "-1" ;
    }

}
int dictionaryOrder(){
    int m, n;
    long long k;
    cin >> m >> n >> k;
    string s;
    s = greedy(m, n, k);
    cout << s << endl;
    return 0;
}
#endif //UNTITLED_DICTIONARYORDER_H
