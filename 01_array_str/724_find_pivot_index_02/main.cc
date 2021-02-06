class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(sum * 2 + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};