/**
 * leetcode: Range Sum Query - Immutable
 * difficulty: medium
 * tags: dynamic proramming
 */

#include <cstdio>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        for (int i=0; i<nums.size(); ++i) {
            nums_.push_back(nums[i]);
            sum_.push_back(0);
        }
        for (int i=1; i<nums_.size(); ++i) {
            sum_[i] = sum_[i-1] + nums_[i];
        }
    }

    int sumRange(int i, int j) {
        int s = (sum_[j] - sum_[i] + nums_[i]);
        printf("s=%d\n", s);
        return s; 
    }
private:
    vector<int> nums_;
    vector<int> sum_;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main(int argc, char** argv) {
    int nums1[] = {1,2,3,4,5,6};
    vector<int> nums(nums1, nums1+6);

    NumArray numArray(nums);
    numArray.sumRange(0, 1);
    numArray.sumRange(1, 2);

    return 0;
}

