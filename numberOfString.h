/*
题目描述
求字典序在s1和s2之间的，长度在len1到len2的字符串的个数，结果mod 1000007。

输入描述:
每组数据包涵s1（长度小于100），s2（长度小于100），len1（小于100000），len2（大于len1，小于100000）
输出描述:
输出答案。
示例1
输入
复制
ab ce 1 2
输出
复制
56
*/
#include<bits/stdc++.h>
#define N 1000007
using namespace std;

int solve(string &s1, string &s2, int l1, int l2){
    int i = 0;
    int res = 0;
    while(s1[i] == s2[i]){
        i++;
    }
    int res = 0;
    if(s1[i] - s2[i] > 1){
        int tmp = 0;
        int base = 1;
        for(int i = 0; i < l1 - i - 1; ++i){
            base = ( base * 24 ) % N;
        }
        for(int i = l1 - i - 1; i < l2 - i - 1; ++i){
            res = (res + base) % N;
            base = (base * 24) % N;
        }
        res = ( res * 4 ) % N;
        
    }
    for(int i0 = i + 1; i0 < s.size(); ++i0){
        
    }
}
int main(){
    string s1, s2;
    int l1, l2;
    cin >> s1 >> s2 >> l1 >> l2;
    cout << solve(s1, s2, l1, l2) << endl;
    return 0;
}
