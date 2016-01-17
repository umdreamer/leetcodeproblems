/**
 * leetcode: ugly number
 * easy
 */

#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
       bool ugly = method1(num); 
       printf("%d --> %d\n", num, ugly);
       return ugly; 
    }
private:
    bool method1(int num) {
        bool ugly = false;
        if (num <= 0) {
            return false;
        }
        if (num == 1) {
            return true;
        }
        int n = num;
        printf("%d=", n);
        while (n > 0) {
            if (n % 2 == 0) {
                n /= 2;
                printf("2*%d,", n);
            } else {
                break;
            }
		}
        while (n > 0) {
            if (n % 3 == 0) {
                n /= 3;
                printf("3*%d,", n);
            } else {
                break;
            }
		}
        while (n > 0) {
            if (n % 5 == 0) {
                n /= 5;
                printf("5*%d,", n);
            } else {
                break;
            }
		}

        if (n == 1) {
            ugly = true;
        } else {
            ugly = false;
        }
        printf("*%d--->%d\n", n, ugly);
        return ugly;
    }
};

int main() {
    Solution sln;
    int N = 99999;
    for (int i=1; i<N; ++i) {
        sln.isUgly(i);
    }
    return 0;
}
