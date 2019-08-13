//
// Created by so_go on 2019/8/13.
//

#ifndef UNTITLED_RECUREXAMPLE_H
#define UNTITLED_RECUREXAMPLE_H

#include<vector>
using namespace std;
void recursive(int n, string &order){
    if(n == 0){
        return;
    }
    if(n % 2 == 0){
        recursive( (n - 2) / 2, order);
        order.push_back('2');
    }
    else{
        recursive((n - 1)/ 2, order);
        order.push_back('1');
    }
}
string machineOrder(int n){
    string res;
    recursive(n , res);
    return res;
}
#endif //UNTITLED_RECUREXAMPLE_H
