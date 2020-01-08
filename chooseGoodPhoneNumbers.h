//
// Created by yindong on 19-10-20.
//
/*
 *
时间限制：1秒 空间限制：32768K 热度指数：2415
本题知识点： Java工程师 C++工程师 拼多多 贪心 字符串
算法知识视频讲解
校招时部分企业笔试将禁止编程题跳出页面，为提前适应，练习时请使用在线自测，而非本地IDE。
题目描述

A 国的手机号码由且仅由 N 位十进制数字(0-9)组成。一个手机号码中有至少 K 位数字相同则被定义为靓号。A 国的手机号可以有前导零，比如 000123456 是一个合法的手机号。
小多想花钱将自己的手机号码修改为一个靓号。修改号码中的一个数字需要花费的金额为新数字与旧数字之间的差值。比如将 1 修改为 6 或 6 修改为 1 都需要花 5 块钱。
给出小多现在的手机号码，问将其修改成一个靓号，最少需要多少钱？

输入描述:

第一行包含2个整数 N、K，分别表示手机号码数字个数以及靓号至少有 K 个数字相同。
第二行包含 N 个字符，每个字符都是一个数字('0'-'9')，数字之间没有任何其他空白符。表示小多的手机号码。
数据范围：
2 <= K <= N <= 10000

输出描述:

第一行包含一个整数，表示修改成一个靓号，最少需要的金额。
第二行包含 N 个数字字符，表示最少花费修改的新手机号。若有多个靓号花费都最少，则输出字典序最小的靓号。

示例1
输入
复制

6 5
787585

输出
复制

4
777577

说明

花费为4的方案有两种：777577与777775，前者字典序更小。


 */
// 75% ....
#ifndef UNTITLED_CHOOSEGOODPHONENUMBERS_H
#define UNTITLED_CHOOSEGOODPHONENUMBERS_H
#include<string>
#include<map>
#include<vector>
#include<climits>
#include<iostream>
using namespace std;

void solve(string s, int k){
    map<int, int> count_dict;
    vector<int> numbers;
    for(char ch: s){
        auto ptr = count_dict.find(ch - '0');
        if(ptr == count_dict.end()){
            count_dict.insert({ch - '0', 1});
        }
        else{
            count_dict[ch - '0'] += 1;
        }
    }
    for(auto ptr = count_dict.begin(); ptr != count_dict.end(); ptr++){
        numbers.push_back(ptr->first);
    }
    int min_changes = INT_MAX;
    string min_string;
    for(int i = 0; i < numbers.size(); i++){
        cout << numbers[i] << endl;
        char goodChar = '0' + numbers[i];
        int count_sum = count_dict[numbers[i]];
        int change_distance = 0;
        string s_copy = s;
        int l = i - 1, r = i + 1;
        int num;
        while(count_sum < k){
            if( l >= 0 and r < numbers.size()){
                if((numbers[i] - numbers[l]) > (numbers[r] - numbers[i])){
                    num = numbers[r];
                    r++;

                }
                else{
                    num = numbers[l];
                    l--;
                }
            }
            else if(l < 0){
                num = numbers[r];
                r++;
            }
            else{
                num = numbers[l];
                l--;
            }
            cout << ' ' << num << ' ' << l << ' ' << r << endl;
            int count2change = min(k - count_sum, count_dict[num]);
            count_sum += count2change;
            change_distance += count2change * abs(num - numbers[i]);

            int count = 0;
            if(num > numbers[i]){
                for(int j = 0; j < s_copy.size(); j++){
                    if(s_copy[j] == '0' + num){
                        s_copy[j] = goodChar ;
                        count++;
                        if(count == count2change){
                            break;
                        }
                    }
                }
            }
            else{
                for(int j = s_copy.size() - 1; j >= 0; j--){
                    if(s_copy[j] == '0' + num){
                        s_copy[j] = goodChar;
                        count++;
                        if(count == count2change){
                            break;
                        }
                    }
                }
            }

        }
        if(change_distance < min_changes){
            min_changes = change_distance;
            min_string = s_copy;
        }

    }
    cout << min_changes << endl << min_string << endl;

}

int chooseGoodNumbers(){
    int N, K;
    string s;
    cin >> N >> K;
    cin >> s;
    solve(s, K);
    return 0;
}
#endif //UNTITLED_CHOOSEGOODPHONENUMBERS_H
