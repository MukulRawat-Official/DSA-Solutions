class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
        arr.push_back(newInterval);
        sort(arr.begin(),arr.end());
        
        vector<vector<int>>ans;
        ans.push_back(arr[0]);
        
        for(int i = 1;i<arr.size();i++){
            vector<int>&tmp = ans.back();
            
            if(arr[i][0] <= tmp[1]) tmp[1] = max(arr[i][1],tmp[1]);
            else ans.push_back(arr[i]);
        }
        
        return ans;
    }
};