/**
 * leetcode: range Sum Query 2D - Immutable
 * difficulty: medium
 * tags: dynamic programming
 * Integral Image
 */
#include <cstdio>
#include <vector>

using namespace std;
class NumMatrix {
public:
    NumMatrix(vector<vector<int> > &matrix) {
        if (matrix.empty()) return;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i=0; i<rows; ++i) {
            vector<int> rowVector(cols, 0);
            sumMatrix_.push_back(rowVector);
        }
        computeSumMatrix(matrix);
    }
    
    void computeSumMatrix(vector<vector<int> >& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        sumMatrix_[0][0] = matrix[0][0];
        for (int j=1; j<cols; ++j) {
            sumMatrix_[0][j] = sumMatrix_[0][j-1] + matrix[0][j];
        }
        for (int i=1; i<rows; ++i) {
            sumMatrix_[i][0] = sumMatrix_[i-1][0] + matrix[i][0];
        }
        for (int i=1; i<rows; ++i) {
            for (int j=1; j<cols; ++j) {
                sumMatrix_[i][j] = sumMatrix_[i-1][j] + sumMatrix_[i][j-1] - sumMatrix_[i-1][j-1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int s1 = 0;
        int s2 = 0;
        int s3 = 0;
        int s4 = 0;
        
        if (sumMatrix_.empty()) return 0;
        
        s1 = sumMatrix_[row2][col2];
        if (row1-1 >=0) {
            s2 = sumMatrix_[row1-1][col2];
            if (col1-1 >=0) {
                s4 = sumMatrix_[row1-1][col1-1];
            }
        }
        if (col1-1 >= 0) {
            s3 = sumMatrix_[row2][col1-1];
            if (row1-1 >=0) {
                s4 = sumMatrix_[row1-1][col1-1];
            }
        }
        int s = s1 - s2 - s3 + s4;
        printf("sumRange(%d,%d,%d,%d) --> %d\n", row1, col1, row2, col2, s);
        return s;
    }
private: 
    vector<vector<int> > sumMatrix_;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int main(int argc, char** argv) {
    vector<vector<int> > matrix;
    for (int i=0; i<5; ++i) {
        vector<int> v;
        for (int j=0; j<5; ++j) {
            v.push_back(j);
        }
        matrix.push_back(v);
    }

    NumMatrix numMatrix(matrix);
    numMatrix.sumRegion(0, 1, 2, 3);
    numMatrix.sumRegion(1, 2, 3, 4);
    
}
