// Nikita Gautam github: @nikitaghps
// Given a value x, find the number of ways to make change for x cents, if we have infinite
// supply of each of a = { a1, a2, .. , an } valued coins. 

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n;
    int a[n]; //array of coins
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>x;  //amount x
    int dp[x+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
            if(j-a[i]>=0)
                dp[j]+=dp[j-a[i]];
        }
    }
    cout<<dp[x];
    return 0;
}