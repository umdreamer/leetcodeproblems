#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        vector<int> max_sum(nums.size());
        max_sum[0] = nums[0];
        int global_max_sum = nums[0];
        
        if (nums.size() ==1) 
        {
            return nums[0];
        }
        
        for (int i=1; i<nums.size(); ++i)
        {
            if (max_sum[i-1] > 0)
            {
                max_sum[i] = max_sum[i-1] + nums[i];
            }
            else
            {
                max_sum[i] = nums[i];
            }
            
            if (max_sum[i] > global_max_sum)
            {
                global_max_sum = max_sum[i];
            }
        }
        
        return global_max_sum;
        
    }
};
