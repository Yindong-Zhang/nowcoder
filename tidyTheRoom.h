//
// Created by so_go on 2019/8/16.
//
/*
 * 题目描述
又到了周末，小易的房间乱得一团糟。
他希望将地上的杂物稍微整理下，使每团杂物看起来都紧凑一些，没有那么乱。
地上一共有n团杂物，每团杂物都包含4个物品。第i物品的坐标用(ai,bi)表示，小易每次都可以将它绕着(xi,yi)逆时针旋转90∘90^ \circ90∘，这将消耗他的一次移动次数。如果一团杂物的4个点构成了一个面积不为0的正方形，我们说它是紧凑的。
因为小易很懒，所以他希望你帮助他计算一下每团杂物最少需要多少步移动能使它变得紧凑。
输入描述:

第一行一个数n(1 <= n <= 100)，表示杂物的团数。
接下来4n行，每4行表示一团杂物，每行4个数ai, bi，xi, yi, (-104 <= xi, yi, ai, bi <= 104)，表示第i个物品旋转的它本身的坐标和中心点坐标。

输出描述:

n行，每行1个数，表示最少移动次数。

示例1
输入
复制

4
1 1 0 0
-1 1 0 0
-1 1 0 0
1 -1 0 0
1 1 0 0
-2 1 0 0
-1 1 0 0
1 -1 0 0
1 1 0 0
-1 1 0 0
-1 1 0 0
-1 1 0 0
2 2 0 1
-1 0 0 -2
3 0 0 -2
-1 1 -2 0

输出
复制

1
-1
3
3

说明

对于第一团杂物，我们可以旋转第二个或者第三个物品1次。


 */
#ifndef UNTITLED_TIDYTHEROOM_H
#define UNTITLED_TIDYTHEROOM_H
#include<iostream>
#include<valarray>
#include<vector>
using namespace std;
// TODO: 好麻烦。。。
bool isEqual(valarray<int> a, valarray<int> b){
    if(a.size() != b.size()){
        return false;
    }
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}
bool isSquare(valarray<int> a, valarray<int> b, valarray<int> c, valarray<int> d){
    valarray<int> mean = (a + b + c + d) / 4;
    auto da  = a - mean;
    auto db = b - mean;
    auto dc = c - mean;
    auto dd = d - mean;
    vector<bool> j(3, false);
    bool isFind = false;
    for(int i = 0; i < 3; i++){
        isFind = false;
        int x = da[0], y = da[1];
        valarray<int> da = {-y, x};
        if(isEqual(da, d|b)){
            isFind= true;
            j[0] = true;
        }
        else if(isEqual(da, dc)){
            isFind = true;
            j[1] = true;
        }
        else if(isEqual(da, dd)){
            isFind = true;
            j[2] = true;
        }

        if(not isFind){
            return false;
        }
    }
    if(j[0] and j[1] and j[2]){
        return true;
    }
    else{
        return false;
    }
}
vector<valarray<int>> rotate(valarray<int> point, valarray<int> pivot){
    vector<valarray<int>> res;
    auto shift  = point - pivot;
    res.push_back(point);
    res.push_back(pivot + valarray<int>{-point[1], point[0]});
    res.push_back(pivot + valarray<int>{-point[0], -point[1]});
    res.push_back(pivot + valarray<int>{point[1], -point[0]});
    return res;

}
int solve(valarray<int> points[4], valarray<int> pivots[4]){
    vector<valarray<int>> pVec_1 = rotate(points[0], pivots[0]);
    vector<valarray<int>> pVec_2 = rotate(points[1], pivots[1]);
    vector<valarray<int>> pVec_3 = rotate(points[2], pivots[2]);
    vector<valarray<int>> pVec_4 = rotate(points[3], pivots[3]);
    bool isFind = false;
    int n;
    for(n = 0; n <= 12; n++){
        for(int i = 0; i < 4 and i <= n; i++){
            for(int j = 0; j < 4 and j <= n - i; j++){
                for(int k = 0; k < 4 and k <= n - i - j; k++){
                    int l = n - i - j - k;
                    if(l < 4){
                        if(isSquare(pVec_1[i], pVec_2[j], pVec_3[k], pVec_4[l])){
                            isFind = true;
                            break;
                        }
                    }
                }
                if(isFind){
                    break;
                }
            }
            if(isFind){
                break;
            }
        }
        if(isFind){
            break;
        }
    }
    if(isFind){
        return n;
    }
    else{
        return -1;
    }
}
int tidyTheRoom(){
    int n_sample;
    valarray<int> points[4], pivots[4];
    for(int i = 0; i < 4; i++){
        points[i] = valarray<int>(2);
        pivots[i] = valarray<int>(2);
    }
    int x, y, px, py;
    cin >> n_sample;
    for(int i = 0; i < n_sample; i++){
        for(int item = 0; item < 4; item++){
            cin >> x >> y >> px >> py;
            points[i][0] = x;
            points[i][1] = y;
            pivots[i][0] = px;
            pivots[i][1] = py;
        }
        cout << solve(points, pivots) << endl;
    }
}
#endif //UNTITLED_TIDYTHEROOM_H
