class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll> pii;

    pii dp[16][2][2][10][3][2];
    const ll TOTAL_SIZE  = 16 * 2 * 2 * 10 * 3 * 2;;
    pii* dp_start = &dp[0][0][0][0][0][0];
    pii* dp_end = &dp[0][0][0][0][0][0] + TOTAL_SIZE;

    long long totalWaviness(long long num1, long long num2) {
        string a = to_string(num1), b = to_string(num2);
    
        reverse(a.begin(),a.end());
        while(a.size() < b.size()) a.push_back('0');
        reverse(a.begin(),a.end());

        ll n = b.size();
        fill(dp_start , dp_end, make_pair(-1, -1));

        function<pii(ll,ll,ll,ll,ll,ll)> recurr = [&](ll i , ll lf , ll rf , ll prev_num , ll prev_state , ll is_started){
            if(i == n) return make_pair(0ll,1ll); //  {total waviness, total valid suffix};
            

            pii& ans = dp[i][lf][rf][prev_num][prev_state][is_started];
            
            if(ans.first != -1) return ans; ans = {0,0};

            ll lb = lf ? 0 : a[i] - '0';
            ll ub = rf ? 9 : b[i] - '0';

            /*
                1 2 3 (i) ->   prev -> 0  (1 == 2) , 1 (1 > 2) , 2 (1 < 2);
            */


            for(ll j = lb; j <= ub; j++)
            {

                ll curr_state = 0;

                
                if(is_started && j > prev_num) curr_state = 2;
                else if(is_started && j < prev_num) curr_state = 1;
                ll is_started_updated = is_started |  (j > 0);

                ll nlf = lf | (j >  (a[i] - '0'));
                ll nrf = rf | (j <  (b[i] - '0'));


                pair<ll,ll> curr = recurr(i + 1 , nlf, nrf , j ,curr_state , is_started_updated);
                
                ans.first += curr.first;
                ans.second += curr.second;

                
                if(is_started && (curr_state ^ prev_state) == 3){
                    ans.first += curr.second;
                }
            }

            return ans;

        };


        return recurr(0,0,0,0,0,0).first;
    }
};