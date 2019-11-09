#include<bits/stdc++.h>
using namespace std ;
const int nax= 1e5+10 ;

vector< vector<int> > graph(1,vector<int>() );
int team_one = 0 , team_two = 0;

void fuck(int node , bool isvisited[] , bool first_team){
    if(first_team == true) team_one ++ ;
    else  team_two++ ;
    isvisited[node] = true ;
    
    for(auto x : graph[node]){
        if(isvisited[x] == false){
            fuck(x , isvisited ,  first_team^1);
        }    
    }
    
    
    
}

void solve() {
    int edge ; scanf("%d",&edge);
    
    graph = vector< vector<int> > (nax,vector<int> ());
    bool gotit[nax]= {} ;
    for(int i = 0 ; i < edge ; i++){
        int u , v;
        scanf("%d%d",&u,&v);
        gotit[u] = gotit[v] = true ;
        graph[u].push_back(v);
        graph[v].emplace_back(u);
    }
    
    bool isvisited[nax+5] ={} ;
    int ans = 0 ;
    for(int i = 0 ; i < nax ; i++){
        
        if(gotit[i] == true && isvisited[i] == false){
            team_one = team_two = 0;
            fuck(i , isvisited , true );
            ans += max(team_one , team_two) ;
        }
        
    }
    printf("%d\n",ans) ;
}

int main(){
    int testcase ;
    scanf("%d",&testcase);
    
    for(int i= 1 ; i<= testcase ; i++){
        printf("Case %d: ",i);
        solve() ;
    }
    
    return  0;
}
