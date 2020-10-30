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

// tabulation is possible
// memorisation is not possible
vbb isPalindromicSubstring(string str)
{
    vbb dp(str.length(), vb(str.length(), false));

    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = true;
            }
            else if (str[i] == str[j])
            {
                if (gap == 1)
                {
                    dp[i][j] = true;
                }
                else if (dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                }
            }
        }
    }
    return dp;
}

// to calcuate length
// dp = tabulation
int longestPalindromicSubstring(string str, vii &dp)
{
    vbb isPali = isPalindromicSubstring(str);
    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (str[i] == str[j] && gap == 1)
            {
                dp[i][j] = 2;
            }
            else if (str[i] == str[j] && isPali[i + 1][j - 1])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][str.length() - 1];
}

//* dp
int longestLengthPalindromicSubsequence(string str, vii &dp)
{
    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 1;

            else if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;

            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][str.length() - 1];
}

int countLongestPalindromicSubsequence(string str, vii &dp)
{
    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 1;

            else if (str[i] == str[j])
            {
                dp[i][j] += dp[i + 1][j - 1] + 1;                           // when both first and last character is included.
                dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]; // when one character is included from first and last at a time.
            }

            else
            {
                dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }
    return dp[0][str.length() - 1];
}

void solve()
{
    string str = "abccbdefeg";
    // string str = "abcbd";

    //// to check which part of string is palindrome

    // vbb ans = isPalindromicSubstring(str);
    // for (int i = 0; i < str.length(); i++)
    // {
    //     for (int j = 0; j < str.length(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //// to return the lasrgest string of palindrom

    // vii dp(str.length(), vi(str.length(), 0));
    // cout << longestPalindromicSubstring(str, dp) << endl;
    // display(dp);

    //// to return the largest length of palindromic subsequence

    // vii dp(str.length(), vi(str.length(), 0));
    // cout << longestLengthPalindromicSubsequence(str, dp) << endl;
    // display(dp);

    //// to return the count of lomgest palindromic subsequence

    // vii dp(str.size(), vi(str.size(), 0));
    // cout << countLongestPalindromicSubsequence(str, dp) << endl;
    // display(dp);
}

int main(int rags, char **argv)
{
    solve();
    return 0;
}