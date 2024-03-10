class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        int i = nums1.size() - 1;

        while (i >= 0)
        {
            if (count(res.begin(), res.end(), nums1[i]) == 0)
            {
                if (count(nums2.begin(), nums2.end(), nums1[i]) > 0) res.push_back(nums1[i]);
            }
            i--;
        }
        return res;
    }
};