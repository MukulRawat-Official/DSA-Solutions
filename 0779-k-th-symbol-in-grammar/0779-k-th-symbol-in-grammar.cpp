class Solution {
public:
    int cnt = 0 , ans = -1 , k;
    void recurr(int i , int n , int tot ,  int curr){
        if(i == n){
            ans = curr;
            return;
        }
          
        if(  k  > tot / 2 ){
            k -= tot / 2;
            recurr(i+1 , n , tot / 2 , !curr);
        }
        else{
            recurr(i+1, n , tot / 2 , curr);
        }
    }
    int kthGrammar(int n, int k) {
        this->k = k;
        int tot = pow(2,n - 1);
        recurr(1,n, tot , 0);
        
        return ans;
    }
};