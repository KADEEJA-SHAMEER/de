#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1); // Add 1 at the beginning
        nums.push_back(1); // Add 1 at the end
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for (int len = 1; len <= n; len++) { // Length of subarrays
            for (int left = 1; left <= n - len + 1; left++) {
                int right = left + len - 1;
                for (int i = left; i <= right; i++) {
                    dp[left][right] = max(dp[left][right],
                        nums[left - 1] * nums[i] * nums[right + 1] + dp[left][i - 1] + dp[i + 1][right]);
                }
            }
        }
        
        return dp[1][n];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, 5, 8};
    cout << "Maximum coins: " << sol.maxCoins(nums) << endl;
    return 0;
}
