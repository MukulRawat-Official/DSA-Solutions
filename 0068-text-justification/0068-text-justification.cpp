class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        
        vector<string>ans;
        int n = words.size();
        int i = 0;
        while(i<n){
            int cnt = 0;
            vector<string>ad , sp;
            while(i < n && (cnt + words[i].size() <= maxWidth) || !cnt){
                cnt += words[i].size() + 1;
                ad.push_back(words[i++]);
                sp.push_back(" ");
            }
            
      
            
            
            int j =0 , m = sp.size() , f = 0;
            
            if(m > 1 || cnt > maxWidth) { sp.pop_back(); m--; cnt--;}
            
            
            cnt = max(0,maxWidth - cnt);
            
            while(cnt--){
                sp[f++].push_back(' ');
                f %= m;
            }
            
            string anss;
            
            for(int i = 0;i<ad.size();i++){
              anss += ad[i];
                
              if(i < sp.size())
              anss += sp[i];
            }
            ans.push_back(anss);
        }
        
        string& lst = ans.back() , tmp;
        for(int i = 0;i<maxWidth;i++){
            if(lst[i] == ' ' && lst[i] == lst[i-1]) continue;
            tmp.push_back(lst[i]);
        }
        
        while(tmp.size() < maxWidth) tmp += " ";
        lst = tmp;
                
        
        return ans;
    }
};