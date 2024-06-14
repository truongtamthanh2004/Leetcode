// class Solution {
// public:
//     int maxAvailable(unordered_map<int, int>& mp, int start)
//     {
//         while(true)
//         {
//             if (mp[start] == 0) return start;
//             start++;
//         }
//         return start;
//     }
//     int minIncrementForUnique(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         for (auto i : nums)
//         {
//             mp[i]++;
//         }
//         sort(nums.begin(), nums.end());
        
//         int tmp = nums[0];
//         int increment = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int start = maxAvailable(mp, tmp);
//             tmp = start;
//             cout << start << " ";
//             if (mp[nums[i]] > 1)
//             {
//                 increment += (start - nums[i]);
//                 cout << increment << endl;
//                 mp[nums[i]]--;
//                 mp[start]++; 
//             }
//         }
//         return increment;
//     }
// };
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                int diff=1;
                count+=1;
                nums[i]=nums[i]+diff;
            }
            else if(nums[i]<nums[i-1]){
                int diff=abs(nums[i]-nums[i-1])+1;
                count+=diff;
                 nums[i]=nums[i]+diff;
            }
        }
        return count;
    }
};