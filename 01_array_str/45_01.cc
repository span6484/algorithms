class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0;
        int end = 0;
        int step = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            maxPos = max(maxPos, i + nums[i]);
            if(i == end) {
                end = maxPos;
                step++;
            }
        }
        return step;
    }
};