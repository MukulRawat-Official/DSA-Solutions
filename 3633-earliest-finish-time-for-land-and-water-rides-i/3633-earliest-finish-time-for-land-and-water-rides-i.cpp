class Solution {
public:
    int give_min_time(int sa , int sb , int da , int db)
    {   
        int cnt = 0;
        if(sa > sb){
            swap(sa,sb);
            swap(da,db);
        }

        cnt = max(sa + da , sb) + db;
        return cnt;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int N = landStartTime.size() , M = waterStartTime.size();
        int ans = INT_MAX;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++){
                ans = min(ans, give_min_time(landStartTime[i] , waterStartTime[j] , landDuration[i] ,  waterDuration[j]));
            }
        }

        return ans;
        
    }
};