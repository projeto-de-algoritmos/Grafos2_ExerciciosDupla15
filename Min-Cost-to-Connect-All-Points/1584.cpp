class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        vector<bool> visited(points.size(), false);
        vector<int> dist(points.size(), INT_MAX);
        int result = 0;     // distancia total da MST
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
            // min_heap.first = custo do vértice atual até um vizinho u
            // min_heap.second = indice de u

        min_heap.push({0, 0});
        dist[0] = 0;

        while (not min_heap.empty()) {          // Prim
            int u = min_heap.top().second;
            min_heap.pop();     
            if (visited[u]) continue;
            visited[u] = true;
            result += dist[u];          
            for (size_t v = 0; v < points.size(); v++) {    // visitar vizinhos e ver o de menor custo
                if (not visited[v]) {
                    int cost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (cost < dist[v]) {
                        dist[v] = cost;
                        min_heap.push({dist[v], v});
                    }
                }
            }
        }
        
        return result;
    }
};
