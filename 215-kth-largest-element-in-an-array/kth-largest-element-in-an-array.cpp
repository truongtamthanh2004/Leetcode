class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int pivot = nums[rand() % n];
        vector<int> left, right, mid;
        for (auto num : nums)
        {
            if (num > pivot) 
                right.push_back(num);
            else if (num < pivot)
                left.push_back(num);
            else
                mid.push_back(num);
        }
        if (k <= right.size())
            return findKthLargest(right, k);
        
        k -= right.size();

        if (k <= mid.size())
            return pivot;

        k -= mid.size();

        return findKthLargest(left, k);
    }
};