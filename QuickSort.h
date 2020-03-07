//
// Created by so_go on 2020/3/4.
//
/*
 * 记录快排的几种写法
 */
#ifndef UNTITLED_QUICKSORT_H
#define UNTITLED_QUICKSORT_H
#include<bits/stdc++.h>
#include"printVector.h"
using namespace std;

// 一轮快排
template <class T>
int partition_1(vector<T> &nums, int l, int r){
    // 快排返回pivot节点最终的位置，供递归调用
    T pivot= nums[l];
    int i = l, j = r;
    while(i < j){
        while(i < j and nums[j] >= pivot){
            j--;
        }
        if(i < j){
            nums[i] = nums[j];
        }
        while(i < j and nums[i] < pivot){
            i++;
        }
        if(i < j){
            nums[j] = nums[i];
        }
        printVector(nums);
    }

    nums[i] = pivot;
    return i;
}

template<class T>
int partition_2(vector<T> &nums, int l, int r){
    T pivot = nums[l];
    int i = l + 1, j = r;
    while(i - 1 < j){
        if(nums[i] >= pivot){
            swap(nums[i], nums[j]);
            j--;
        }
        else{
            nums[i - 1] = nums[i];
            i++;
        }
        cout << i << ' ' << j << ' ';
        printVector(nums);
    }
    nums[i-1] = pivot; // 弄清楚概念，i为当前需要判断的数位，i - 1为需要填充的数位
    return i - 1;
}

template<class T>
void quickSort(vector<T> &nums, int l, int r){
    if(l >= r){
        return;
    }
    int ind_pivot = partition_2<T>(nums, l, r);
    quickSort<T>(nums, l, ind_pivot - 1);
    quickSort<T>(nums, ind_pivot + 1, r);
}


#endif //UNTITLED_QUICKSORT_H
