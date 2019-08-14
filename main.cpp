#include <iostream>
#include<vector>
#include<map>
#include<string>
#include"numberOfSpecificPairs.h"
using namespace std;

int main(){
    int k;
    long long n;
    cin >> n >> k;
    cout << numberOfPairs(n, k) << endl;
}