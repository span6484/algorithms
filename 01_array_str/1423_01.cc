class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sz = cardPoints.size();
        int windowSz = sz - k;
        int all = 0;
        int sum = 0;
        for(int i = 0; i < sz; i++) {
            if(i < windowSz) {
                sum += cardPoints[i];
            }
            all += cardPoints[i];
        }
        int minSum = sum;   
        for(int i = windowSz; i < sz; i++) {
            sum = sum + cardPoints[i] - cardPoints[i - windowSz];
            minSum = min(minSum, sum);
        }
        return all - minSum;
    }
};