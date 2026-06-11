class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        

        vector<vector<int>>adj(numCourses);

        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        
        vector<int>indegree(numCourses,0);
        for(int i = 0 ; i < numCourses ; i++){
           for( auto it : adj[i]){
            indegree[it]++;
           }
        }


        queue<int>q;
        vector<int>topo;
        for( int i = 0 ; i < numCourses ; i++){
            if(indegee[i] == 0){
                q.push(i);
            }
        }


        while(!q.empty()){
            auto it = q.front();
            q.pop();
            topo.push_back(it);


            for( auto ex : adj[it]){
                indegree[ex]--;
                if(indegree[ex] == 0){
                    q.push(i);
                }
            }
        }


        if(topo.size() == numCourses){
            return topo;
        }

        return {};
    }
};
