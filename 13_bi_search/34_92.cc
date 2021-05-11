class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findPos(nums, target, true);
        int end = findPos(nums, target, false);
        return {start, end};
    }
private:
    int findPos(vector<int>& nums, int target, bool left) {
        int l = 0, r = nums.size();
        int pos = -1;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(target == nums[mid]) {
                if(left) {
                    pos = mid;
                    r = mid;
                } else {
                    pos = mid;
                    l = mid+1;
                }
            } else if(target < nums[mid]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return pos;
    }
};