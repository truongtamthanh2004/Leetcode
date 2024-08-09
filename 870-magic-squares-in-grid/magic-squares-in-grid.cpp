// class Solution {
// public:
//     int calcSumRow(vector<vector<int>>& grid, int r, int c) {
        
//         int sumEqual = 0;
//         for (int i = r; i <= r + 2; i++) {
//             int sum = 0;
//             for (int j = c; j <= c + 2; j++) {
//                 sum += grid[i][j];
//             }
//             if (i == r) {
//                 sumEqual = sum;
//             }
//             else {
//                 if (sumEqual != sum) return 0;
//             }
//         }
//         return sumEqual;
//     }
//     int calcSumCol(vector<vector<int>>& grid, int r, int c) {
        
//         int sumEqual = 0;
//         for (int i = c; i <= c + 2; i++) {
//             int sum = 0;
//             for (int j = r; j <= r + 2; j++) {
//                 sum += grid[i][j];
//             }
//             if (i == c) {
//                 sumEqual = sum;
//             }
//             else {
//                 if (sumEqual != sum) return 0;
//             }
//         }
//         return sumEqual;
//     }
//     int calcSumDiaMain(vector<vector<int>>& grid, int r, int c) {
//         int sum = 0;
//         int i = r, j = c;
//         while (i <= r + 2) {
//             sum += grid[i][j];
//             i++;
//             j++;
//         }
//         return sum;
//     }

//     int calcSumDiaRemain(const vector<vector<int>>& grid, int r, int c) {
//         int sum = 0;
//         for (int i = 0; i < 3; ++i) {
//             sum += grid[r + 2 - i][c + i];
//         }
//         return sum;
//     }

//     bool isDistinct(vector<vector<int>>& grid, int r, int c) {
//         unordered_map<int, int> mp;
//         for (int i = r; i <= r + 2; i++) {
//             for (int j = c; j <= c + 2; j++) {
//                 mp[grid[i][j]]++;
//                 if (mp[grid[i][j]] > 1) return false; 
//             }
//         }

//         return true;
//     }
//     int numMagicSquaresInside(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         int cnt = 0;
//         for (int i = 0; i < m - 2; i++) {
//             for (int j = 0; j < n - 2; j++) {
//                 if (isDistinct(grid, i, j) && calcSumRow(grid, i, j) > 0 
//                     && calcSumRow(grid, i, j) == calcSumCol(grid, i, j) && calcSumDiaMain(grid, i, j) == calcSumDiaRemain(grid, i, j)) cnt++;
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    // Function to calculate the sum of rows in the 3x3 grid
    int calcSumRow(const vector<vector<int>>& grid, int r, int c) {
        int sumEqual = 0;
        for (int i = r; i < r + 3; ++i) {
            int sum = 0;
            for (int j = c; j < c + 3; ++j) {
                sum += grid[i][j];
            }
            if (i == r) {
                sumEqual = sum;
            } else if (sumEqual != sum) {
                return 0;
            }
        }
        return sumEqual;
    }

    // Function to calculate the sum of columns in the 3x3 grid
    int calcSumCol(const vector<vector<int>>& grid, int r, int c) {
        int sumEqual = 0;
        for (int j = c; j < c + 3; ++j) {
            int sum = 0;
            for (int i = r; i < r + 3; ++i) {
                sum += grid[i][j];
            }
            if (j == c) {
                sumEqual = sum;
            } else if (sumEqual != sum) {
                return 0;
            }
        }
        return sumEqual;
    }

    // Function to calculate the sum of the main diagonal
    int calcSumDiaMain(const vector<vector<int>>& grid, int r, int c) {
        int sum = 0;
        for (int i = 0; i < 3; ++i) {
            sum += grid[r + i][c + i];
        }
        return sum;
    }

    // Function to calculate the sum of the secondary diagonal
    int calcSumDiaRemain(const vector<vector<int>>& grid, int r, int c) {
        int sum = 0;
        for (int i = 0; i < 3; ++i) {
            sum += grid[r + 2 - i][c + i];
        }
        return sum;
    }

    // Function to check if all numbers in the 3x3 grid are distinct and in the range 1-9
    bool isDistinct(const vector<vector<int>>& grid, int r, int c) {
        unordered_map<int, int> mp;
        for (int i = r; i < r + 3; ++i) {
            for (int j = c; j < c + 3; ++j) {
                if (grid[i][j] < 1 || grid[i][j] > 9 || ++mp[grid[i][j]] > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    // Function to count the number of magic squares in the grid
    int numMagicSquaresInside(const vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i <= m - 3; ++i) {
            for (int j = 0; j <= n - 3; ++j) {
                if (isDistinct(grid, i, j)) {
                    int rowSum = calcSumRow(grid, i, j);
                    int colSum = calcSumCol(grid, i, j);
                    int diaMain = calcSumDiaMain(grid, i, j);
                    int diaRemain = calcSumDiaRemain(grid, i, j);
                    
                    // Check if all sums are equal to the magic sum (15)
                    if (rowSum == 15 && colSum == 15 && diaMain == 15 && diaRemain == 15) {
                        ++count;
                    }
                }
            }
        }
        
        return count;
    }
};

