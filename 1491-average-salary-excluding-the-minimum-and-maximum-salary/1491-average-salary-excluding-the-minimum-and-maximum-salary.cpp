class Solution {
public:
    double average(vector<int>& salary) {
        double sum  = 0;
        int n = salary.size();
        for(auto& x : salary){
            sum += x;
        }
        
        sort(salary.begin(),salary.end());
        sum -= (salary.back() + salary[0]);
        
        return sum / (n-2);
    }
};