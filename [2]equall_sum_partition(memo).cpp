#include<bits/stdc++.h>
using namespace std;
auto start = std::chrono::high_resolution_clock::now();
int dp[100][100];
bool knapsack(int n,vector<int>&nums,int sum){
    if(n==0)return false;
    if(sum==0)return true;
    
    if(dp[n][sum]!=-1)return dp[n][sum];
    
    if(nums[n-1]<=sum){
        return dp[n][sum]= knapsack(n-1,nums,sum-nums[n-1])||knapsack(n-1,nums,sum);
    }
    else return dp[n][sum]= knapsack(n-1,nums,sum);
}
int main(){
    vector<int>nums={5,7,11,5,2,100};
    int sum=accumulate(nums.begin(),nums.end(),0);
    // cout<<sum;
    if(sum%2==1){cout<<"NOT POSSIBLE";return false;}
    int n=nums.size();
    memset(dp,-1,sizeof(dp));
    bool answer=knapsack(n,nums,sum/2);
    cout<<"your answer is "<<answer<<endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Compilation time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}
