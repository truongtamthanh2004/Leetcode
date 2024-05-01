class Solution {
public:
    double average(vector<int>& arr, int start, int end) {
        return accumulate(arr.begin() + start, arr.begin() + end + 1, 0) / (double)(end - start + 1);
    }

    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int start = 0;
        int end = k - 1;

        int count = 0;
        while (end < arr.size()) {
            if (average(arr, start, end) >= (double)threshold) count++;

            start++;
            end++;
        }

        return count;
    }
};