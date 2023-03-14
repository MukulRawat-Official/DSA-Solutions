//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int nc) {
        int n = arr.size() , m = arr[0].size();
        int st = arr[sr][sc];
        if(st == nc) return arr;
        queue<long>q;
        q.push({sr*m + sc});
        arr[sr][sc] = nc;
        vector<int> le = {0,1,0,-1} , ri= {1,0,-1,0};
        
        // cout<<st<<endl;
        while(q.size()){
            long curr = q.front(); q.pop();
            int r = curr / m , c = curr % m;
            
            for(int k = 0;k<4;k++){
                long x = r + le[k];
                long y = c + ri[k];
                
                if(x < 0 || y < 0  || x == n || y == m || arr[x][y] != st) continue;
                arr[x][y] = nc;
                q.push({x*m + y});
            }
        }
        
        return arr;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends