class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int res = 0;
        for(int i = 1; i <= citations.size(); i++) {
            res = max(res, min(i, citations[i-1]));
        }
        return res;
    }
};