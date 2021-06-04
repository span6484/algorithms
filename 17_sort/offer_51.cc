class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.empty()) return 0;
        mergeHelper(nums, 0, nums.size() - 1);
        return cnt_;
    }
private:
    void mergeHelper(vector<int>& nums, int left, int right) {
        if(left >= right) return;
        int mid = left + (right - left) / 2;
        mergeHelper(nums, left, mid);
        mergeHelper(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
    void merge(vector<int>& nums, int left, int mid , int right) {
        vector<int> tmp(right - left + 1);
        int l = left, r = mid + 1, k = 0;
        while(l <= mid && r <= right) {
            if(nums[l] <= nums[r]) {
                tmp[k++] = nums[r++];
            } else {
                tmp[k++] = nums[l++];
                cnt_ += (right - r + 1);
            }
        }
        int start = l, end = mid;
        // 判断剩余
        if(r <= right) {
            start = r;
            end = right;
        } 
        while(start <= end) {
            tmp[k++] = nums[start++];
        }
        // 写回 nums
        for(int i = left; i <= right; i++) {
            nums[i] = tmp[i-left]; 
        }
    }
private:
    int cnt_;
};