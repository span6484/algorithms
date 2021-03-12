class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long sum = 0;
        for(auto pile : piles) {
            sum += pile;
        }
        long l = 1, r = sum+1;
        while(l < r) {
            int hour = 0;
            long m = l + (r-l)/2;
            for(auto pile: piles) {
                hour += (pile-1)/m + 1;
            }
            if(hour <= h) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;

    }
};