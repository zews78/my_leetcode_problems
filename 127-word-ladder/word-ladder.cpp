class Solution {
public:
    bool diffByOne(string a, string b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ++diff;
                if (diff > 1) return false;
            }
        }
        return diff == 1;
    }

    vector<int> dijkstra(int n, const vector<vector<int>>& adj, int src) { 
        vector<int> dist(n, INT_MAX); 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        dist[src] = 0; 
        pq.push({0, src}); 
        while (!pq.empty()) { 
            auto [d, u] = pq.top(); pq.pop(); 
            if (d != dist[u]) continue; 
            for (int v : adj[u]) { 
                int w = 1; 
                if (dist[v] > d + w) { 
                    dist[v] = d + w; 
                    pq.push({dist[v], v}); 
                } 
            } 
        } 
        return dist; 
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        
        vector<vector<int>> adj(n + 1);
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // Node 0: beginWord
        for (int i = 0; i < n; ++i) {
            if (diffByOne(beginWord, wordList[i])) {
                adj[0].push_back(i + 1);
                adj[i + 1].push_back(0);
            }
        }
        
        // Nodes 1 to n: wordList
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {  // Avoid self-loops/duplicates
                if (diffByOne(wordList[i], wordList[j])) {
                    adj[i + 1].push_back(j + 1);
                    adj[j + 1].push_back(i + 1);
                }
            }
        }
        
        vector<int> dist = dijkstra(n + 1, adj, 0);
        int endIdx = -1;
        for (int i = 0; i < n; ++i) {
            if (wordList[i] == endWord) {
                endIdx = i + 1;
                break;
            }
        }
        int steps = dist[endIdx];
        return (steps == INT_MAX) ? 0 : steps + 1;
    }
};
