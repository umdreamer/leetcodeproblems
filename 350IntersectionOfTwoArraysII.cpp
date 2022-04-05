#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        vector<int> *num_short_p = &nums1;
        vector<int> *num_long_p = &nums2;
        if (nums1.size() > nums2.size())
        {
            num_short_p = &nums2;
            num_long_p = &nums1;
        }

        vector<int> &num_short = *num_short_p;
        vector<int> &num_long = *num_long_p;

        int n = num_long.size();

        for (int i = 0; i < num_short.size(); ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (num_short[i] == num_long[j])
                {
                    result.push_back(num_short[i]);
                    // swap with the last one
                    int temp = num_long[j];
                    num_long[j] = num_long[n - 1];
                    num_long[n - 1] = temp;

                    // make sure to search from [0, n]
                    --n;
                    break;
                }
            }
        }
        return result;
    }
};