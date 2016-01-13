/**
 * leetcode: happy number 
 * easy
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        return method1(n);
    }
private:
// non loop method
    int method2(int num) {
        if (num < 10) {
            return num;
        }
        
        int div9 = num / 9;
        int mod9 = num % 9;
        if (mod9 != 0) {
            return mod9;
        } else {
            return 9;
        }
    }
    
    // loop method
    bool method1(int num) {
        //printf("------\n");
        int n = num;
        int digitSquareSum = 0;
        vector<int> loopNumbers;
        for (;;) {
            int number = n;
            //printf("%d-->", number);
            for (;;) {
                int digit = n % 10;
                digitSquareSum += digit * digit;
                n /= 10;
                if (n ==0) {
                    break;
                }
            }
            //printf("=%d\n", digitSquareSum);
            if (digitSquareSum == 1) {
                break;
            } else {
                //printf("number=%d, digitSquareSum=%d\n", number, digitSquareSum);
                if (std::find(loopNumbers.begin(), loopNumbers.end(), digitSquareSum) != loopNumbers.end()) {
                    break;
                } else {
                    loopNumbers.push_back(digitSquareSum);
                }

                n = digitSquareSum;
                digitSquareSum = 0;
            }
        }
        printf("num=%d --> %d\n", num, digitSquareSum);
        if (digitSquareSum == 1) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution s;
    for (int i=1; i<99999; ++i) {
        bool result = s.isHappy(i);
        //printf("%d --> %d, div9=%d, mod9=%d\n", i, result, i/9, i%9);
    }
    
    return 0;
}
