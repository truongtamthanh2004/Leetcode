// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int n = nums.size();
//         int cnt = 0;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i; j < n; j++)
//             {   
//                 int subSum = 0;
//                 for (int k = i; k <= j; k++) subSum += nums[k];

//                 if (abs(subSum) % k == 0) cnt++;
//             }
//         }
        
//         return cnt;
//     }
// };

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_map = {{0, 1}};
        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;
            if(sum < 0) sum += k;
            if(prefix_map.find(sum) != prefix_map.end()) {
                ans += prefix_map[sum];
                prefix_map[sum]++;
            } else {
                prefix_map[sum] = 1;
            }
        }
        return ans;
    }
};