typedef long long ll;
class Solution {
public:
    struct DSU
{
    vector<ll> parent, size;
    ll comp;
    DSU(ll n)
    {
        parent.resize(n); size.resize(n);
        for(ll i = 0; i < n; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
        comp = n;
    }

    ll get(ll x)
    {
        return (parent[x] == x) ? x : parent[x] = get(parent[x]);
    }

    bool join(ll a, ll b)
    {
        a = get(a);
        b = get(b);

        if(a == b) return false;

        if(size[a] < size[b]) swap(a, b);

        size[a] += size[b];
        parent[b] = a;
        comp--;
        return true;
    }
};

    int minScore(int n, vector<vector<int>>& roads) {
        DSU ds(n);
 
        // int ans = 0;
        for(auto& x : roads){ ds.join(x[0]-1, x[1] - 1);}
        map<int,int>mp;
        
        int p = ds.get(0);
        int ans = INT_MAX;
        for(auto& x : roads){
            int pt = ds.get(x[0]-1);
            if(pt == p){
              ans = min(ans,x[2]);
            }
        }
        return ans;
    }
};