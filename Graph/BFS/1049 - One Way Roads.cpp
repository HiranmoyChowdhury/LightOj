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
        ll n, i, j, k=0, l;
        vector<ll> d[102], dw[102], ndw[102]; // d-directed, dw-weight of directed road, ndw- not
        scanf("%lld", &n);
        for(i=0; i<n; i++){
            ll u, v, ch;
            scanf("%lld %lld %lld", &u, &v, &ch);
            if(u>1 && v>1){
                d[u].pb(v);
                dw[u].pb(0);
                ndw[u].pb(ch);
                d[v].pb(u);
                dw[v].pb(ch);
                ndw[v].pb(0);
            }
            else if(k==0){    // if there is '1', then in the first move, we will go with one direction, left or right
                if(v==1){
                    d[v].pb(u);      
                    dw[v].pb(ch);
                    ndw[v].pb(0);
                }
                else{
                    d[u].pb(v);
                    dw[u].pb(0);
                    ndw[u].pb(ch);    
                }
                k++;
            }
            else{        // for the last move we will get back to '1' again...
                if(u==1){
                    d[v].pb(u);
                    dw[v].pb(ch);
                    ndw[v].pb(0);    
                }
                else{
                    d[u].pb(v);
                    dw[u].pb(0);
                    ndw[u].pb(ch);
                }
            }
        }
        ll ansl=0, ansr=0;
        queue<ll> Q;
        Q.push(1);
        bool check[102]={};   // in the last move we have to visit '1' again, that's why '1' is false....
        while(!Q.empty()){
            ll num=Q.front();
            for(i=0; i<d[num].size(); i++){
                if(check[d[num][i]]==false){
                    Q.push(d[num][i]);
                    ansl+=dw[num][i];          
                    ansr+=ndw[num][i];
                    check[d[num][i]]=true;
                }
            }
            Q.pop();
        }
        
        printf("Case %lld: %lld\n", tc++, min(ansl, ansr));
        
        
    }
    
    return 0;
}

