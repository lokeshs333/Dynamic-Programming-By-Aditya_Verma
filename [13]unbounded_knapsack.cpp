#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, vector<int>& weight,vector<int>&profit, int capacity) {
    if(n==0)return 0;
    if(capacity==0)return 0;
    
    if(weight[n-1]<=capacity){
        return max(profit[n-1]+knapsack(n,weight,profit,capacity-weight[n-1]),knapsack(n-1,weight,profit,capacity));
    }
    else return knapsack(n-1,weight,profit,capacity);
}

int main() {
    vector<int> weight = {1,3,4,5};
    vector<int>val={1,4,5,7};
    int capacity=10;
    int n = val.size();
    int answer = knapsack(n,weight,val,capacity);
    cout << "Your answer is " << answer << endl;

    return 0;
}
