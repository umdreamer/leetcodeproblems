#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index(2);
        for (int i=0; i<nums.size(); ++i)
        {
            int diff = target - nums[i];
            for (int j=i+1; j<nums.size(); ++j)
            {
                if (diff == nums[j])
                {
                    index[0] = i;
                    index[1] = j;
                    return index;
                }
            }
        }
        return index;
    }
};

