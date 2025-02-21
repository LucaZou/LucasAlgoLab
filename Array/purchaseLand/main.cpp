#include<vector>
#include<iostream>
#include <climits>
using namespace std;

int main(){
    int n,m;
    int sum = 0;
    int min=INT_MAX;
    cin >> n >> m;
    vector<vector<int>> vec(n,vector<int>(m,0));// 初始化n行m列二维矩阵
    for(int i  = 0;i<n;i++){
        for(int j =0;j<m;j++){
            cin >> vec[i][j];
            sum += vec[i][j];
        }
    }
    int t,sub=0;
    // 横向
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            sub += vec[i][j];
        }
        t = sum-2*sub;
        if(t < 0) t = -t;
        if(t < min){
            min = t;
        }
        // cout << "sum1:" <<sum << endl;
        // cout <<  "sub1:" <<sub << endl;
        // cout << "t1:" << t << endl;
        // cout << "min1:" << min << endl;
    }
    sub = 0;
    // 纵向
    for(int j=0;j<m-1;j++){
        for(int i=0;i<n;i++){
            sub += vec[i][j];
        }
        t = sum-2*sub;
        if(t < 0) t = -t;
        if(t < min){
            min = t;
        }
        // cout << "sum2:" <<sum << endl;
        // cout <<  "sub2:" <<sub << endl;
        // cout << "t2:" << t << endl;
        // cout << "min2:" << min << endl;
    }
    cout << min << endl;
    //输出vec
    // for(int i  = 0;i<n;i++){
    //     for(int j =0;j<m;j++){
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << sum << endl;
}