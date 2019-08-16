//
// Created by so_go on 2019/8/16.
//
/*
 * 题目描述
又到了丰收的季节，恰逢小易去牛牛的果园里游玩。
牛牛常说他对整个果园的每个地方都了如指掌，小易不太相信，所以他想考考牛牛。
在果园里有N堆苹果，每堆苹果的数量为ai，小易希望知道从左往右数第x个苹果是属于哪一堆的。
牛牛觉得这个问题太简单，所以希望你来替他回答。
输入描述:

第一行一个数n(1 <= n <= 105)。
第二行n个数ai(1 <= ai <= 1000)，表示从左往右数第i堆有多少苹果
第三行一个数m(1 <= m <= 105)，表示有m次询问。
第四行m个数qi，表示小易希望知道第qi个苹果属于哪一堆。

输出描述:

m行，第i行输出第qi个苹果属于哪一堆。

示例1
输入
复制

5
2 7 3 4 9
3
1 25 11

输出
复制

1
5
3


 */
#ifndef UNTITLED_HARVEST_H
#define UNTITLED_HARVEST_H
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int harvest(){
    int n, m;
    int count, query;
    vector<int> apples;
    int acc_sum = 1;
    apples.push_back(1);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> count;
        acc_sum += count;
        apples.push_back(acc_sum);
    }
    cin >> m;
    for(int j = 0; j < m; j++){
        cin >> query;
        auto ptr = upper_bound(apples.begin(), apples.end(), query);
        cout << "p: " << *ptr << endl;
        cout << ptr - apples.begin() << endl;

    }
    return 0;
}
#endif //UNTITLED_HARVEST_H
