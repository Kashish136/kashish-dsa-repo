class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<int> distance(n+1, 1e9);
vector<vector<pair<int,int>>> adj(n+1);

for(auto it : times){
    int u = it[0];
    int v = it[1];
    int wt = it[2];

    adj[u].push_back({v, wt});
}

priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> pq;

distance[k] = 0;
pq.push({0, k});

while(!pq.empty()){
    auto it = pq.top();
    int time = it.first;
    int node = it.second;
    pq.pop();

    for(auto ex : adj[node]){
        int neighbour = ex.first;
        int dist = ex.second;

        if(time + dist < distance[neighbour]){
            distance[neighbour] = time + dist;
            pq.push({distance[neighbour], neighbour});
        }
    }
}

    for(int i = 1 ; i <= n ; i++){
        if(distance[i] == 1e9){
            return -1;
        }
    }

     return *max_element(distance.begin() , distance.end());
    }
};