class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int a) {
        int n = arr.size();
        
        for(int i = 0;i<n && a;i++){
            if(arr[i]) continue;
            if(i && arr[i-1]) continue;
            if(i<n-1 && arr[i+1]) continue;
            arr[i] = 1;
            a--;
            
        }
        
        return !a;
    }
};