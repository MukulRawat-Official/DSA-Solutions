class Solution {
public:
    vector<int>par;
    int find(int a){
        if(par[a] == a) return a;
        return par[a] = find(par[a]);
    }
    bool join(int a, int b){
        a = find(a);
        b = find(b);
        int t = 0;
        if(a != b){
          par[b] = a;
          t = 1;
        }
        
        return t;
    }
    int numSimilarGroups(vector<string>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        par.resize(n);
        iota(par.begin(),par.end(),0);
        int comp = n;
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
              int cnt = 0;
             
                
              for(int k = 0;k<m && cnt < 3;k++){
                   cnt += (arr[i][k] != arr[j][k]);    
              }  
                
              if(cnt % 2 == 0 && join(i,j)) comp--;
            }
        }
        
        return comp;
    }
};