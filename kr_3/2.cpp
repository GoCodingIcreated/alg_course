#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<char> > field;
std::vector<std::vector<int> > moves;
std::queue<std::pair<int, int> > que;
std::vector<int> dx {0, 0, 1, -1};
std::vector<int> dy {1, -1, 0, 0};
int main() {
    int n, m;
    std::cin >> n >> m;
    field.assign(n, std::vector<char>(m, 0));
    moves.assign(n, std::vector<int>(m, -1));
    int start_x = -1, start_y = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> field[i][j];
            if (field[i][j] == '@') {
                start_x = i;
                start_y = j;
            }
        }
    }
    que.push(std::make_pair(start_x, start_y));
    moves[start_x][start_y] = 0;
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m) {
                continue;
            }
            if (moves[x][y] == -1 && (field[x][y] == '.' || field[x][y] == '#')) {
                moves[x][y] = moves[p.first][p.second] + 1;
                que.push(std::make_pair(x, y));
            }
            if (field[x][y] == '#') {
                std::cout << moves[x][y] << std::endl;
                return 0;
            }
        }
    }
}
