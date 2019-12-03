#include<bits/stdc++.h>
#define bst           ios_base::sync_with_stdio(0);
#define bug(x)        cerr<<#x<<'='<<x<<endl;
#define lp(i,a,b)     for(int i=a; i<=b; i++)
#define ll            long long int
#define pb            emplace_back
using namespace std;
int lalax[4]={0, 0, 1, -1};
int lalay[4]={1, -1, 0, 0};
char arr[205][205];
int fire_pos[205][205];
int main(){
    int t, tc=1;
    cin>>t;
    while(t--){
        int r, c, i,j, k;
        cin>>r>>c;
        int xj, yj;
        queue<int> qx, qy, fx, fy;
        for(i=0; i<r; i++){
            scanf("%s", arr[i]);
            for(j=0; j<c; j++){
                if(arr[i][j]=='J'){
                    xj=j, yj=i;
                }
                else if(arr[i][j]=='F'){
                    fx.push(j); fy.push(i);
                }
            }
        }
        for(i=0; i<r; i++) for(j=0; j<c; j++) fire_pos[i][j]=0;// distance from janes position
        qx.push(xj);
        qy.push(yj);
        bool check[r][c]={};
        while(!qx.empty()){
            int x, y;
            qx.push(500); qy.push(500); fx.push(500); fy.push(500);//distince all level
            if(!fx.empty()){
                while(fx.front()!=500){
                    x=fx.front();
                    y=fy.front();
                    arr[y][x]='#';
                    for(i=0; i<4; i++){
                        if(x+lalax[i]<c && x+lalax[i]>=0 && y+lalay[i]>=0 && y+lalay[i]<r && arr[y+lalay[i]][x+lalax[i]]=='.'){
                            fx.push(x+lalax[i]);
                            fy.push(y+lalay[i]);
                            arr[y+lalay[i]][x+lalax[i]]='#';
                        }
                    }
                    fx.pop(); fy.pop();
                }
            }
            fx.pop(); fy.pop(); //pop 500;
            while(qx.front()!=500){
                x=qx.front();
                y=qy.front();
                check[y][x]=true;
                for(i=0; i<4; i++){
                    if(x+lalax[i]<c && x+lalax[i]>=0 && y+lalay[i]>=0 && y+lalay[i]<r && arr[y+lalay[i]][x+lalax[i]]=='.' && check[y+lalay[i]][x+lalax[i]]==false){
                        qx.push(x+lalax[i]);
                        qy.push(y+lalay[i]);
                        check[y+lalay[i]][x+lalax[i]]=true;
                        fire_pos[y+lalay[i]][x+lalax[i]]=fire_pos[y][x]+1;
                    }
                }
                qx.pop(); qy.pop();
            }
            qx.pop(); qy.pop();// pop 500;
        }
        int ans=1024;
        for(i=0; i<c; i++){
            if(fire_pos[0][i]>0) ans=min(ans, fire_pos[0][i]);
            if(fire_pos[r-1][i]>0) ans=min(ans, fire_pos[r-1][i]);
        }
        for(i=0; i<r; i++){
            if(fire_pos[i][0]>0) ans=min(ans, fire_pos[i][0]);
            if(fire_pos[i][c-1]>0) ans=min(ans, fire_pos[i][c-1]);
        }
        printf("Case %d: ", tc++);
        if(xj==0 || xj==c-1 || yj==0 || yj==r-1) cout<<1<<endl;
        else if(ans==1024) puts("IMPOSSIBLE");
        else printf("%d\n", ans+1);
    }


    return 0;
}
