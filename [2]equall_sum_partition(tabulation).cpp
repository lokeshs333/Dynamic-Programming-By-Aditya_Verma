#include<bits/stdc++.h>
using namespace std;
auto start = std::chrono::high_resolution_clock::now();
int dp[100][100];
bool knapsack(int n, vector<int>&nums, int sum)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                dp[i][j] = true;
            if (i == 0)
                dp[i][j] = false;
        }
    }
    dp[0][0] = true;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            // include
            if (nums[n - 1] <= sum)
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            // excluding
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
int main(){
    vector<int>nums={5,1,5,1,2,80,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,800};
    int sum=accumulate(nums.begin(),nums.end(),0);
    cout<<sum<<endl;
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
