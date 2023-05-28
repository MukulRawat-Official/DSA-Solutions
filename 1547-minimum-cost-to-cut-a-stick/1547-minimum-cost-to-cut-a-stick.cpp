class Solution {
public:
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int m=cuts.size();
        sort(cuts.begin(), cuts.end());
        vector cost(m, vector<int>(m, 0));
        for (int step=2; step<m; step++){
            for (int i=0; i<m-step; i++){
                int result=INT_MAX, j=i+step;
                for(int k=i+1; k<j; k++)
                    result=min(result, cost[i][k] +cost[k][j]);
                cost[i][j] = result+(cuts[j]-cuts[i]);
            }
        }
        return cost[0][m-1];
    }
};