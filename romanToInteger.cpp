/**
 * leetcode: roman to integer
 * easy
 */

#include <cstdio>
#include <string>

using namespace std;

/**
 * roman digit: I V  X  L   C   D    M
 * digit      : 1 5 10 50 100 500 1000
 * 计数规则： 
 * 相同的数字连写，所表示的数等于这些数字相加得到的数，例如：III = 3
 * 小的数字在大的数字右边，所表示的数等于这些数字相加得到的数，例如：VIII = 8
 * 小的数字，限于（I、X和C）在大的数字左边，所表示的数等于大数减去小数所得的数，例如：IV = 4
 * 正常使用时，连续的数字重复不得超过三次
 * 在一个数的上面画横线，表示这个数扩大1000倍
 *（本题只考虑3999以内的数，所以用不到这条规则） 
 * 重复数次：一个罗马数字重复几次，就表示这个数的几倍
 *
 *
 * 右加左减： 在较大的罗马数字的右边记上较小的罗马数字，表示大数字加小数字。 
 * 在较大的罗马数字的左边记上较小的罗马数字，表示大数字减小数字。
 * 左减的数字有限制，仅限于I、X、C。比如45不可以写成VL，只能是XLV.
 * 但是，左减时不可跨越一个位数。比如，99不可以用IC（100 - 1）表示，而是用XCIX（[100 - 10] + [10 - 1]）表示。
 * （等同于阿拉伯数字每位数字分别表示。） 
 * 左减数字必须为一位，比如8写成VIII，而非IIX。 
 * 右加数字不可连续超过三位，比如14写成XIV，而非XIIII。（见下方“数码限制”一项。）
 * 数码限制： 同一数码最多只能出现三次，如40不可表示为XXXX，而要表示为XL。
 * 例外：由于IV是古罗马神话主神朱庇特（即IVPITER，古罗马字母里没有J和U）的首字，因此有时用IIII代替IV。
 */
class Solution {
public:
    Solution() {
        init();
    }

    int romanToInt(string s) {
        return method1(s);    
    }
private:
    int method2(string s) {
        int n = s.length();

        for (int i=0; i<n; ++i) {
            if (lut[s[i]] % 1000 == 0) {
            }
        }

    }

    int method1(string s) {
        int n = s.length();
        int sum = lut[s[0]];
        printf("%c=%d\n", s[0], sum);

        int i = 0;
        int j = 1;
        bool isAdd = false;
        int count = 0;
        while (i<n && j<n) {
            if (lut[s[j]] <= lut[s[i]]) {
               if ( (j+1) < n && lut[s[j+1]] > lut[s[j]]) {
                   digit = lut[s[i]];
                   i++;
                   j = i+1;
               } else {
                  digit = lut[s[i]] + lut[s[j]]
                  while (i)
               }
               if (count <=0) {
                   isAdd = true;
               }
               digit += lut[s[j]] + lut[s[i]];
            }
            
            if (lut[s[j]] > lut[s[i]]) {
                digit = lut[s[j]] - lut[s[i]];
                i += 2;
                j = i+1;
            }
        }



        for (int i=1; i<n; ++i) {
            if (lut[s[i]] <= lut[s[i-1]]) {
                sum += lut[s[i]];
            } else {
                digit = lut[s[i]] - lut[s[i-1]];
                sum += digit;
                ++i;
            }
            printf("%c=%d\n", s[i], sum);
        }   
        return sum;
    }

    string intToRoman(int number) {
        
    }

    void init() {
        memset(lut, 0, sizeof(int)*SIZE);
        lut['I'] = 1;
        lut['V'] = 5;
        lut['X'] = 10;
        lut['L'] = 50;
        lut['C'] = 100;
        lut['D'] = 500;
        lut['M'] = 1000;
        lut['i'] = 1;
        lut['v'] = 5;
        lut['x'] = 10;
        lut['l'] = 50;
        lut['c'] = 100;
        lut['d'] = 500;
        lut['m'] = 1000;

        memset(rlut, 0, sizeof(char)*RLUT_SIZE);
        rlut[1] = 'I';
        rlut[5] = 'V';
        rlut[10] = 'X';
        rlut[50] = 'L';
        rlut[100] = 'C';
        rlut[500] = 'D';
        rlut[1000] = 'M';
    }
    static const int SIZE = 128;
    int lut[SIZE];
    static const int RLUT_SIZE = 1001;
    int rlut[RLUT_SIZE];
};

int main() {
    Solution sln;
    sln.romanToInt("DCXXI");
    return 0;
}
