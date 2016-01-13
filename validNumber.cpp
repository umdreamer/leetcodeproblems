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
        string sub(s);
        string::size_type pos1 = s.find_first_not_of(' ');
        if (pos1 != string::npos) {
            string::size_type pos2 = s.find_last_not_of(' ');
            sub = sub.substr(pos1, pos2-pos1+1);
        }
        printf("before:%s ==> after:%s\n", s.c_str(), sub.c_str());
        
        bool hasSign = false;  // "+-"
        bool hasPoint = false; // "."
        bool hasDigit = false;
        bool hasE = false; // "e"
        for (int i=0; i<sub.length(); ++i) {
            if (isDigit(sub[i])) {
                if (!hasDigit) {
                    hasDigit = true;
                }
            } else if (isE(sub[i])) {
                if (i == 0) {
                    return false;
                }
                
                if (!hasDigit) {  // before e, "1.e"==>true, ".e"==>false
                    return false;
                }
                
                if ( (!isPoint(sub[i-1])) && (!isDigit(sub[i-1])) ) { // before e: .1e==>true
                    return false;
                }
                
                if ( (!isSign(sub[i+1])) && (!isDigit(sub[i+1])) ) { // after e: 1e+1==>true, 1e-1==>true. 1e-.5==>false
                    return false;
                }
                
                if (!hasE) { // only one "e".
                    hasE = true;
                } else { 
                    return false;
                }
            } else if (isPoint(sub[i])) {
                if (hasE) {   // 1e.5==>false, 1e5.==>false
                    return false;
                }
                
                if (!hasPoint) { // only once
                    hasPoint = true;
                } else {
                    return false;
                }
            } else if (isSign(sub[i])) {
                if (!hasE) { // before e
                    if (hasPoint || hasDigit) {
                        return false;
                    }
                } else { // after e
                    if ( (!isE(sub[i-1])) ) {// e+
                        return false;
                    }
                    if (!isDigit(sub[i+1]) ) { //e+1, e+.1
                        return false;
                    }
                }

            } else if (sub[i] == ' ') {
                return false;
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
    testCase.push_back("1 1");
    testCase.push_back("2e10");
    testCase.push_back("1e+5");
    testCase.push_back("1e-5");
    testCase.push_back("  1e-0   ");
    testCase.push_back("    ");
    testCase.push_back("4e+");
    testCase.push_back("4+e");
    testCase.push_back("4e+.2");

    for (int i=0; i<testCase.size(); ++i) {
        printf("%s ==> %d\n", testCase[i].c_str(), s.isNumber(testCase[i]));
    } 

    return 0;
}
