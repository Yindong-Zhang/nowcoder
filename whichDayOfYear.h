//
// Created by yindong on 19-8-30.
//
/*
 * 题目描述


输入年、月、日，计算该天是本年的第几天。

输入：

包括三个整数年(1<=Y<=3000)、月(1<=M<=12)、日(1<=D<=31)。

输出：

输入可能有多组测试数据，对于每一组测试数据，

输出一个整数，代表Input中的年、月、日对应本年的第几天。


输入描述:

输入：1990 9 20

输出描述:

输入：263

示例1
输入
复制

2000 5 1

输出
复制

122


 */
#ifndef UNTITLED_WHICHDAYOFYEAR_H
#define UNTITLED_WHICHDAYOFYEAR_H
#include<vector>
#include<iostream>
using namespace std;
vector<int> days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int solve(int year, int month, int day){
    int res = 0;
    for(int i = 1; i < month; i++){
        res += days[i];
        if(i == 2){
            if(year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)){
                res += 1;
            }
        }

    }
    res += day;

    return res;

}
int whichDayOfYear(){
    int year, month, day;
    while(cin >> year >> month >> day){
        cout << solve(year, month, day) << endl;
    }
    return 0;
}

#endif //UNTITLED_WHICHDAYOFYEAR_H
