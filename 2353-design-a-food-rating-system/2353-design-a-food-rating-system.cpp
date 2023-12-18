class FoodRatings {
public:
   
    
    
    map<string,int>f; // food index 
    map<string,string>c; // food cuisined 
    map<string,set<pair<int , string>>>m; // cuisine rating 
    vector<int> ratings;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& rating) {
        int n = foods.size();
        ratings = rating;
        for(int i = 0;i<n;i++)
        {
            f[foods[i]] = i;
            c[foods[i]] = cuisines[i]; 
            m[cuisines[i]].insert({-rating[i] , foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int idx = f[food];
        string& s = c[food];
        
        m[s].erase({-ratings[idx],food});
        ratings[idx] = newRating;
        m[s].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
       
        auto it = m[cuisine].begin();
        return  it->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */