
class Solution {
public:
    struct comparator
    {
        bool operator() (pair<int, string>& a, pair<int, string>& b)
        {
            if(a.first == b.first)     return a.second > b.second;
            return a.first < b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>freq;
        for(auto& x : words) freq[x]++;
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,comparator>q;
        for(auto& x : freq)
            q.push({x.second,x.first});
        vector<string>ans;
        for(auto& x : freq)
        {
            ans.push_back(q.top().second);
            q.pop();
            k--; if(!k) break;
        }
        
        return ans;
    }
};