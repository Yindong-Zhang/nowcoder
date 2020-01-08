//
// Created by yindong on 19-9-11.
//

#ifndef UNTITLED_UPPERBOUND_H
#define UNTITLED_UPPERBOUND_H
#include<vector>
#include<sstream>
#include<iostream>
using namespace std;
/*
 *  以下函数使用二分查找搜索一个增序的数组，当有多个元素值与目标元素相等时，返回最后一个元素的下标，目标元素不存在时返回-1。请指出程序代码中错误或不符最佳实践的地方（问题不止一处，请尽量找出所有你认为有问题的地方）

int BinarySearchMax(const std::vector<int>& data, int target)

{

   int left = 0;

   int right = data.size();

   while (left < right) {

       int mid = (left + right) / 2;

       if (data[mid] <= target)

           left = mid + 1;

       else

           right = mid - 1;

   }

   if (data[right] == target)

       return right;

   return -1;

}
 */
int BinarySearchMax_std(const vector<int>& data, int target)
{
    int left = 0;
    int right = data.size()-1; //修改1
    while(left < right) {
        int mid = left+(right-left+1)/2;     //修改2：防止整形溢出；使用偏右的中值
        if(data[mid] <= target)
            left = mid;                      //修改3
        else
            right = mid - 1;
    }
    if(data[right] == target)
        return right;
    return-1;
}

int BinarySearchMax(const std::vector<int>& data, int target)
{
    int left = 0;
    int right = data.size();
    while (left + 1 < right) {
        cout << left << ' ' << right << endl;
        int mid = (left + right) / 2;
        if (data[mid] <= target)
            left = mid + 1;
        else if(data[mid - 1] <= target and target < data[mid]){
            return mid;
        }
        else{
            right = mid;
        }
    }
    return left;
}

int solve(vector<int> data, int target){
    int ind = BinarySearchMax(data, target);
    if(data[ind - 1] == target){
        return ind - 1;
    }
    else{
        return -1;
    }
}
int upperBound(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> v;
    int vi, target;
    while(ss >> vi){
        v.push_back(vi);
    }
    cin >> target;
    cout << solve(v, target) << endl;
    return 0;

}
#endif //UNTITLED_UPPERBOUND_H
