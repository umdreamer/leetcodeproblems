/**
 * leetcode: excel sheet column number
 * easy
 */
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
    Solution() {
        init();
    }
    int titleToNumber(string s) {
        return method1(s);
    }
private:
    static const int LUT_SIZE = 128;
    int lut[LUT_SIZE];
    void init() {
        memset(lut, 0, sizeof(int)*LUT_SIZE);
        int value = 1;
        for (char c='a'; c<='z'; ++c) {
            lut[c] = value;
            value++;
        }
        value = 1;
        for (char c='A'; c<='Z'; ++c) {
            lut[c] = value;
            value++;
        }

        printLut(lut, 128);
    }
    // lookup table, similar to addDigits.
    int method1(string s) {
        
        int n = s.length();
        int sum = 0;
        for (int i=n-1; i>=0; --i) {
            int coeff = pow(26, (n-1-i));
            int v = lut[s[i]] * coeff;
            sum += v; 
            printf("i=%d, n=%d,", i, n);
            printf("c=%c, coeff=%d, value=%d, sum=%d\n", s[i], coeff, v, sum);
        }
        
        printf("%s-->%d\n", s.c_str(), sum);
        return sum;
    }

    void printLut(int* lut, int size) {
        for (int i=0; i<size; ++i) {
            printf("%c=%d\n", i, lut[i]);
        }
    }
};

int main() {
    Solution sln;
    sln.titleToNumber("A");
    sln.titleToNumber("AA");
    sln.titleToNumber("AAA");
    sln.titleToNumber("BCD");
   
    return 0;
}

