class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int sum = 0;
        int cnt = 0;
        for(const int num : nums) {
            sum += num;
            cnt += map[sum - k];
            map[sum]++;
        }
        return cnt;
    }
};