void dfs(int src,vector<bool>& vis,vector<int> adj[],vector<int>& ans){
        //initial case or base case type
        vis[src]=true;
        ans.push_back(src);
        
        for(int i=0;i<adj[src].size();i++){
            //traverse over the nbr's
            int nbr = (adj[src])[i];  // Correctly accessing the ith neighbor of src
            if(!vis[nbr]){
                //go over the nbr's of the children node 
                dfs(nbr, vis,adj,ans);
            }
        }
    }


vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V,false);
        
        int src=0;
        dfs(src,vis,adj,ans);
        
        return ans;
    }
