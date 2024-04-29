class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j = numbers.size() - 1;

        for (int i = 0; i < j; i++) {
            while (j >= 0 && numbers[i] + numbers[j] > target) 
                j--;

            if (numbers[i] + numbers[j] == target) 
                return {i + 1, j + 1};
        }
        
        return {-1, -1};
    }
};