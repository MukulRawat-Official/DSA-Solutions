class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        
        map<int,int>mp;
        int curr = arr[0];
        for(int i = 1;i<n;i++){
            if(curr < arr[i]) curr = arr[i];
            if(++mp[curr] == k) return curr;
        }
        
        
        return curr;
        
    }
};