//
// Created by so_go on 2020/2/26.
//
// n! 数字中零的个数
// {1...n}数字中0的个数n0, 2
#ifndef UNTITLED_ZEROINFACTORIAL_H
#define UNTITLED_ZEROINFACTORIAL_H
// 输入一个正整数n,求n!(即阶乘)末尾有多少个0？ 比如: n = 10; n! = 3628800,所以答案为2
// 对n！做质因数分解，因为10 的质因子分解为 2 * 5，n!= 2^n2 * 5^n5， res = min(n2, n5)
// 又因为， n2 > n5,, 故 res = n5, 所有只需计算{1...n}中质因子5的个数
// 可以得出f(n) = n / 5 + f(n / 5)
#include<iostream>
using namespace std;
int f(int n){
    if(n == 0){
        return 0;
    }
    return n / 5 + f( n / 5);
}
int solve(int n ){
    return f(n);
}
int zerosInFactorial(){
    int n;
    cin >> n;
    return solve(n);
}
#endif //UNTITLED_ZEROINFACTORIAL_H
