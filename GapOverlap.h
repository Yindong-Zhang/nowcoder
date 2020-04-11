//
// Created by so_go on 2020/4/1.
//

#ifndef UNTITLED_GAPOVERLAP_H
#define UNTITLED_GAPOVERLAP_H
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<algorithm>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
struct TimeStamp{
    int time;
    int type;
    bool operator < (const TimeStamp & t2){
        if(time < t2.time){
            return true;
        }
        return false;
    }
};
int calcMinStaff() {
    int n;
    cin >> n;
    vector<TimeStamp> T;
    int ts, te;
    for(int i = 0; i < n; ++i){
        cin >> ts;
//        cout << ts << endl;
        cin.get();
        cin >> te;
//        cout << te << endl;
        T.push_back({ts, 0});
        T.push_back({te, 1});
    }
    sort(T.begin(), T.end());
    int count = 0;
    int res = 0;
    for(auto &t : T){
//        cout << t.time << endl;
        if(t.type == 0){
            count++;
        }
        else{
            count--;
        }
        res = max(count, res);
    }
    return res;
}
/******************************结束写代码******************************/


int gapOverlap() {
    int res;


    res = calcMinStaff();
    cout << res << endl;

    return 0;

}

#endif //UNTITLED_GAPOVERLAP_H
