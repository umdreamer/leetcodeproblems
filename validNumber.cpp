/**
 * https://leetcode.com/problems/valid-number/
 * Level: Hard
 */ 

#include <cstdio>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        bool hasSign = false;  // "+-"
        bool hasPoint = false; // "."
        bool hasDigit = false;
        bool hasE = false; // "e"
        for (int i=0; i<s.length(); ++i) {
            if (isDigit(s[i])) {
                if (!hasDigit) {
                    hasDigit = true;
                }
            } else if (isE(s[i])) {
                if (i == 0) {
                    return false;
                }
                
                if (!hasDigit) {  // before e, "1.e"==>true, ".e"==>false
                    return false;
                }
                
                if ( (!isPoint(s[i-1])) && (!isDigit(s[i-1])) ) { // before e: .1e==>true
                    return false;
                }
                
                if ( (!isSign(s[i+1])) && (!isDigit(s[i+1])) ) { // after e: 1e+1==>true, 1e-1==>true. 1e-.5==>false
                    return false;
                }
                
                if (!hasE) { // only one "e".
                    hasE = true;
                } else { 
                    return false;
                }
            } else if (isPoint(s[i])) {
                if (hasE) {   // 1e.5==>false, 1e5.==>false
                    return false;
                }
                
                if (!hasPoint) { // only once
                    hasPoint = true;
                } else {
                    return false;
                }
            } else if (isSign(s[i])) {
                if (!hasE) { // before e
                    if (hasPoint || hasDigit) {
                        return false;
                    }
                } else { // after e
                    if ( (!isE(s[i-1])) ) {// e+
                        return false;
                    }
                }

                //if (!hasSign) { 
                //    hasSign = true;
                //} else {
                    //return false;
                //}
            } else if (s[i] == ' ') {
                if (hasE || hasDigit || hasPoint) {
                    return false;
                }
                continue; // ignore whitespace
            } else {
                return false;
            }
        }
        
        if (!hasDigit) { // must have digit.
            return false;
        }
        return true;
    }
private:
    bool isDigit(char c) {
        if (c >= '0' && c <= '9') {
            return true;
        }
        return false;
    }
    bool isSign(char c) {
        if (c == '+' || c == '-') {
            return true;
        }
        return false;
    }
    bool isPoint(char c) {
        if (c == '.') {
            return true;
        }
        return false;
    }
    bool isE(char c) {
        if (c == 'e') {
            return true;
        }
        return false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<string> testCase;

    testCase.push_back("0");
    testCase.push_back("0.1");
    testCase.push_back("abc");
    testCase.push_back("1 a");
    testCase.push_back("2e10");
    testCase.push_back("1e+5");
    testCase.push_back("1e-5");

    for (int i=0; i<testCase.size(); ++i) {
        printf("%s ==> %d\n", testCase[i].c_str(), s.isNumber(testCase[i]));
    } 

    return 0;
}
