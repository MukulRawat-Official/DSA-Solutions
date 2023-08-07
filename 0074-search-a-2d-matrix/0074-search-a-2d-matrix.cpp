class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n = arr.size();
        int m = arr[0].size();
        int l = 0 , h = m * n;
        
        while(h - l > 1){
            int mid = (h + l) >> 1;
            int r = mid / m , c = mid % m;
            if(arr[r][c] <= target) l = mid;
            else h = mid;
        }
        
        return arr[l/m][l % m] == target;
    }
};