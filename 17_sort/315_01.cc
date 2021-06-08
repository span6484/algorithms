class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int sz = nums.size();
        vector<pair<int, int> > numVec(sz);
        count_.resize(sz, 0);
        for(int i = 0; i < sz; i++) {
            numVec[i].first = nums[i];
            numVec[i].second = i;
        }
        mergeHelper(numVec, 0, sz-1);
        return count_;
    }
private:
    void mergeHelper(vector<pair<int, int> >& numVec, int left, int right) {
        if(left >= right) return;
        int mid = left + (right-left)/2;
        mergeHelper(numVec, left, mid);
        mergeHelper(numVec, mid+1, right);
        merge(numVec, left, mid, right);
    }
    void merge(vector<pair<int, int> >& numVec, int left, int mid, int right) {
        vector<pair<int, int> > tmp(right - left + 1);
        int l = left, r = mid + 1, k = 0;
        while(l <= mid && r <= right) {
            if(numVec[l].first <= numVec[r].first) {
                tmp[k++] = numVec[r++];
            } else {
                count_[numVec[l].second] += right - r + 1;
                tmp[k++] = numVec[l++];
            }
        }
        int start = l, end = mid;
        if(r <= right) {
            start = r;
            end = right;
        }
        while(start <= end) {
            tmp[k++] = numVec[start++];
        }
        // 写回numVec
        for(int i = left; i <= right; i++) {
            numVec[i] = tmp[i-left];
        }
    }
private:
    vector<int> count_;

};