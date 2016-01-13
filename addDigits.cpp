/**
 * leetcode: add digits
 * easy
 */

#include <cstdio>

class Solution {
public:
    int addDigits(int num) {
        return method2(num);
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
    int method1(int num) {
        int n = num;
        int digitSum = 0;
        for (;;) {
            for (;;) {
                digitSum += n % 10;
                n /= 10;
                if (n ==0) {
                    break;
                }
            }
            if (digitSum < 10) {
                return digitSum;
            } else {
                n = digitSum;
                digitSum = 0;
            }
        }
    }
};

int main() {
    Solution s;
    for (int i=0; i<9999999; ++i) {
        int result = s.addDigits(i);
        printf("%d --> %d, div9=%d, mod9=%d\n", i, result, i/9, i%9);
    }
    
    return 0;
}
