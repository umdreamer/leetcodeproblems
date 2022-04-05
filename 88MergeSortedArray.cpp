#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        while (j >= 0)
        {
            if (i >= 0)
            {
                if (nums2[j] >= nums1[i])
                {
                    nums1[i + 1 + j] = nums2[j];
                    --j;
                }
                else
                {
                    nums1[i + 1 + j] = nums1[i];
                    --i;
                }
            }
            else
            {
                nums1[j] = nums2[j];
                --j;
            }
        }
    }
};