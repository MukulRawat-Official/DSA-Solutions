class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return {};
        vector<string>arr;
        int curr = nums[0];
        int n = nums.size();
        arr.push_back(to_string(nums[0]));
        for(int i = 1;i<nums.size();i++){
            int x = nums[i];
            if(x == curr + 1)  {
                curr++;
                if(i == n-1) arr.back()+= "->" + to_string(curr);     
            }
            else{ 
                if(to_string(curr) != arr.back())  arr.back() += "->" + to_string(curr);
                arr.push_back(to_string(x));
                curr = x;
            }
        }
        
        
        
        return arr;
    }
};