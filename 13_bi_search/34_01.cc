class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findFirst(nums, target);
        int end = findEnd(nums, target);
        return {start, end};
    }
private:
    int findFirst(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        int start = -1;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(target == nums[mid]) {
                start = mid;
                r = mid;
            } else if(target < nums[mid]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return start;
    }
    int findEnd(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        int end = -1;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(target == nums[mid]) {
                end = mid;
                l = mid+1;
            } else if(target < nums[mid]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return end;
    }
};