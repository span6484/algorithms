class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> factors{2, 3, 5};
        priority_queue<long, vector<long>, greater<long> > heap;
        unordered_set<long> memo;
        heap.push(1);
        int ugly = 0;
        for(int i = 0; i < n; i++) {
            long cur = heap.top(); heap.pop();
            ugly = (int)cur;
            for(auto& factor : factors) {
                long num = factor * cur;
                if(!memo.count(num)) {
                    memo.insert(num);
                    heap.push(num);
                }
            }
        }
        return ugly;
    }
};