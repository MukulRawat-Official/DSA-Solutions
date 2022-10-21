class Solution
{
    public:
        bool containsNearbyDuplicate(vector<int> &nums, int k)
        {
            set<int> s;
            k++;
            int n = nums.size();
            for (int i = 0; i < min(n, k); i++)
                s.insert(nums[i]);
            if(s.size() != min(n,k)) return 1; 

            for (int i = k; i < n; i++)
            {
                s.erase(nums[i-k]);
                s.insert(nums[i]);
                if(s.size() != k) return 1; 
            }
            
            return 0;
        }
};