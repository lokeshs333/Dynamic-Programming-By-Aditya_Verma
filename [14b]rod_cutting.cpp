#include<bits/stdc++.h>
using namespace std;
auto start = chrono::high_resolution_clock::now();
int dp[100][100];
int knapsack(int n,vector<int>&weight,vector<int>&profit,int capacity){
    if(n==0)return 0;
    if(capacity==0)return 0;
    if(dp[n][capacity]!=-1)return dp[n][capacity];
    // including the element
    if(weight[n-1]<=capacity)
    return dp[n][capacity]= max(profit[n-1]+knapsack(n,weight,profit,capacity-weight[n-1]),knapsack(n-1,weight,profit,capacity));
    // excluding the element
    else return dp[n][capacity]= knapsack(n-1,weight,profit,capacity);
}
int main(){
    vector<int>profit={5,4,9,1};
    vector<int>weight= {1,2,3,4};
    memset(dp,-1,sizeof(dp));
    int n=profit.size(); 
    int capacity=n;
    int ans=knapsack(n,weight,profit,capacity);
    cout<<"your answer is "<<ans<<endl;
        auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}
