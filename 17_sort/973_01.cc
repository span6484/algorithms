class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int> > res;
        if(!points.size()) return res; 
        srand((unsigned)time(NULL));
        qsortHelper(points, 0, points.size()-1);
        for(int i = 0; i < k; i++) {
            res.push_back(points[i]);
        }
        return res;
    }

    void qsortHelper(vector<vector<int>>& points, int left, int right) {
        if(left >= right) return;
        int mid = random_partition(points, left, right);
        qsortHelper(points, left, mid-1);
        qsortHelper(points, mid+1, right);
    }
    int random_partition(vector<vector<int>>& points, int left, int right) {
        int random = rand() % (right - left + 1) + left;
        swap(points[random], points[right]);
        return partiotion(points, left, right);
    }
    int partiotion(vector<vector<int>>& points, int left, int right) {
        int midVal = squareSum(points[right]);
        for(int i = left; i < right; i++) {
            if(squareSum(points[i]) < midVal) {
                swap(points[left++], points[i]);
            }
        }
        swap(points[left], points[right]);
        return left;
    }
    int squareSum(const vector<int>& nums) {
        return nums[0] * nums[0] + nums[1] * nums[1];
    }
};