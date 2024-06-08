#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int n, vector<int> &mp, vector<int> &temp, vector<vector<int>> &ans)
{
    if (temp.size() == n)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!mp[i])
        {
            temp.push_back(nums[i]);
            mp[i] = 1;
            solve(nums, n, mp, temp, ans);
            // backtrack
            mp[i] = 0;
            temp.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int n = nums.size();
    vector<int> mp(n, 0);
    solve(nums, n, mp, temp, ans);
    return ans;
}

int main()
{
    vector<int> v{1, 2, 3};
    vector<vector<int>> ans = permute(v);
    cout << "All Permutations are " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
