/**
 * https://leetcode.com/problems/count-and-say/
 */

#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string digitString("1");
        for (int i=1; i<n; ++i) {
            digitString = getNextDigitString(digitString);
            printf("%d: %s\n", i+1, digitString.c_str());
        }
       
        printf("-->%d: %s\n", n, digitString.c_str());
        
        return digitString;
    }

private:
    string getNextDigitString(string digitString) {
        string nextDigitString;
        int previousDigit = myatoi(digitString[0]);
        int count = 0;
        for (int i=0; i<digitString.length(); ++i) {
            int digit = myatoi(digitString[i]);
            if (digit == previousDigit) {
                count++;
            } else {
                nextDigitString += getDigitString(count, previousDigit);
                previousDigit = digit;
                count = 1;
            }
            
            if (i+1 >= digitString.length()) {
                nextDigitString += getDigitString(count, previousDigit);
            }
        }
        
        return nextDigitString;
    }
    
    string getDigitString(int count, int digit) {
        char countChar = myitoa(count);
        char digitChar = myitoa(digit);
        
        string digitString;
        digitString.push_back(countChar);
        digitString.push_back(digitChar);
        
        return digitString;
    }
    
    int myatoi(char a) {
        return (int)(a - '0');
    }
    
    char myitoa(int i) {
        return (char)(i+'0');
    }
    
};


int main(int argc, char** argv) {

    Solution s;
    s.countAndSay(atoi(argv[1]));

}
