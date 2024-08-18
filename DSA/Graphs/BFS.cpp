class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        queue<int> q;
        vector<bool>vis(V,false);
        
        //initial state
        q.push(0);
        vis[0]=true;
        
        while(!q.empty()){
            int frontNode=q.front();
            q.pop(); //to empty the queue
            ans.push_back(frontNode);
            
            for(int nbr: adj[frontNode]){
                //all neighbors
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr]=true;
                }
            }
            
        }
        
        return ans;
    }
};
