/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int get_index(MountainArray &mr){
        int l = 0, h = mr.length() - 1;
        
        while(h - l > 1){
            int mid = (h + l) >> 1;
            
            if(mr.get(mid) > mr.get(mid-1)) l = mid;
            else h = mid;
        }
        
        return l;
    }
    int findInMountainArray(int target, MountainArray &mr) {
        int mid = get_index(mr);
        int l = 0 , h = mid + 1;
        
        while(h - l > 1){
            int mid = (h + l) >> 1;
            
            if(mr.get(mid) <= target) l = mid;
            else h = mid;
        }
        
        if(mr.get(l) == target) return l;
        l = mid; h = mr.length() - 1;
        
        while(h - l > 1){
            int mid = (h + l) >> 1;
            
            if(mr.get(mid) > target) l = mid;
            else h = mid;
        }
        
        
        if(mr.get(h) == target) return h;
        
        return -1;
        
    }
};