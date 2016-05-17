#include <iostream>
#include <vector>

std::vector<std::vector<int> > graph;
std::vector<int> used;

bool dfs(int v, int color) {
    used[v] = color;
    for (size_t i = 0; i < graph[v].size(); ++i) {
        int u = graph[v][i];
        if (used[u] == 0) {
            bool is_good = dfs(u, color % 2 + 1);
            if (!is_good) {
                return false;
            }
        }
        else {
            if (used[u] == color) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    graph.resize(n);
    used.assign(n, 0);
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bool is_good = true;
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            is_good = is_good && dfs(i, 1);
            if (!is_good) {
                break;
            }
        }
    }
    if (is_good) {
        std::cout << "YES\n";
    }
    else {
        std::cout << "NO\n";
    }
}
