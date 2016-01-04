/**
 * leetcodeproblem: 322. Coin Change
 * Difficulty: Medium
 * dynamic programming
 */

#include <climits>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //vector<int> newCoins(coins);
        //return fromBigger(newCoins, amount);
        //return method2(coins, amount);
        return method3(coins, amount);
    }
    
private: 
    // method3: the dynamic programming method
    int method3(vector<int>& coins, int amount) {
        vector<int> leastCount(amount+1, INT_MAX);
        leastCount[0] = 0;
        for (int n=1; n<=amount; ++n) {
            int minCount= INT_MAX;
            //int minCoin = -1;
            for (int i=0; i<coins.size(); ++i) {
                int lessOneValue = n - coins[i];
                if (lessOneValue >= 0) {
                    if (leastCount[lessOneValue] < minCount) {
                        minCount= leastCount[lessOneValue];
                        //minCoin = i;
                        leastCount[n] = leastCount[lessOneValue] + 1;
                    }
                }
            }
            printf("f(%d)=%d\n", n, leastCount[n]);
        }
        
        if (leastCount[amount] == INT_MAX) {
            return -1;
        } else {
            return leastCount[amount];
        }
    }

    int computeSum(vector<int>& v) {
        int sum = 0;
        for (int i=0; i<v.size(); ++i) {
            sum += v[i];
        }
        return sum;
    }

    void printCoinCursors(vector<int>& coinCursors) {
        for (int i=0; i<coinCursors.size(); ++i) {
            printf("%i, ", coinCursors[i]);
        }
        printf("\n");
    }
    
    int computeValue(vector<int>& coins, vector<int>& coinCursors) {
            int totalValue = 0;
            for (int j=0; j<coins.size(); ++j) {
                totalValue += coins[j] * coinCursors[j];
            }
            return totalValue;
    }
    int method2(vector<int>& coins, int amount) {
/***
        int totalCount = 0;
        if (coins.size() == 1) {
            totalCount = amount/coins[0];
            int reducedAmount = amount % coins[0];
            if (reducedAmount == 0) {
                return totalCount;
            } else {
                return -1;
            }
        }
***/
        // find the limits of each coin.
        // then, search in the all weight*coin space, and get the 
        vector<int> coinNumberLimits(coins.size());
        for (int i=0; i<coins.size(); ++i) {
            coinNumberLimits[i] = amount / coins[i];
            printf("coin=%d, Limits=%d, amount=%d\n", coins[i], coinNumberLimits[i], amount);
        }
        
        vector<int> coinCursors(coins.size());
        int minCount = INT_MAX;

        for (;;) {
            printCoinCursors(coinCursors);

            int totalValue = computeValue(coins, coinCursors);
            printf("-->totalValue=%d, amount=%d\n", totalValue, amount);
            // do something, get the minimal count
            if (totalValue == amount) {
                int count = computeSum(coinCursors);
                printf("-------------->>count=%d, minCount=%d\n", count, minCount);
                if (count < minCount) {
                    minCount = count;
                }
                printf("-------------->>count=%d, minCount=%d\n", count, minCount);
            }
            
            int k = 0;
            for (;;) {
                if (coinCursors[k] < coinNumberLimits[k]) {
                    //int totalValue = computeValue(coins, coinCursors);
                    //if (totalValue <= amount) {
                    //    int step = (amount-totalValue) / coins[k];
                    //    coinCursors[k] += step;
                        coinCursors[k]++;
                        break;
                    //} else {
                    //    coinCursors[k] = 0;
                    //    k++;
					//    if (k >= coins.size()) {
					//	    break;
					//    }
                    //}
                }
                else {
                    coinCursors[k] = 0;
                    k++;
					if (k >= coins.size()) {
						break;
					}
                }
            }
           
            if (k >= coins.size()) {
                break;
            }
        }
        
        printf("final minCount=%d\n", minCount);
        return minCount;
    }

    int findMax(vector<int>& coins, int* index) {
        int maxValue = -1;
        for (int i=0; i<coins.size(); ++i) {
            if (coins[i] > maxValue) {
                maxValue = coins[i];
                *index = i;
            }
        }
        return maxValue;
    }
    
    int fromBigger(vector<int>& coins, int amount) {
        
        int totalCount = 0;
        int reducedAmount = amount;
        for (; coins.size() > 0; ) {
            int index = -1;
            int maxValue = findMax(coins, &index);
            totalCount += reducedAmount / maxValue;
            reducedAmount = reducedAmount % maxValue;
            coins.erase(coins.begin()+index);
            if (reducedAmount == 0) {
                break;
            }
        }
        
        if (reducedAmount != 0) {
            return -1;
        }
        return totalCount;
    }
};


int main(int argc, char** argv) {
    vector<int> coins;
    coins.push_back(3);
    coins.push_back(7);
    coins.push_back(405);
    coins.push_back(436);
    int amount = 8839;

    Solution s;
    s.coinChange(coins, amount);
}

