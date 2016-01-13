/**
 * leetcode: integer to roman
 * medium 
 */

#include <cmath>
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

    string intToRoman(int num) {
        return method1(num);    
    }
private:
    string method1(int num) {
       int n = num;
       int digits[4] = {0,0,0,0};
       
       for (int i=0; i<4 && n>0; ++i) {
           digits[i] = (n % 10); 
           printf("%d:%d,", i, digits[i]); 
           n /= 10;
       } 
       printf("\n");
      
       string str;
       for (int i=3; i>=0; --i) {
           int coef = pow(10, i);
           printf("%d: coef=%d, digit=%d\n", i, coef, digits[i]);
           if (digits[i]<=3) {
               for (int j=1; j<=digits[i]; ++j) {
                   str += rlut[1*coef];
               }    
           } else if (digits[i] <=4) {
               str += rlut[1*coef];
               str += rlut[5*coef];
           } else if (digits[i] == 5) {
               str += rlut[5*coef];
           } else if (digits[i] <= 8) {
               str += rlut[5*coef];
               for (int j=1; j<=digits[i]-5; ++j) {
                   str += rlut[1*coef];
               }   
           } else if (digits[i] <= 9) {
               str += rlut[1*coef];
               str += rlut[10*coef];
           } else {
           }
           printf("%d --> %s\n", digits[i], str.c_str());
       }
       printf("%d --> %s\n", num, str.c_str());

       return str;
    }

    void init() {
        memset(rlut, 0, sizeof(char)*RLUT_SIZE);
        rlut[1] = 'I';
        rlut[5] = 'V';
        rlut[10] = 'X';
        rlut[50] = 'L';
        rlut[100] = 'C';
        rlut[500] = 'D';
        rlut[1000] = 'M';
    }

    static const int RLUT_SIZE = 1001;
    int rlut[RLUT_SIZE];
};

int main() {
    Solution sln;

    for (int i=1; i<3999; ++i) {
        sln.intToRoman(i);
    }

    return 0;
}
