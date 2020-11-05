#include <iostream>
#include <vector>

#define vi vector<int>
#define vii vector<vi>

#define vb vector<bool>
#define vbb vector<vb>

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
void displayBool(vbb &arr)
{
    for (vb ar : arr)
    {
        for (bool n : ar)
        {
            cout << n << " ";
        }
        cout << endl;
    }
}

// recursive(memorisation)
// to print all possible subsequences

int LISmax = 0;
int longestIncreasingSubsequence_rec(vi &arr, int ei, vi &dp)
{
    if (ei == 0)
    {
        return 1;
    }

    int max_ = 1;
    for (int i = ei - 1; i >= 0; i--)
    {
        int recAns = longestIncreasingSubsequence_rec(arr, i, dp);
        if (arr[i] < arr[ei])
        {
            LISmax = max(LISmax, recAns + 1);
            max_ = max(max_, recAns + 1);
        }
    }
    // dp[ei] = max_;
    return max_;
}

// DP
vi longestIncreasingSubsequence(vi &arr)
{
    vi dp(arr.size(), 1); // by default the longest string is 1 length (of itself)
    int max_ = 1;

    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--) // can also be like for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_ = max(max_, dp[i]);
    }
    // cout << max_ << endl;     // commenting this while runnig biotonic subsequence
    return dp;
}

vi longestDecreasingSubsequence(vi &arr)
{
    vi dp(arr.size(), 1);
    int max_ = 1;

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        for (int j = i + 1; j <= arr.size() - 1; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_ = max(max_, dp[i]);
    }
    // cout << max_ << endl;    // commenting this while runnig biotonic subsequence
    return dp;
}

vi longestBiotonicSubsequence(vi &arr)
{
    vi dp(arr.size(), 1);
    int max_ = 1;

    vi LIS = longestIncreasingSubsequence(arr);
    vi LDS = longestDecreasingSubsequence(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        dp[i] = LIS[i] + LDS[i] - 1;
        max_ = max(max_, dp[i]);
    }
    cout << max_ << endl;
    return dp;
}

vi maxaximumSumIncreasingSubsequence(vi &arr)
{
    vi dp(arr.size(), 0);
    int max_ = 1;

    for (int i = 1; i < arr.size(); i++)
    {
        dp[i] = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i]) // here we are checking the largest sum present behind us
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        max_ = max(dp[i], max_);
    }
    cout << max_ << endl;
    return dp;
}

// print min num of deletion to make for make given array, a longest increasing subsequence
//* but in this code is only valid for strictly increasing subsequence
//* not valid for 8 8 8 8 8 ...type arrays
//* and this is because LIS code have a if condition like "if (arr[j] < arr[i])"
int minDeletion_01(vi &arr)
{
    vi LIS = longestIncreasingSubsequence(arr);
    int max_ = 1;

    for (int i: LIS)
    {
        max_ = max(max_, i);
    }

    return arr.size() - max_;
}

//* minDeletion code valid for all the cases
int minDeletion_02(vi &arr)
{
    vi dp(arr.size(), 1);
    int max_ = 1;

    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] <= arr[i])       //* thats how we handled all the cases
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_ = max(max_, dp[i]);
    }

    return arr.size() - max_;
}

void solve()
{
    vi arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

    vi dp;
    longestIncreasingSubsequence_rec(arr, arr.size() - 1, dp);
    cout << LISmax << endl;

    vi ans1 = longestIncreasingSubsequence(arr);
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i] << " ";
    }
    cout << endl;

    vi ans2 = longestDecreasingSubsequence(arr);
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }
    cout << endl;

    vi ans3 = longestBiotonicSubsequence(arr);
    for (int i = 0; i < ans3.size(); i++)
    {
        cout << ans3[i] << " ";
    }
    cout << endl;

    vi ans4 = maxaximumSumIncreasingSubsequence(arr);
    for (int i = 0; i < ans4.size(); i++)
    {
        cout << ans4[i] << " ";
    }
    cout << endl;

    cout << minDeletion_01(arr) << endl;
    cout << minDeletion_02(arr) << endl;
}

int main(int rags, char **argv)
{
    solve();
    return 0;
}