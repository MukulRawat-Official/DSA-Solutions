typedef long long ll;
template<class T, class U>
// T -> node, U->update.
struct Lsegtree {
  vector<T>st;
  vector<U>lazy;
  ll n;
  T identity_element;
  U identity_update;
  Lsegtree(ll n, T identity_element, U identity_update)
  {
    this->n = n;
    this->identity_element = identity_element;
    this->identity_update = identity_update;
    st.assign(4 * n, identity_element);
    lazy.assign(4 * n, identity_update);
  }
  T combine(T l, T r)
  {
    // change this function as required.
    T ans = max(l , r);
    return ans;
  }
  void buildUtil(ll v, ll tl, ll tr, vector<T>&a)
  {
    if (tl == tr)
    {
      st[v] = a[tl];
      return;
    }
    ll tm = (tl + tr) >> 1;
    buildUtil(2 * v + 1, tl, tm, a);
    buildUtil(2 * v + 2, tm + 1, tr, a);
    st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
  }
  // change the following 2 functions, and you're more or less done.
  T apply(T curr, U upd, ll tl, ll tr)
  {
    T ans = curr +  upd;
    return ans;
  }
  U combineUpdate(U old_upd, U new_upd, ll tl, ll tr)
  {
    U ans = old_upd + new_upd;
    return ans;
  }
  void push_down(ll v, ll tl, ll tr)
  {
    if (lazy[v] == identity_update)return;
    st[v] = apply(st[v], lazy[v], tl, tr);
    if (2 * v + 2 < 4 * n)
    {
      ll tm = (tl + tr) >> 1;
      lazy[2 * v + 1] = combineUpdate(lazy[2 * v + 1], lazy[v], tl, tm);
      lazy[2 * v + 2] = combineUpdate(lazy[2 * v + 2], lazy[v], tm + 1, tr);
    }
    lazy[v] = identity_update;
  }
  T queryUtil(ll v, ll tl, ll tr, ll l, ll r)
  {
    push_down(v, tl, tr);
    if (l > r)return identity_element;
    if (tr < l or tl > r)
    {
      return identity_element;
    }
    if (l <= tl and r >= tr)
    {
      return st[v];
    }
    ll tm = (tl + tr) >> 1;
    return combine(queryUtil(2 * v + 1, tl, tm, l, r), queryUtil(2 * v + 2, tm + 1, tr, l, r));
  }

  void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd)
  {
    push_down(v, tl, tr);
    if (tr < l or tl > r)return;
    if (tl >= l and tr <= r)
    {
      lazy[v] = combineUpdate(lazy[v], upd, tl, tr);
      push_down(v, tl, tr);
    }
    else
    {
      ll tm = (tl + tr) >> 1;
      updateUtil(2 * v + 1, tl, tm, l, r, upd);
      updateUtil(2 * v + 2, tm + 1, tr, l, r, upd);
      st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
    }
  }



  void build(vector<T>a)
  {
    assert( (ll)a.size() == (ll)n);
    buildUtil(0, 0, n - 1, a);
  }
  T query(ll l, ll r)
  {
    return queryUtil(0, 0, n - 1, l, r);
  }
  void update(ll l, ll r, U upd)
  {
    updateUtil(0, 0, n - 1, l, r, upd);
  }
};

Lsegtree<ll,ll> st(1e5 + 1,0,0);
class Solution {
public:
    
    long long maxBalancedSubsequenceSum(vector<int>& tmp) {
        ll n = tmp.size();
        
        vector<ll> pos(n,0);
        iota(pos.begin(),pos.end() , 0);
        sort(pos.begin(),pos.end() , [&](ll a , ll b){
           ll f = 1ll* tmp[a] - a;
           ll s = 1ll* tmp[b] - b;
           if(f == s)  return a < b;
           return f < s; 
        });
        
        ll cnt = 0;
        for(auto& x : tmp){
            cnt += x < 0;
        }
        if(cnt == tmp.size()){
            sort(tmp.begin(),tmp.end());
            return tmp.back();
        }
        
        map<ll,ll>mp;
        for(int i = 0;i<n;i++) mp[pos[i]] = i;
        
        for(auto& x : st.st) x = 0;
        for(auto& x : st.lazy) x = 0;
           
        
      
        
        ll ans = 0;
        for(int i = 0;i<n;i++){
            ll idx = mp[i];
            if(tmp[i] > 0){
                ll sum = tmp[i];
                if(idx)  {
                   sum += st.query(0,idx-1);
                }
                st.update(idx,idx,sum);         
            }
        }
        
        return st.query(0,n-1);
    }
};