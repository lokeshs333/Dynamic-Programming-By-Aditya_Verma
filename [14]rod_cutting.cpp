#include<bits/stdc++.h>
using namespace std;
int knapsack(int n,vector<int>&weight,vector<int>&profit,int capacity){
    if(n==0)return 0;
    if(capacity==0)return 0;
    
    // including the element
    if(weight[n-1]<=capacity)
    return max(profit[n-1]+knapsack(n,weight,profit,capacity-weight[n-1]),knapsack(n-1,weight,profit,capacity));
    // excluding the element
    else return knapsack(n-1,weight,profit,capacity);
}
int main(){
    vector<int>profit={5,4,9,1};
    vector<int>weight= {1,2,3,4};
    int n=profit.size(); 
    int capacity=n;
    int ans=knapsack(n,weight,profit,capacity);
    cout<<"your answer is "<<ans;
    return 0;
}
