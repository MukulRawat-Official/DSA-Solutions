class Solution {
public:
    int diagonalSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int i = 0 , j;
        
        int sum = 0;
        if(n & 1) sum -= arr[n/2][n/2];
        
        while(i<n) sum += arr[i++][j++];
        i = 0; j = n-1;
        while(i<n) sum += arr[i++][j--];
        
        return sum;
    }
};