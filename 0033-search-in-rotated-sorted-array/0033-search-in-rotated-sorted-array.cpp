class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n =  arr.size();
        int l = -1 , h = n;
        
        while(h - l > 1){
            int mid = (h + l) >> 1;
            if(arr[mid] >= arr[0]){
                if(arr[0] > target || arr[mid] <= target) l = mid;
                else  h = mid;
            }
            else {
                if(arr[0] <= target || arr[mid] > target) h = mid;
                else l = mid;
            }
        }
        
        
        return (l != -1  && arr[l] == target ? l  : -1);
    }
};