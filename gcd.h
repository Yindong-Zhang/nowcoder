//
// Created by so_go on 2020/9/1.
//

#ifndef UNTITLED_GCD_H
#define UNTITLED_GCD_H
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a < b){
        return gcd(b, a);
    }
    while(b > 0){
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b){
    int g = gcd(a, b);
    return a * b / g;
}
#endif //UNTITLED_GCD_H
