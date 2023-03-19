class WordDictionary {
public:
    struct trie{
       trie* arr[26];
       bool is_end = false;
    };
    trie* head;
    WordDictionary() {
        head = new trie();
    }
    
    void addWord(string word) {
        trie* root = head;
        
        for(auto& x : word){
            if(!root->arr[x-'a']) root->arr[x-'a'] = new trie();
            root = root->arr[x-'a']; 
        }
        root->is_end = true;
    }
    
    bool search(string word) {
        trie* tmp = head;
        auto give = [&](trie* tmp , int idx , auto&& give)->bool{
          if(idx == word.size()) return tmp->is_end;
          
          bool ans = false;
          if(word[idx] == '.'){
              for(int i = 0;i<26;i++) {
                if(tmp->arr[i]) if(give(tmp->arr[i] , idx+1 , give)) return true;  
              }
          }
            
          else if(tmp->arr[word[idx] - 'a'])
           ans |= give(tmp->arr[word[idx]-'a'] , idx+1 , give);
          
          return ans;
        };
        
        return give(tmp , 0 , give);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */