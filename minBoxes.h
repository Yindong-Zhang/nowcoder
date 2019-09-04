//
// Created by yindong on 19-9-4.
//

#ifndef UNTITLED_MINBOXES_H
#define UNTITLED_MINBOXES_H

#include<iostream>
using namespace std;

int solve(int n){
    int div9 = n / 9;
    int res9 = n % 9;
    switch(res9){
        case 0:
            return div9;
        case 1:
            if(div9 >= 3){
                return div9 + 4;
            }
            else{
                return -1;
            }
        case 2:
            if(div9 >= 2){
                return div9 + 3;
            }
            else{
                return -1;
            }
        case 3:
            if(div9 >= 1){
                return div9 + 2;
            }
            else{
                return -1;
            }
        case 4:
            return div9 + 1;
        case 5:
            if(div9 >= 3){
                return div9 + 5;
            }
            else{
                return -1;
            }
        case 6:
            if(div9 >= 2){
                return div9 + 4;
            }
            else{
                return -1;
            }
        case 7:
            if(div9 >= 1){
                return div9 + 3;
            }
            else{
                return -1;
            }
        case 8:
            return div9 + 2;
    }
}

int minBoxes(){
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif //UNTITLED_MINBOXES_H
