//
// Created by so_go on 2020/3/23.
//
/*
 *

我们知道每一个大于1的整数都一定是质数或者可以用质数的乘积来表示，如10=2*5。现在请设计一个程序，对于给定的一个(1，N] 之间的正整数（N取值不超过10万），你需要统计(1，N] 之间所有整数的质数分解后，所有质数个数的总个数。举例，输入数据为6，那么满足(1,6] 的整数为2，3，4，5，6，各自进行质数分解后为：2=>2，3=>3，4=>2*2，5=>5，6=>2*3。对应的质数个数即为1，1，2，1，2。最后统计总数为7


输入描述:

输入数据包含1行，为一个大于1的整数（不超过10万）。


输出描述:

输出小于等于该数的所有整数质数分解后的总个数。


输入例子1:

6


输出例子1:

7


 */
#ifndef UNTITLED_PRIMECOUNT_H
#define UNTITLED_PRIMECOUNT_H
#include"printVector.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(int n){
    ll res = 0;
    vector<ll> dp(n, 0);
    vector<int> p(n, 0);
    for(int i = 1; i < n; ++i){
        if(p[i] == 0){
            int k = 2;
            while(k * (i + 1) <= n ){
                p[k * (i + 1) - 1] = i;
                k++;
            }
        }
    }
    printVector(p);
    for(int i = 1; i < n; ++i){
         dp[i] = dp[ (i + 1) / (p[i] + 1) - 1 ] + 1;
    }
    printVector(dp);
    for(int i = 1; i < n; ++i){
        res += dp[i];
    }
    return res;
}
int primeCount(){
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif //UNTITLED_PRIMECOUNT_H
