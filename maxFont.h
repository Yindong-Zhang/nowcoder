//
// Created by yindong on 19-8-25.
//
/*
 * 题目描述
latex自然是广大研究人员最喜欢使用的科研论文排版工具之一。
月神想在iPhone 上查阅写好的paper，但是无赖iPhone 上没有月神喜欢使用的阅读软件，于是月神也希望像tex老爷爷Donald Knuth那样自己动手do it yourself一个。
在DIY这个阅读软件的过程中，月神碰到一个问题，已知iPhone屏幕的高为H，宽为W，若字体大小为S(假设为方形），则一行可放W / S(取整数部分）个文字，一屏最多可放H / S （取整数部分）行文字。
已知一篇paper有N个段落，每个段落的文字数目由a1, a2, a3,...., an表示，月神希望排版的页数不多于P页（一屏显示一页），那么月神最多可使用多大的字体呢？

1 <= W, H, ai <= 1000
1 <= P <= 1000000
输入描述:

每个测试用例的输入包含两行。

第一行输入N,P,H,W

第二行输入N个数a1,a2,a3,...,an表示每个段落的文字个数。

输出描述:

对于每个测试用例，输出最大允许的字符大小S

示例1
输入
复制

1 10 4 3
10
2 10 4 3
10 10

输出
复制

3
2

备注:

以上所有输入、输出均为整数。

且所有测试用例均保证有解。

两个段落之前不空行，并且段落顶格写。

    笔记
    收藏
    纠错

 */
#ifndef UNTITLED_MAXFONT_H
#define UNTITLED_MAXFONT_H
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
// 50%....
/*
 * 用例:
10 9 720 460
100 200 300 400 500 600 700 800 50 10

对应输出应该为:

27

你的输出为:

28
 */
int f(int s, vector<int> a, int W, int P, int H){
    int sum = 0;
    for(int i = 0; i < a.size(); i++){
        sum += s * ceil(a[i] * s / float(W));
    }
    return sum - P * H;
}

int binary_search(vector<int> a, int W, int P, int H){
    int left, right, mid;
    int fmid, fmidp1;
    left = 1;
    right = W;

    while(right > left){
        mid = (left + right) / 2;
        fmid = f(mid, a, W, P, H);
        fmidp1 = f(mid + 1, a, W, P, H);
        if(fmid <= 0 and fmidp1 > 0){
            return mid;
        }
        else if (fmid > 0){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }

    }
    cout << left << ' '  << right << endl;
    return left;

}
int solve(vector<int> a, int P, int H, int W){
    return binary_search(a, W, P, H);
}

int maxFont(){
    int N, P, H, W;

    vector<int> a;
    int ai;
    while(cin >> N >> P >> H >> W){
        a.clear();
        for(int i = 0; i < N; i++){
            cin >> ai;
            a.push_back(ai);
        }
//        cout << f(28, a, W, P, H) << ' ' << f(29, a, W, P, H) << endl;
        cout << solve(a, P, H, W) << endl;
    };
    return 0;

}
#endif //UNTITLED_MAXFONT_H
