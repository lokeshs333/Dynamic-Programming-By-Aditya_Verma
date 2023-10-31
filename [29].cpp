// "Print shortest common Supersequence"
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
string lcs(int n, int m, string a, string b){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0)dp[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(a[i-1]==b[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    // return dp[n][m];
    string ans="";
    int i=n;
    int j=m;
    while(i!=0 || j!=0) {
    if (a[i-1] == b[j-1]) {
        ans.push_back(a[i-1]);  // Corrected
        i--;
        j--;
    } else if (dp[i][j-1] > dp[i-1][j]) {
        ans.push_back(b[j-1]);  // Corrected
        j--;
    } else {
        ans.push_back(a[i-1]);  // Corrected
        i--;
    }
}

    return ans;
}

int main() {
    string a = "agbcba";
    string b=a;
    int n = a.size();
    int m = b.size();
    string ans = lcs(n, m, a, b);
    cout << "Print shortest common Supersequence " <<ans << endl;
    return 0;
}
