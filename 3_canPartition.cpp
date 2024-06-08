#include <bits/stdc++.h>
using namespace std;

bool solve(int ind, vector<int> &arr, int sum, vector<vector<int>> &dp)
{
    if (sum == 0)
    {
        return true;
    }
    if (ind == 0)
    {
        return arr[0] == sum;
    }
    if (dp[ind][sum] != -1)
    {
        return dp[ind][sum];
    }
    bool notTake = solve(ind - 1, arr, sum, dp);
    bool take = false;
    if (arr[ind] <= sum)
    {
        take = solve(ind - 1, arr, sum - arr[ind], dp);
    }
    return dp[ind][sum] = take || notTake;
}
bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    int ind = n - 1;
    return solve(ind, arr, sum, dp);
}

bool canPartition(vector<int> &arr)
{
    int n = arr.size();
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    if (totalSum % 2 == 1)
        return false;

    int target = totalSum / 2;

    return isSubsetSum(arr, target);
}

int main()
{
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();

    if (canPartition(arr))
        cout << "The Array can be partitioned into two equal subsets";
    else
        cout << "The Array cannot be partitioned into two equal subsets";

    return 0;
}
