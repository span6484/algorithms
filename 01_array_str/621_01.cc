class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> memo(26, 0);
        int maxCount = 0;
        for(auto task : tasks) {
            maxCount = max(maxCount, ++memo[task - 'A']);
        }
        int res = (maxCount - 1) * (n+1);
        for(auto m : memo) {
            if(m == maxCount) res++;
        }
        return max(res, (int)tasks.size());

    }
};