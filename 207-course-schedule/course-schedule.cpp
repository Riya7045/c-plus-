class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);  // Adjacency list
        vector<int>indeg(numCourses,0);
       // Build adjacency list and in-degree count
        for (auto& i : prerequisites) {
            int course = i[0];  // The course to be taken
            int prereq = i[1];  // The prerequisite
            adj[prereq].push_back(course);  // Directed edge: prereq → course
            indeg[course]++;  // Increment in-degree of the course
        }
        queue<int>q;
        for(int i =0;i<numCourses;i++){
            if(!indeg[i])
            q.push(i);// Push courses with no prerequisites
        } 
        int count = 0;   
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(int j =0;j<adj[node].size();j++){
                indeg[adj[node][j]]--;
                if(indeg[adj[node][j]]==0)
                    q.push(adj[node][j]);
            }
        }
        
        
        
        return count==numCourses;
    
    }
};