#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include<string>

int LastNumber(int n){
    int a{0}, b{1}, c{0};
    static int sum{0}; 
    for(int i{0};i<n;++i){
        c = a+b;
        a = b;
        b = c;
        sum+=c;
    }
    return sum%10;
}

using namespace std;
int main(){
    int a;
    cin>>a;
    cout<<LastNumber(a)<<endl;
}