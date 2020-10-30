
//? in this type of questions memorisation is fater than dp bcz in memorisation we are savig a
//? call to occur and in dp we are traversing some indexes for no reason

#include <iostream>
#include <vector>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

void display1D(vi &ar)
{
    for (int n : ar)
    {
        cout << n << " ";
    }
    cout << endl;
}

void display2D(vii &arr)
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

// recursive
int knapSack_bounded_01(int idx, vi &cost, vi &weight, int capacity, vii &dp)
{
    if (idx == -1)
    {
        return 0;
    }

    if (dp[idx][capacity] != 0)
    {
        return dp[idx][capacity];
    }

    int contribute = 0, notContribute = 0;
    if (capacity - weight[idx] >= 0) // we dont check for capacity to be negetive in base case due to this check
    {
        contribute = knapSack_bounded_01(idx - 1, cost, weight, capacity - weight[idx], dp) + cost[idx]; // added the cost/cost at last
    }
    notContribute = knapSack_bounded_01(idx - 1, cost, weight, capacity, dp);

    return dp[idx][capacity] = max(contribute, notContribute);
}

// dp
int knapSack_bounded_02(vi &cost, vi &weight, int capacity, vii &dp)
{
    for (int idx = 1; idx < dp.size(); idx++) // we are starting loop from 1 means we have already made dp array of (size + 1)
    {
        int weightIdx = idx - 1;
        for (int cap = 0; cap <= capacity; cap++)
        {
            //* actual idx is idx-1 but in dp we considered is idx
            int contribute = 0, notContribute = 0;
            if (cap - weight[weightIdx] >= 0)
            {
                contribute = dp[idx - 1][cap - weight[weightIdx]] + cost[weightIdx]; // so we use idx while using in dp but we use weightIdx when we are checking
            }
            notContribute = dp[idx - 1][cap];

            dp[idx][cap] = max(contribute, notContribute);
        }
    }
    return dp[dp.size() - 1][dp[0].size() - 1];
}

// DP only
// this method is btr bcz here we only have to use 1D dp
int knapSack_unbounded(vi &cost, vi &weight, int capacity)
{
    vi dp(capacity + 1, -1); //-1 by default
    dp[0] = 0;

    for (int i = 1; i < weight.size(); i++)
    {
        for (int cap = 0; cap <= capacity; cap++)
        {
            if (cap - weight[i] >= 0)
            {
                int picked = dp[cap - weight[i]] + cost[i];
                int unpicked = dp[cap];
                dp[cap] = max(picked, unpicked);
            }
        }
    }
    display1D(dp);
    return dp[capacity];
}

void solve()
{
    vi cost = {15, 14, 10, 45, 30};
    vi weight = {2, 5, 1, 3, 4};
    int capacity = 7;

    //* one method : without increasing the size of dp
    // vii dp(weight.size(), vi(capacity + 1, 0));
    // cout << knapSack_bounded_01(weight.size() - 1, cost, weight, capacity, dp) << endl;
    // display2D(dp);

    //* two method : with increasing the size of dp by 1
    // vii dp(weight.size() + 1, vi(capacity + 1, 0));
    // cout << knapSack_bounded_02(cost, weight, capacity, dp) << endl;
    // display2D(dp);

    //* unbounded same as combination with repetation of coins
    cout << knapSack_unbounded(cost, weight, capacity) << endl;
}

int main(int rags, char **argv)
{
    solve();
    return 0;
}