class Solution {
public:
    int jump(vector<int>& nums) {
        int currentPos = 0;
        int count = 0;

        while (currentPos < nums.size() - 1)
        {
            int nextPos = currentPos + 1;
            for (int i = currentPos + 1; i <= currentPos + nums[currentPos] && i < nums.size(); i++)
            {
                if (nextPos + nums[nextPos] <= i + nums[i])
                {
                    nextPos = i;
                }
            }

            if (currentPos + nums[currentPos] >= nums.size() - 1) currentPos = nums.size() - 1;
            else currentPos = nextPos;
            count++;
        }
        return count;
    }
};