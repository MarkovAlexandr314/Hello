#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int m, k;
    cin>>m;
    vector<long long> list;

    for(int i{0}; i<m; ++i){
        cin>>k;
        list.push_back(k);
    }
    sort(list.begin(), list.end());

    while(true){
        cin>>k;
        if(k==0){
            break;
        }
        if(list[0] < k){
            list[0] = k;
        }
        sort(list.begin(), list.end());
    }

    for(auto i : list){
        cout<<i<<' ';
    }
}