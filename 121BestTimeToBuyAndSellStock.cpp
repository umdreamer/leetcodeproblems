#include <vector>

using namespace std;

class Solution
{
public:
    // Using Dynamic Programming method.
    // The key idea of DP is to compute the values of range from 0 to i, ie. dp[0...i], then get the result of [0...N].
    int maxProfit(vector<int> &prices)
    {
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            min_price = min(min_price, prices[i]);
            max_profit = max(max_profit, prices[i] - min_price);
            // cout << "min_price=" << min_price << ",max_profit=" << max_profit << endl;
        }

        return max_profit;
    }
    // Time Limit Exceeded
    int maxProfit1(vector<int> &prices)
    {
        int min = prices[0];
        int min_day = 0;
        int max = -1;
        int max_day = -1;
        int profit = 0;
        int max_profit = 0;

        for (int i = 0; i < prices.size() - 1; ++i)
        {
            min = prices[i];
            // cout << "min=" << min << endl;

            // find max from [i, ...]
            max = -1;
            for (int j = i + 1; j < prices.size(); ++j)
            {
                if (prices[j] > max)
                {
                    max = prices[j];
                    max_day = j;
                    // cout << "max=" << max << ",max_day=" << max_day << endl;
                }
            }

            // find profit
            profit = max - min;
            if (profit > max_profit)
            {
                max_profit = profit;
            }
        }

        return max_profit;
    }
};