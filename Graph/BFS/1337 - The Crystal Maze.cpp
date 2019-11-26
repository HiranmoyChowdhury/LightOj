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
        ll m, n, q, i, j, k=0;
        scanf("%lld %lld %lld", &m, &n, &q);
        char arr[m+1][n+1];
        for(i=0; i<m; i++){
            scanf("%s", arr[i]);
        }
        vector<ll> land[q+2];
        for(i=0; i<q; i++){
            ll x, y;
            scanf("%lld %lld", &x, &y);
            arr[x-1][y-1]='X';          // landing positions ar denoted by 'X'
            land[k].pb(x-1);
            land[k++].pb(y-1);
        }
        bool check[m+1][n+1]={};     //BFS
        ll ans[m+1][n+1];
        for(i=0; i<q; i++){
            if(check[land[i][0]][land[i][1]]==false){
                ll xi=land[i][0], yi=land[i][1];
                queue<ll> qx, qy;
                qx.push(xi);
                qy.push(yi);
                ll pointx[q+1], pointy[q+1], p_num=1;   //while we are checking, can we go from a landing point to 'C', we will count, how many landing point are connect o each other...
                                                        //so, they have equal 'C'
                pointx[0]=xi; pointy[0]=yi;
                check[xi][yi]=true;
                ll keep=0;
                while(!qx.empty()){
                    xi=qx.front();
                    yi=qy.front();
                    ll lefty=yi-1, leftx=xi;
                    if(lefty>=0 && arr[leftx][lefty]!='#' && check[leftx][lefty]==false){
                        if(arr[leftx][lefty]=='C'){
                            keep++;
                        }
                        else if(arr[leftx][lefty]=='X'){
                            pointx[p_num]=leftx;
                            pointy[p_num++]=lefty;
                        }
                        qx.push(leftx);
                        qy.push(lefty);
                        check[leftx][lefty]=true;
                    }
                    ll righty=yi+1, rightx=xi;
                    if(righty<n && arr[rightx][righty]!='#' && check[rightx][righty]==false){
                        if(arr[rightx][righty]=='C'){
                            keep++;
                        }
                        else if(arr[rightx][righty]=='X'){
                            pointx[p_num]=rightx;
                            pointy[p_num++]=righty;
                        }
                        qx.push(rightx);
                        qy.push(righty);
                        check[rightx][righty]=true;
                    }
                    ll upy=yi, upx=xi-1;
                    if(upx>=0 && arr[upx][upy]!='#' && check[upx][upy]==false){
                        if(arr[upx][upy]=='C'){
                            keep++;
                        }
                        else if(arr[upx][upy]=='X'){
                            pointx[p_num]=upx;
                            pointy[p_num++]=upy;
                        }
                        qx.push(upx);
                        qy.push(upy);
                        check[upx][upy]=true;
                    }
                    ll downy=yi, downx=xi+1;
                    if(downx<m && arr[downx][downy]!='#' && check[downx][downy]==false){
                        if(arr[downx][downy]=='C'){
                            keep++;
                        }
                        else if(arr[downx][downy]=='X'){
                            pointx[p_num]=downx;
                            pointy[p_num++]=downy;
                        }
                        qx.push(downx);
                        qy.push(downy);
                        check[downx][downy]=true;
                    }
                    qx.pop();
                    qy.pop();
                }
                for(j=0; j<p_num; j++){
                    ans[pointx[j]][pointy[j]]=keep;   //they all have equal 'C'
                }
            }
        }
        printf("Case %lld:\n", tc++);
        for(i=0; i<q; i++){
            ll xi, yi;
            xi=land[i][0]; yi=land[i][1];
            printf("%lld\n", ans[xi][yi]);
        }
    }

    return 0;
}

