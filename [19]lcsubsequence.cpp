#include<bits/stdc++.h>
using namespace std;
int lcs(int n,int m,string a,string b){
    if(n==0||m==0)return 0;
    
    if(a[n-1]==b[m-1])
    return 1+lcs(n-1,m-1,a,b);
    else return max(lcs(n-1,m,a,b),lcs(n,m-1,a,b));
}
int main(){
    string a="abcdgh";
    string b="abedfhr";
    int n=a.size();
    int m=b.size();
    int ans=lcs(n,m,a,b);
    cout<<"your answer is "<<ans;
    return 0;
}
