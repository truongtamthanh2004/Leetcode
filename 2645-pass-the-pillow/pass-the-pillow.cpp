class Solution {
public:
    int passThePillow(int n, int time) {
        bool reverse = 0;
        int start = 1;
        
        while (time-- > 0) {
            if (!reverse) {
                start += 1;
            }
            else {
                start -= 1;
            }
            
            if (start == n || start == 1) {
                reverse = !reverse;
            }
        }
        return start;
    }
};