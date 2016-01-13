/**
 * https://leetcode.com/problems/word-ladder-ii/
 * Level: Hard
 */

#include <cstdio>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string> > ladders; 
        vector<string> ladder;
        ladder.push_back(beginWord);
        unordered_set<string> pool(wordList);
        pool.insert(endWord);
        recursiveFindLadder(ladder, pool);
        ladders.push_back(ladder);
    }
    
private:
    void recursiveFindLadder(vector<string>& ladder, unordered_set<string>& pool) {
        if (pool.empty()) {
            return;
        }
        
        printLadder(ladder);
        printPool(pool);
        printf("\n");

        string beginWord = ladder[ladder.size()-1];

        vector<string> candidates;
        for (unordered_set<string>::iterator it = pool.begin(); it != pool.end(); ++it) {
            int diffCount = diffWord(beginWord, *it, NULL);
            if (diffCount == 1) {
                candidates.push_back(*it);
            }
        }
        
        for (int i=0; i< candidates.size(); ++i) {
            ladder.push_back(candidates[i]);
            pool.erase(candidates[i]);
            recursiveFindLadder(ladder, pool);
        }
    }

    /**
     * returns number of diffences between words, and the positions of differences.
     */ 
    int diffWord(string word1, string word2, vector<int>* position) {
        if (word1.size() != word2.size()) {
            return -1;
        }
        int diffCount = 0;
        for (int i=0; i<word1.size(); ++i) {
            if (word1[i] != word2[i]) {
                diffCount++;
                if (position != NULL) {
                    position->push_back(i);
                }
            }
        }
        return diffCount;
    }

    void printLadder(vector<string>& ladder) {
        auto i = ladder.begin();
        printf("%s", i->c_str());
        for (++i; i!=ladder.end(); ++i) {
            printf("-->%s", i->c_str());
        }
        printf("\n");
    }
    void printPool(unordered_set<string>& ladder) {
        auto i = ladder.begin();
        printf("%s", i->c_str());
        for (++i; i!=ladder.end(); ++i) {
            printf("-->%s", i->c_str());
        }
        printf("\n");
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    vector<string> bw; 
    bw.push_back("hit"); 
    vector<string> ew; ew.push_back("cog");
    unordered_set<string> wordList;
    wordList.insert("hot");
    wordList.insert("dot");
    wordList.insert("dog");
    wordList.insert("lot");
    wordList.insert("log");
    
    for (int i=0; i<bw.size(); ++i) {
        s.findLadders(bw[i], ew[i], wordList);
    }
    return 0;
}
