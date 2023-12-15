class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> outgoing;
        unordered_set<string> incoming;

        for (const auto& path : paths) {
            outgoing.insert(path[0]);
            incoming.insert(path[1]);
        }

        for (const auto& city : incoming) {
            if (outgoing.find(city) == outgoing.end()) {
                return city;
            }
        } 
        
        return "";;
    }
};