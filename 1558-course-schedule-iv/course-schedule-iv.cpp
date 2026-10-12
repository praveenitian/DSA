class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for(auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        // isPrereq[i][j] = true agar 'i' is a prerequisite of 'j'
        vector<vector<bool>> isPrereq(numCourses, vector<bool>(numCourses, false));
        
        // Kahn's Algorithm
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(int v : adj[u]) {
                // Direct prerequisite
                isPrereq[u][v] = true; 
                
                // Indirect prerequisite: Jo bhi 'u' ke prerequisites the, wo 'v' ke bhi honge
                for(int i = 0; i < numCourses; i++) {
                    if(isPrereq[i][u]) {
                        isPrereq[i][v] = true;
                    }
                }
                
                if(--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        vector<bool> ans;
        for(auto& query : queries) {
            ans.push_back(isPrereq[query[0]][query[1]]);
        }
        
        return ans;
    }
};