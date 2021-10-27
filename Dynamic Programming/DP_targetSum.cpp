
//? in this type of questions memorisation is fater than dp bcz in memorisation we are savig a
//? call to occur and in dp we are traversing some indexes for no reason

#include <iostream>
#include <vector>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

void display(vii &arr)
{
    for (vi ar : arr)
    {
        for (int n : ar)
        {
            cout << n << " ";
        }
        cout << endl;
    }
}

//* memorisation
//! again check for answer matrix
int targetSum_01(int idx, int tar, vi &arr, vii &dp)
{
    if (tar == 0 || idx < 0)
    {
        return tar == 0 ? 1 : 0;
    }

    if (dp[idx][tar] != 0)
    {
        return dp[idx][tar];
    }

    int count = 0;
    if (tar - arr[idx] >= 0)
    {
        count += targetSum_01(idx - 1, tar - arr[idx], arr, dp);
    }
    count += targetSum_01(idx - 1, tar, arr, dp);

    return dp[idx][tar] = count;
}

//* DP
int targetSum_02(int tar, vi &arr, vii &dp)
{
    dp[0][0] = 1; 
    for (int i = 1; i < arr.size(); i++)
    {
        for (int t = 0; t <= tar; t++)
        {
            if (t == 0)
            {
                dp[i][t] = 1;
                continue;
            }

            if (t >= arr[i])
            {
                dp[i][t] += dp[i - 1][t - arr[i]];
            }
            dp[i][t] += dp[i - 1][t];
        }
    }
    return dp[arr.size() - 1][tar];
}

void solve()
{
    vi arr = {0, 2, 3, 5, 7};       // initially put zero to handle the base case
    int tar = 10;
    vii dp(arr.size(), vi(tar + 1, 0));
    cout << targetSum_01(arr.size() - 1, tar, arr, dp) << endl; // if we are starting idx from last then answer will be printed in bottom right corner but if we start the idx from 0 then over answer will occur in top right corner
    display(dp);
    cout << targetSum_02(tar, arr, dp) << endl;
    display(dp);
}

int main(int rags, char **argv)
{
    solve();
    return 0;
}