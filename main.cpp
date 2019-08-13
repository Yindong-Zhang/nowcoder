#include <iostream>
#include<vector>
#include<map>
#include<string>
#include"ReverseOrderNumber.h"
using namespace std;

int main(){
    long long n;
    cin >> n;
    string res = inverseNumber(n);
    cout << res << endl;
}