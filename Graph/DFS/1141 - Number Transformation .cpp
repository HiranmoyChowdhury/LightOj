#include<bits/stdc++.h>
#define bst           ios_base::sync_with_stdio(0);
#define bug(x)        cerr<<#x<<'='<<x<<endl;
#define lp(i,a,b)     for(int i=a; i<=b; i++)
#define ll            long long int
#define pb            emplace_back
using namespace std;
vector<ll> primes[1002];
ll ans;                  //step
bool npsble[1002];       //is it possible to go in 'b' or not from a node
ll q[1002];               // if it's possible, then how many steps required to go in 'b' from current node
ll dfs(ll a, ll b, ll take){   //'take' is the number of step to reach current node from 'a'
        if(a==b){
            if(take<ans) ans=take;
            return 1;
        }
        ll k=0, p=10000;
        for(ll i=primes[a].size()-1; i>=0; i--){
            ll x=primes[a][i];
            if(a+x<=b){
                if(q[a+x]>0){             //we saved some time by storing steps
                    ans=min(ans, take+q[a+x]+1);
                    p=min(p, q[a+x]+1);     //here 'p' is the num of steps to go in 'b' from current node(a)
                }
                else if(npsble[a+x]==false){
                    k=dfs(a+x, b, take+1);
                    if(k==0){
                        npsble[a+x]=true;
                    }
                    else if(k>0) p=min(p, k);
                }
            }
        }
        if(p>1009){
            npsble[a]=true;
            return 0;
        }
        else{
            q[a]=p; 
            return p+1;
        }
}



int main(){
    ll t, tc=1;
    bool see[1050]={};
    for(ll i=4; i<=1000; i+=2){
        see[i]=true;              // divisors of every number
        primes[i].pb(2);
    }
    for(ll z=3; z<=500; z++){
        if(see[z]==false){
            for(ll xy=z+z; xy<=1000; xy+=z){
                see[xy]=true;
                primes[xy].pb(z);
            }
        }
    }
    cin>>t;
    while(t--){
        ll a, b, i, j, k, l;
        scanf("%lld %lld", &a, &b);
        if(a==b){
            printf("Case %lld: 0\n", tc++);
            continue;
        }
        if(a>b || see[a]==false){
            printf("Case %lld: -1\n", tc++);
            continue;
        }
        
        for(i=0; i<=1000; i++){
            npsble[i]=false;
            q[i]=0;               // making prepare for this test case...
        }
        
        ll take=0;
        ans=1009;
        
        for(i=primes[a].size()-1; i>=0; i--){
            ll x=primes[a][i];
            if(a+x<=b){
                if(q[a+x]>0){
                    ans=min(ans, take+q[a+x]);
                }
                else if(npsble[a+x]==false){
                    k=dfs(a+x, b, take+1);
                    if(k==0) npsble[a+x]=true;
                }
            }
        }
        if(ans>=1009) printf("Case %lld: -1\n", tc++);
        else printf("Case %lld: %lld\n", tc++, ans);
    }
    return 0;
}

