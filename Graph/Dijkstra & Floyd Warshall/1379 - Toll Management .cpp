#include<bits/stdc++.h>
#define bst           ios_base::sync_with_stdio(0);
#define bug(x)        cerr<<#x<<'='<<x<<endl;
#define lp(i,a,b)     for(int i=a; i<=b; i++)
#define ll            long long int
#define eb            emplace_back
#define pb            push_back
#define mp            make_pair
using namespace std;
int main(){
    ll d, tc=1;
    cin>>d;
    while(d--){
        ll n, m, s,t, p, i, j, k;
        cin>>n>>m>>s>>t>>p;
        vector<pair<ll, ll>> path[n+5], ulta[n+5];
        while(m--){
            ll u, v, c;
            scanf("%lld %lld %lld", &u, &v, &c);
            path[u].pb({v, c});
            ulta[v].pb({u, c});   /// we will find the shortest paths to go in 't'
        }
        queue<ll> node;
        queue<pair<ll, ll>> q;
        vector<pair<ll, ll>> u;
        for(i=0; i<=n+10; i++) u.pb({1000000001, 0});  // first one is distance and other is the max edge
        u[t].first=0; u[t].second=0;
        node.push(t);
        q.push({0, 0});
        while(q.empty()==false){    /// shortest path to go in 't' from all node
            ll x=node.front(), mx=q.front().first, mw=q.front().second;
            ll limit=ulta[x].size();
            for(i=0; i<limit; i++){
                ll y=ulta[x][i].first, w=ulta[x][i].second;
                ll keep=mw+w;
                if(keep<u[y].first){
                    u[y].first=keep;                    
                    u[y].second=max(mx, w);
                    node.push(y);
                    q.push({max(w, mx), keep});
                }
                else if(keep==u[y].first && u[y].second<max(mw, w)){
                    u[y].second=max(mx, w);
                    node.push(y);
                    q.push({max(w, mx), keep});
                }
            }
            node.pop(); q.pop();
        }
        
        if(u[s].first>=1000000001){
            printf("Case %lld: -1\n", tc++);
            continue;
        }
        
        
        
        ll ans=0;
        bool flag=false;
        map<ll, map<ll, ll>> check;
        check[s][s]=1;
        node.push(s);
        q.push({0, 0});
        while(!q.empty()){    // now we will check all node...and will add the 't' to node+ 's' to node..if it less than 'p'
        /// we will check max edge on this
            ll x=node.front(), mx=q.front().first, mw=q.front().second;
            ll limit=path[x].size();
            for(i=0; i<limit; i++){
                ll y=path[x][i].first, w=path[x][i].second;
                if((w+mw+u[y].first)<=p && check[x][y]==0){
                    flag=true;
                    check[x][y]++;
                    node.push(y);
                    ll keep=max(mx, w);
                    keep=max(keep, u[y].second);
                    q.push({keep, mw+w});
                    ans=max(ans, keep);
                }
            }
            node.pop(); q.pop();
        }
        if(flag) printf("Case %lld: %lld\n", tc++, ans);
        else printf("Case %lld: -1\n", tc++);
    }

    return 0;
}
