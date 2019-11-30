#include<bits/stdc++.h>
#define bst           ios_base::sync_with_stdio(0);
#define bug(x)        cerr<<#x<<'='<<x<<endl;
#define lp(i,a,b)     for(int i=a; i<=b; i++)
#define ll            long long int
#define pb            emplace_back
using namespace std;
int main(){
    ll t, tc=1;
    cin>>t;
    while(t--){
        ll n, m, i, j, k;
        scanf("%lld %lld", &n, &m);
        ll tk[n+2], carry=0;
        for(i=1; i<=n; i++){
            scanf("%lld", &tk[i]);
            carry+=tk[i];
        }
        
        vector<ll> edge[n+1];
        ll u, v;
        for(i=0; i<m; i++){
            scanf("%lld %lld", &u, &v);
            edge[u].pb(v);
            edge[v].pb(u);
        }
        printf("Case %lld: ", tc++);
        if(carry%n!=0){
            printf("No\n");
            continue;
        }
        bool check[n+2]={}, flag=false;
        ll per_person=carry/n;
        for(i=1; i<=n; i++){
            if(check[i]==false){
                queue<ll> q;
                q.push(i);
                ll keep=0, person=0;
                while(!q.empty()){
                    ll x=q.front();
                    if(check[x]==false){
                        check[x]=true;
                        keep+=tk[x];
                        person++;
                    }
                    for(j=0; j<edge[x].size(); j++){
                        if(check[edge[x][j]]==false) q.push(edge[x][j]);
                    }
                    q.pop();
                }
                if(keep%person!=0) flag=true;
                else if(per_person!=(keep/person)) flag=true;
                
            }
            if(flag==true) break;
        }
        if(flag==false) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
