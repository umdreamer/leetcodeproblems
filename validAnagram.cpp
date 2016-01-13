/**
 * leetcode: valid anagram
 * easy
 */

#include <cstdio>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        return diff(s, t);
    }
private:
    bool diff(string s, string t) {
        const int NUM = 26;
        int histogramS[NUM];
        int histogramT[NUM];
        
        computeHistogram(s, histogramS, NUM);
        computeHistogram(t, histogramT, NUM);
        
        printHistogram(histogramS, NUM);
        printHistogram(histogramT, NUM);

        for (int i=0; i<NUM; ++i) {
            if (histogramS[i] - histogramT[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
    void computeHistogram(string s, int* histogram, int size) {
        memset(histogram, 0, sizeof(int)*size);
        for (int i=0; i<s.length(); ++i) {
            histogram[s[i]-'a']++;
        }
    }
    void printHistogram(int* hist, int size) {
        printf("%d", hist[0]);
        for (int i=0; i<size; ++i) {
            printf(",%d", hist[i]);
        }
        printf("\n");
    }
};

int main() {
    Solution sln;
    string s = "a";
    string t = "b";
    printf("%s,%s -> %d\n", s.c_str(), t.c_str(), sln.isAnagram(s,t));
}

