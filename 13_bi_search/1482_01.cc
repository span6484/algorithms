class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k > bloomDay.size()) return -1;
        int l = *min_element(begin(bloomDay), end(bloomDay));
        int r = *max_element(begin(bloomDay), end(bloomDay)) + 1;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(canMake(mid, bloomDay, m, k)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }      
        return l;
    }
private:
    bool canMake(int mid, vector<int>& bloomDay, int m, int k) {
        int adj = 0;
        int bouque = 0;
        for(auto& day : bloomDay) {
            if(day <= mid) {
                adj += 1;
                if(adj == k) {
                    adj = 0;
                    bouque += 1;
                }
            } else {
                adj = 0;
            }
            if(bouque == m) break;
        }
        return bouque == m;
    }

};