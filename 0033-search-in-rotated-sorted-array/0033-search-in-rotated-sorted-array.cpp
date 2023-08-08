#define nums arr
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 , high  = nums.size()-1;
        
        while(low<=high)
        {
           int mid = low + (high - low) / 2;
           
            
            if(arr[mid] == target)
                return mid;
            
             else  if(arr[mid] >= arr[low])
            {
                if(arr[low] <= target && arr[mid] > target)
                    high = mid-1;
                 
                 else
                     low = mid+1;
            }
            
            else
            {
                  if(arr[mid] <  target && arr[high] >= target)
                      low = mid+1;
                
                  else
                      high = mid-1;
                      
            }
        }
        
        return -1;
    }
};