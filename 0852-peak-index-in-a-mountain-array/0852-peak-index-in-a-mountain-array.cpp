class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0 , h = n - 1;
        
        auto chk = [&](int m)->bool{
           return arr[m] > arr[m-1];
        };
        while(h - l > 1){
            int mid = (h + l) >> 1;
            if(chk(mid)) l = mid;
            else h = mid;
        }
        
        return l;
    }
};