//
// Created by so_go on 2019/8/14.
//

/*
 * 题目描述
为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你。
输入描述:

每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
保证不存在两项工作的报酬相同。

输出描述:

对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。

示例1
输入
复制

3 3
1 100
10 1000
1000000000 1001
9 10 1000000000

输出
复制

100
1000
1001


 */
#ifndef UNTITLED_FINDSUITABLEJOB_H
#define UNTITLED_FINDSUITABLEJOB_H

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
struct Work{
    int level;
    int payment;
    bool operator<(Work b){
        return level < b.level;
    };
};
int binary_search(vector<int> &levels, int cap){
    int left = 0, right = levels.size() - 1, mid, index;
    while(right > left){
        cout  << 'b' << ' ' << left << ' '  << right << endl;
        mid = (left + right) / 2;
        if(levels[mid] <= cap and cap < levels[mid + 1]){
            return mid;
        }
        else if (cap < levels[mid]){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}
int findSuitable(vector<int> &levels, vector<int> &max_pay, int cap){
    int maxPay = 0;
    int i = 0;
    int index = binary_search(levels, cap);
    cout << "index: " << index << endl;
    return max_pay[index];
}
int solve(vector<Work> works, int cap){
    vector<int> levels;
    sort(works.begin(), works.end());
    for(int i = 0; i < works.size(); i++){
        levels.push_back(works[i].level);
    }
    int cur_max = 0;
    vector<int> max_pay;
    for(int i = 0; i < works.size(); i++){
        if(works[i].payment > cur_max){
            cur_max= works[i].payment;
        }
        max_pay.push_back(cur_max);
    }

//    for(int i = 0; i < works.size(); i++){
//        cout << levels[i] << ' ' << max_pay[i] << endl;
//    }


    return findSuitable(levels, max_pay, cap);
}
#endif //UNTITLED_FINDSUITABLEJOB_H
