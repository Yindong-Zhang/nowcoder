//
// Created by so_go on 2019/8/13.
//
/*
 *  为了得到一个数的"相反数",我们将这个数的数字顺序颠倒,然后再加上原先的数得到"相反数"。例如,为了得到1325的"相反数",首先我们将该数的数字顺序颠倒,我们得到5231,之后再加上原先的数,我们得到5231+1325=6556.如果颠倒之后的数字有前缀零,前缀零将会被忽略。例如n = 100, 颠倒之后是1.

输入描述:

输入包括一个整数n,(1 ≤ n ≤ 10^5)


输出描述:

输出一个整数,表示n的相反数


输入例子1:

1325


输出例子1:

6556

重置自测
 */
#ifndef UNTITLED_REVERSEORDERNUMBER_H
#define UNTITLED_REVERSEORDERNUMBER_H
#include<vector>
#include<string>
using namespace std;
vector<int> number2vec(long long n){
    vector<int> res;
    while( n > 0){
        res.push_back(n % 10);
        n = n / 10;
    }
//    for(int i = 0; i < res.size(); i++){
//        cout << res[i] << ' ';
//    }
//    cout << endl;
    return res;
}

string inverseNumber(long long n){
    vector<int> vec = number2vec(n);
    vector<int> res;
    int t = 0, sum; // 进位， 每位的和，
    int s = vec.size() - 1;
    for(int i = 0; i < vec.size(); i++){
        sum = vec[i] + vec[s - i] + t;
        if(sum < 10){
            res.push_back(sum);
            t = 0;
        }
        else{
            res.push_back(sum % 10);
            t = 1;
        }
    }
    if(t > 0){
        res.push_back(t);
    }
//    for(int i = 0; i < res.size(); i++){
//        cout << res[i] << ' ';
//    }
//    cout << endl;
    string str;
    for(int i = res.size() - 1; i >= 0; i--){
        str.push_back(res[i] + '0');
    }
    return str;
}

#endif //UNTITLED_REVERSEORDERNUMBER_H
