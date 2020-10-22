//Nikita Gautam github: @nikitaghps
//C++ program to calculate and print true or false, if there is a subset the elements of which adds up to a specific target or not.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>x;

    // Create a bool type dp array.
    bool dp[n+1][x+1];

    // Set the first column of the dp array to be true. 
    for(int i=0;i<=n;i++)
    dp[i][0]=true;
    
    // Set the first row of the dp array to be false. 
    for(int j=1;j<=x;j++)
    dp[0][j]=false;
    
    // Traverse through the dp array
    for(int i=1;i<=n;i++){

        for(int j=1;j<=x;j++){

            // Check if the element on the immediate top of dp[i][j] is true. If true, set dp[i][j] to true.
            if(dp[i-1][j]==true)
            dp[i][j]=true;
            // Else check if j-a[i-1]>=0
            else{
                if(j-a[i-1]>=0){
                    // If true, check if dp[i-1][j-a[i-1]] is true.
                    if(dp[i-1][j-a[i-1]]==true)
                        // If true, set dp[i][j] to true.
                        dp[i][j]=true;
                    else 
                        // Else, set dp[i][j] to false.
                        dp[i][j]=false;
                }
                else dp[i][j]=false;
            }
        }
    }
    (dp[n][x])?cout<<"true":cout<<"false";
    return 0;
}