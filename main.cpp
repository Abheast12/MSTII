#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi> > pq; 
int n, e, s;
vector<pair<int, int>>v[50100];
int a[50100];
int vis[50100];
int main() {
  cin >> n >> e;
  int a2, b, c;
  for(int i=0; i<e; i++){
    cin >> a2 >> b >> c;
    v[a2].push_back({b, c});
    v[b].push_back({a2, c});
  }
  for(int i=1; i<=n; i++){
    a[i]=INT_MAX;
  }
  a[1]=0;
  int cur = 1;
  pq.push({0, 1});
  while(!pq.empty()){
    for(int i=0; i<v[cur].size(); i++){
      if(a[v[cur][i].first]>(v[cur][i].second) && !vis[v[cur][i].first]){
        a[v[cur][i].first] = v[cur][i].second;
        pq.push({v[cur][i].second, v[cur][i].first});
      }
    }
    pq.pop();
    vis[cur]=1;
    cur = pq.top().second;
  }
  long long total = 0;
  for(int i=1; i<=n; i++){
    total+=a[i];
  }
  cout << total << endl;
}