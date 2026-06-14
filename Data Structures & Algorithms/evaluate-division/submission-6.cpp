class Solution {
public:

   double helper(string src , string dest , unordered_map<string , vector<pair<string , double>>>&adj){


       if(!adj.count(src) || !adj.count(dest)){
          return -1.0;
        }

       queue<pair<string,double>>q;
       unordered_set<string>visited;

       q.push({src , 1.0});
        visited.insert(src);


       while(!q.empty()){
        auto it = q.front();
        string str = it.first;
        double wt = it.second;
        q.pop();

        if(str == dest){
            return wt;
        }

        for( auto [nei , neiWeight] : adj[str]){
           if(!visited.count(nei)){
              visited.insert(nei);
              q.emplace(nei, wt * neiWeight);
           }
        }
       }

    return -1.0;
   }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        

    unordered_map<string , vector<pair<string , double>>>adj;
    for(int i = 0 ; i < equations.size() ; i++){

        string str1 = equations[i][0];
        string str2 = equations[i][1];
        adj[str1].push_back({str2 , values[i]});
        adj[str2].push_back({str1 , 1.0/values[i]}); }

        vector<double>output ;
        for( int i = 0 ; i < queries.size() ; i++){
            string src = queries[i][0];
            string dest = queries[i][1];

            double answer = helper(src , dest , adj);
            output.push_back(answer);
        }
    
    return output;

    }
};