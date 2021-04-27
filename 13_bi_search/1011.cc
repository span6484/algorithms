class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 0, r = 1;
        for(int i = 0; i < weights.size(); i++) {
            l = max(l, weights[i]);
            r += weights[i];
        }
        // cout << l << " " << r << endl;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(helper(mid, weights, D)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
private:
    bool helper(int cap, vector<int>&weights, int D) {
        int days = 1;
        int weight = 0;
        for(int i = 0; i < weights.size(); i++) {
            weight += weights[i];
            if(weight > cap) {
                days++;
                weight = weights[i];
            }
        }
        if(days > D) {
            return false;
        }
        return true;
    }
};