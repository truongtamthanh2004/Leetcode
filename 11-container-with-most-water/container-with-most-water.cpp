class Solution {
public:
    int calcVolume(int height, int vertical) { return height * vertical; }
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        int maxVolume = 0;
        while (i < j) {
            int volume = min(height[i], height[j]) * (j - i);
            maxVolume = max(maxVolume, volume);

            if (height[i] > height[j])
                j--;
            else i++;
        }

        return maxVolume;
    }
};