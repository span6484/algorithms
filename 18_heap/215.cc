class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        auto comp = [](int a, int b) { return a > b; };
        priority_queue<int, vector<int>, decltype(comp)> q(comp);
        for(int i = 0; i < k; i++) {
            q.push(nums[i]);
        }
        for(int i = k; i < nums.size(); i++) {
            if(nums[i] > q.top()) {
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};