class Solution {
public:
    int cnt = 0 , ans = -1 , k;
    void recurr(int tot ,  int curr){
        if(tot == 1){
            ans = curr;
            return;
        }
          
        if(  k  > tot / 2 ){
            k -= tot / 2;
            recurr(tot / 2 , !curr);
        }
        else{
            recurr(tot / 2 , curr);
        }
    }
    int kthGrammar(int n, int k) {
        this->k = k;
        int tot = pow(2,n - 1);
        recurr(tot , 0);
        
        return ans;
    }
};