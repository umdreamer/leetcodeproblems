/**
 * leetcode: valid anagram
 * easy
 */

#include <cstdio>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return computeHistogram(nums);
    }
private:
    bool computeHistogram(vector<int>& nums) {
        map<int, int> hist;
        for (int i=0; i<nums.size(); ++i) {
            hist[nums[i]]++;
            if (hist[nums[i]] >=2) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    Solution sln;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);

    printf("%d\n", sln.containsDuplicate(nums));
}

