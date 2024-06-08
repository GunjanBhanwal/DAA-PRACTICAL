#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int W, int wt[], int val[], vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }

    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }

    int notTake = 0 + solve(ind - 1, W, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= W)
    {
        take = val[ind] + solve(ind - 1, W - wt[ind], wt, val, dp);
    }
    return dp[ind][W] = max(take, notTake);
}
// Function to return max value that can be put in knapsack of  W.
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    int ind = n - 1;
    return solve(ind, W, wt, val, dp);
}

int main()
{
    int wt[] = {1, 2, 4, 5};
    int val[] = {5, 4, 8, 6};
    int  = 5;
    int n = 4;

    cout << "The Maximum value of items the thief can steal is " << knapSack(, wt, val, n);

    return 0;
}
