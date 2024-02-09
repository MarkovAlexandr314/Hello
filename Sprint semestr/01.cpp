#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> Lomuto(vector<int> list){
    int min = list[0];
    int ind = 1;
    for (size_t i = 1; i < list.size(); i++)
    {
        if (list[i] < min){
            swap(list[i], list[ind]);
            ++ind;
        }
    }
    swap(list[0], list[--ind]);
    return list;
}

vector<int> QuickSort(vector<int> list){
    if (list.size() == 1)
        return list;
    vector<int> l1 = Lomuto(list);
    vector<int> l2 = reverse(Lomuto(list).begin(), Lomuto(list).back());


}

int main(){
    vector<int> list;
    int n;
    cin>>n;
    for(int i{0}; i<n; ++i){
        int m;
        cin>>m;
        list.push_back(m);
    }
    int min = list[0];
    int ind = 1;
    for (size_t i = 1; i < list.size(); i++)
    {
        if (list[i] < min){
            swap(list[i], list[ind]);
            ++ind;
        }
    }
    swap(list[0], list[--ind]);
       for(auto i : list)
        cout<<i<<' ';
}
