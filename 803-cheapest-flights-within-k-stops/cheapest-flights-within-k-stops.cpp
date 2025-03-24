class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights,
    int src, int dst, int K)
    {
        // Create the adjacency list to depict airports and flights in
        // the form of a graph.
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Create a queue which stores the node and their distances from the
        // source in the form of {node, dist}
        queue<pair<int, int>> q;
        
        q.push({src, 0});

        // Distance array to store the updated distances from the source.
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        int steps = 0;
        // Iterate through the graph using a queue like in Dijkstra with 
     
        while (!q.empty() && steps<=K)
        {
            int N = q.size();
            while(N--){
                int u = q.front().first;
                int price = q.front().second;
                q.pop();
                
                for(auto &p: adj[u]){
                    int v = p.first;
                    int cost = p.second;
                    if(dist[v]>price+cost){
                        dist[v]=price+cost;
                        q.push({v,price+cost});
                        
                    }
                }
            }
            steps++;
        }
        if(dist[dst]==1e9)
        return -1;
        
        return dist[dst];
    }
};
   