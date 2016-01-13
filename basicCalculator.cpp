/**
 * 
 */
class Solution {
public:
    int calculate(string s) {
        while (true) {
            for (int i=0; i<s.length(); ++i) {
                if (s[i] == ' ') {
                    continue;
                } else if (s[i] >= '0' && s[i] <= '9') {
                    number.push_back(int(s[i]-'0'));
                } else if (s[i] == '+') {
                    left = getNumber(number);
                }
            }
        }
        
    }
private:
    int str2num(string s) {
        return atoi(s.c_str());
    }
    
    vector< vector<int> > numberList;
    
    
};
