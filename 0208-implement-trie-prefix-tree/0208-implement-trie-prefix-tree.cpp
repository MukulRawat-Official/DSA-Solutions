class Trie {
public:
    struct trie{
        int is_end = 0;
        trie* arr[26];  
    };
    
    trie* head; 
    Trie() {
        head = new trie();
    }
    
    void insert(string word) {
        trie* tmp = head;
        for(auto& x : word){
            if(!tmp->arr[x-'a']) tmp->arr[x-'a'] = new trie();
            tmp = tmp->arr[x-'a'];
        }
        
        tmp->is_end = 1;
    }
    
    bool search(string word) {
        trie* tmp = head;
        
        for(auto& x : word){
            if(!tmp->arr[x-'a']) return false;
            tmp = tmp ->arr[x-'a'];
        }
        
        return tmp->is_end;
    }
    
    bool startsWith(string prefix) {
         trie* tmp = head;
        
        for(auto& x : prefix){
            if(!tmp->arr[x-'a']) return false;
            tmp = tmp ->arr[x-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */