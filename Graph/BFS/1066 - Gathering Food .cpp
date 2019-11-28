#include<bits/stdc++.h>
#define bst           ios_base::sync_with_stdio(0);
#define bug(x)        cerr<<#x<<'='<<x<<endl;
#define lp(i,a,b)     for(int i=a; i<=b; i++)
#define ll            long long int
#define pb            emplace_back
using namespace std;
int xiii[5]={0, 0, 1, -1};
int yiii[5]={1, -1, 0, 0};
char arr[15][15];
ll x, y;
ll bfs(char b, ll n){
    bool flag=false;
    bool check[n+1][n+1]={};
    ll dhoro=500;
    queue<ll> qx, qy;
    ll cnt=0;
    qx.push(x);
    qy.push(y);
    qx.push(dhoro);   // 'dhoro' is given for distinct the levels.....
    qy.push(dhoro++);
    check[y][x]=true;
    while(!qx.empty()){
        ll p=qx.front();
        ll q=qy.front();
        if(p>800) break;   // it means there is more than 300 levels...its impossible
        else if(p>=500){
            qx.push(dhoro);
            qy.push(dhoro++);
            qx.pop();
            qy.pop();
            cnt++;
            continue;
        }
        else if(arr[q][p]==b){
            flag=true;
            x=p; y=q;
            break;
        }
        for(int i=0; i<4; i++){
            ll xi=p+xiii[i], yi=q+yiii[i];
            if(yi>=0 && xi>=0 && xi<n && yi<n && (arr[yi][xi]=='.' || arr[yi][xi]==b) && check[yi][xi]==false){
                check[yi][xi]=true;
                qx.push(xi);
                qy.push(yi);
            }
        }
        qx.pop();
        qy.pop();
    }
    if(flag==false) return -1;
    else return cnt;
    
}
int main(){
    ll t, tc=1, i, j, k;
    cin>>t;
    while(t--){
        ll n, num=1;
        x=y=15;
        scanf("%lld", &n);
        for(i=0; i<n; i++){
            scanf("%s", arr[i]);
            for(j=0; j<n; j++){
                if(arr[i][j]=='A') x=j, y=i;
                else if(arr[i][j]>'A' && arr[i][j]<='Z') num++;
            }
        }
        if(x==15){
            printf("Case %lld: Impossible\n", tc++);
            continue;
        }
        ll ans=0, keep=0;
        for(i=1; i<num; i++){
            arr[y][x]='.';
            char a;
            a='A'+i;     // a is the next letter from present
            keep=bfs(a, n);
            if(keep==-1) break;
            else ans+=keep;
        }
        if(keep==-1) printf("Case %lld: Impossible\n", tc++);
        else printf("Case %lld: %lld\n", tc++, ans);
        
        
    }
    return 0;
}

