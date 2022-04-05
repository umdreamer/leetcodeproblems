/**
 * 217. Contains Duplicate
 * easy
**/ 

#include <cstdio>

class Solution {
public:
    bool containsDuplicate1(vector<int>& nums) {
        vector<int> duplicate;
        duplicate.push_back(nums[0]);
        
        for (int i=1; i<nums.size(); ++i)
        {
            if (findInArray(duplicate, nums[i]))
            {
                return true;
            }
            else
            {
                duplicate.push_back(nums[i]);
            }
        }
        return false;
    }
    
    bool findInArray(vector<int>& duplicate, int v)
    {
        for (int i=0; i<duplicate.size(); ++i)
        {
            if (v == duplicate[i])
            {
                return true;
            }
        }
        return false;
    }

    bool containsDuplicate2(vector<int>& nums) {
        vector<int> duplicate(nums); 
        std::sort(duplicate.begin(), duplicate.end());
        
        for (int i=1; i<duplicate.size(); ++i)
        {
            if (duplicate[i-1] == duplicate[i])
            {
                return true;
            }
        }
        return false;
    }
};

