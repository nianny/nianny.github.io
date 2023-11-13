#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pi;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  //y is height
  //x is width
  int x,y,start_x,start_y;
  cin >> x >> y >> start_x >> start_y;
  char adj[y+1][x+1];
  memset(adj,'*',sizeof(adj));
  int dx[8]={0,0,1,-1,1,1,-1,-1};
  int dy[8]={1,-1,0,0,-1,1,1,-1};
  for(int i=1; i<=y; i++){
    for(int j=1; j<=x; j++){
      cin>>adj[i][j];
    }
  }
  queue<pi>q;
  int dist[y+1][x+1];
  memset(dist,-1,sizeof(dist));
  dist[start_y][start_x]=0;
  q.push(make_pair(start_x,start_y));
  while(!q.empty()){
    pi cur=q.front();
    q.pop();
    int X=cur.first,Y=cur.second;
    for(int i=0; i<8; i++){
      int nx=X+dx[i],ny=Y+dy[i];
      if(nx<1||ny<1||nx>x||ny>y||dist[ny][nx]!=-1||adj[ny][nx]=='*')continue;
      dist[ny][nx]=dist[Y][X]+1;
      q.push(make_pair(nx,ny));
    }
  }
  int ans=INT_MIN;
  for(int i=1; i<=y; i++){
    for(int j=1; j<=x; j++){
      ans=max(ans,dist[i][j]);
    }
  }
  cout<<ans;
}