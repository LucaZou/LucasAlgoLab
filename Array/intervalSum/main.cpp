#include<iostream>
#include<vector>
using namespace std;
int main(){
    int i,n;
    cin >> n;
    vector<int> vec(n,0);
    vector<int> p(n,0);
    int sum = 0;
    for(i=0;i<n;i++){
        cin >> vec[i];
        sum += vec[i];
        p[i] = sum; 
    }
    int a,b;
    while (cin >>a >>b){
        int j;
        if(a == 0) j = p[b];
        else{
        j = p[b] - p[a-1] ;
        }
        cout << j <<endl;
    }   

    //输出两个数组
    // for(i=0;i<n;i++){
    //     cout << vec[i] << " ";
    // }
    // cout << endl;
    // for(i=0;i<n;i++){
    //     cout << p[i] << " ";
    // }
    // cout << endl;
}