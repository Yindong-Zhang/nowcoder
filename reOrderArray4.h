//
// Created by so_go on 2019/8/15.
//
/*
 * 小易有一个长度为N的正整数数列A = {A[1], A[2], A[3]..., A[N]}。
牛博士给小易出了一个难题:
对数列A进行重新排列,使数列A满足所有的A[i] * A[i + 1](1 ≤ i ≤ N - 1)都是4的倍数。
小易现在需要判断一个数列是否可以重排之后满足牛博士的要求。

输入描述:

输入的第一行为数列的个数t(1 ≤ t ≤ 10),
接下来每两行描述一个数列A,第一行为数列长度n(1 ≤ n ≤ 10^5)
第二行为n个正整数A[i](1 ≤ A[i] ≤ 10^9)


输出描述:

对于每个数列输出一行表示是否可以满足牛博士要求,如果可以输出Yes,否则输出No。


输入例子1:

2
3
1 10 100
4
1 2 3 4


输出例子1:

Yes
No


 */
#ifndef UNTITLED_REORDERARRAY4_H
#define UNTITLED_REORDERARRAY4_H
#include<vector>
using namespace std;

int powerOf2(int n){
    int power = 0;
    while(n % 2 == 0){
        power++;
        n = n / 2;
    }
    return power;
}

bool isReorderFit(vector<int> vec){
    int n_ge2 = 0, n_0 = 0;
    int power_2;
    for(int i = 0; i < vec.size(); i++){
        power_2 = powerOf2(vec[i]);
        if(power_2 >= 2){
            n_ge2++;
        }
        else if (power_2 == 0){
            n_0++;
        }
    }
    if(n_ge2 >= n_0){
        return true;
    }
    else{
        return false;
    }
}
#endif //UNTITLED_REORDERARRAY4_H
