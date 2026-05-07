#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefixMax(n), suffixMin(n);

        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }
        
        vector<int> ans(n);
        
        int start = 0;
        
        for (int i = 0; i < n - 1; i++) {

            if (prefixMax[i] < suffixMin[i + 1]) {
                
                int mx = prefixMax[i];
                
                for (int j = start; j <= i; j++) {
                    ans[j] = mx;
                }
                
                start = i + 1;
            }
        }

        int mx = prefixMax[n - 1];
        for (int j = start; j < n; j++) {
            ans[j] = mx;
        }
        
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    Solution obj;
    vector<int> ans = obj.maxValue(nums);
    
    for (int x : ans) {
        cout << x << " ";
    }
    
    return 0;
}