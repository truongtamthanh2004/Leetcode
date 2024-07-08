class Solution {
public:
    int findTheWinner(int n, int k) {
        // int count = 0;
        // vector<bool> erased(n + 1, false);
        // int start = 1;
        // while (count < n - 1)
        // {
        //     int tmp = 0;
        //     while (tmp < k)
        //     {
        //         tmp++;
                
        //         start++;
        //         if (start > n) start = 1;
        //         while (erased[start]) {
        //             start++;
        //             if (start > n) start = 1;
        //         }
                    
        //     }

        //     erased[start] = true;
        //     start++;
        //     if (start > n) start = 1;
        //     while (erased[start]) {
        //         start++;
        //         if (start > n) start = 1;
        //     }
        //     count++;
        // }
        // for (int i = 1; i <= n; i++)
        // {
        //     if (erased[i] == false) return i;
        // }
        // return count;

        vector<bool> erased(n + 1, false);
        int start = 1;

        for (int count = 0; count < n - 1; ++count) {
            int steps = 0;
            while (steps < k) {
                if (!erased[start]) {
                    ++steps;
                }
                if (steps < k) {
                    ++start;
                    if (start > n) {
                        start = 1;
                    }
                }
            }
            erased[start] = true;

            // Move to the next non-erased element
            do {
                ++start;
                if (start > n) {
                    start = 1;
                }
            } while (erased[start]);
        }

        // Find the last remaining element
        for (int i = 1; i <= n; ++i) {
            if (!erased[i]) {
                return i;
            }
        }

        return -1;
    }
};