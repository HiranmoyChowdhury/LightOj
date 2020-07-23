///Hiranmoy Das Chowdhury
complexity: O( query*n*log(n) )


#include<bits/stdc++.h>
#define bst           ios_base::sync_with_stdio(0);
#define bug(x)        cerr<<#x<<'='<<x<<endl;
#define lp(i,a,b)     for(int i=a; i<=b; i++)
#define ll            long long int
#define eb            emplace_back
#define pb            push_back
#define inp(n)        scanf("%lld", &n);
using namespace std;
ll arr[509][509], mx[509][3000], now, keep, a, b;
void init(ll n, ll l, ll r){
    if(l==r){
        mx[now][n]=arr[now][l];
        return;
    }
    ll mid=(l+r)>>1, n1=n+n, n2=n+1+n;
    init(n1, l, mid); init(n2, mid+1, r);
    mx[now][n]=max(mx[now][n1], mx[now][n2]);
}
void ff(ll n, ll l, ll r){
    if(l>b || r<a) return;
    if(l>=a && r<=b){
        keep=max(keep, mx[now][n]);
        return;
    }
    ll mid=(l+r)>>1, n1=n+n, n2=n+1+n;
    ff(n1, l, mid);
    ff(n2, mid+1, r);
}
int main(){
    ll t;
    scanf("%lld", &t);
    for(ll cas=1; cas<=t; cas++){
        ll n, i, j ,k, q;
        scanf("%lld %lld", &n, &q);
        for(i=1; i<=n; i++) for(j=1; j<=n; j++) scanf("%lld", &arr[i][j]);
        for(i=1; i<=n; i++){
            now=i;
            init(1, 1, n);
        }
        printf("Case %lld:\n", cas);
        for(ll cholbe=0; cholbe<q; cholbe++){
            ll x, y, s;
            scanf("%lld%lld%lld", &x, &y, &s);
            ll ans=0;
            for(i=x; i<x+s; i++){
                a=y, b=y+s-1, now=i;
                keep=0;
                ff(1, 1, n);
                ans=max(ans, keep);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
