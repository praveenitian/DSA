class Solution {
public:
    int minMutations = 1e9; // Minimum mutations track karne ke liye infinity se initialize kiya
    
    // Helper function to check agar do genes me sirf 1 character ka fark hai ya nahi
    bool isValid(string& s1, string& s2) {
        int diff = 0;
        for(int i = 0; i < 8; i++) {
            if(s1[i] != s2[i]) diff++;
        }
        return diff == 1;
    }
    
    void backtrack(string current, string& endGene, vector<string>& bank, unordered_set<string>& visited, int steps) {
        // Base Case: Agar hum endGene par pahunch gaye
        if(current == endGene) {
            minMutations = min(minMutations, steps);
            return;
        }
        
        // Optimization Pruning: Agar current steps pehle hi minimum se zyada ho gaye, toh aage mat jao
        if(steps >= minMutations) return;
        
        // Bank ki saari strings check karo
        for(string& str : bank) {
            // Agar string visited nahi hai aur current gene se sirf 1 mutation door hai
            if(visited.find(str) == visited.end() && isValid(current, str)) {
                
                visited.insert(str); // 1. CHOOSE (Mark as visited)
                
                backtrack(str, endGene, bank, visited, steps + 1); // 2. EXPLORE (Recursive call)
                
                visited.erase(str);  // 3. UN-CHOOSE (Backtrack / Backtrack state reset)
            }
        }
    }
    
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> visited;
        
        backtrack(startGene, endGene, bank, visited, 0);
        
        // Agar minMutations update nahi hua, matlab rasta nahi mila (-1)
        return minMutations == 1e9 ? -1 : minMutations;
    }
};