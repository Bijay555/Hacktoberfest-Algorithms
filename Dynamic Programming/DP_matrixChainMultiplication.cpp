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
int matrixChainMultiplication_MCM(vi &arr, int si, int ei, vii &dp)
{
    if (si + 1 == ei) //* cost of multiplication of 1 matrix is zero
    {
        return 0;
    }

    if (dp[si][ei] != 0)
    {
        return dp[si][ei];
    }

    int minAns = 1e7;

    for (int cut = si + 1; cut < ei; cut++) //* first cut call can be started from (si + 1) and last  at (ei - 1)
    {
        int left = matrixChainMultiplication_MCM(arr, si, cut, dp);
        int right = matrixChainMultiplication_MCM(arr, cut, ei, dp);

        int myCost = left + (arr[si] * arr[cut] * arr[ei]) + right;

        minAns = min(minAns, myCost);
    }

    dp[si][ei] = minAns;
    return minAns;
}

int matrixChainMultiplication_MCM_01(vi &arr, int si, int ei, vii &dp)
{
    int minAns = 1e7;
    for (int cut = si + 1; cut < ei; cut++)
    {
        if (si + 1 == ei) //* cost of multiplication of 1 matrix is zero
        {
            return 0;
        }

        // for (int cut = si + 1; cut < ei; cut++) //* first cut call can be started from (si + 1) and last  at (ei - 1)
        // {
            int left = dp[si][cut];
            int right = dp[cut][ei];

            arr[cut] = left + (arr[si] * arr[cut] * arr[ei]) + right;

            minAns = min(minAns, arr[cut]);
        // }

        dp[si][ei] = minAns;
    }
    return minAns;
}

void solve()
{
    vi arr = {10, 20, 30, 40, 30};
    vii dp(arr.size(), vi(arr.size(), 0));
    cout << matrixChainMultiplication_MCM(arr, 0, arr.size() - 1, dp) << endl;
    display(dp);

    cout << matrixChainMultiplication_MCM_01(arr, 0, arr.size() - 1, dp) << endl;
    display(dp);
}

int main(int rags, char **argv)
{
    solve();
    return 0;
}