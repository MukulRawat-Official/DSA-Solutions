//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&arr){
	    int n = arr.size();
	 for (int num = 0; num < n; num++)
     {
      for (int i = 0; i < n; i++) {
        if (i == num) continue;
        for (int j = 0; j < n; j++) {
          if (j == num || i == j || arr[i][num] == -1 || arr[num][j] == -1) continue;
         if(arr[i][j] == -1) arr[i][j] = arr[i][num] + arr[num][j];
         else
         arr[i][j] = min(arr[i][j] , arr[i][num] + arr[num][j]);
         }
       }
     }

	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends