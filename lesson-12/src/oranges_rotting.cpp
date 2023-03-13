#include <vector>
#include <cassert>
#include <queue>
#include <iostream>
/*
 * Дана матрица n на m, где каждая ячейка может принимать одно из значений
 *  - 0 представляет пустую ячейку,
 *  - 1 представляет свежий апельсин,
 *  - 2 представляет протухший апельсин.
 * Каждую минуту свежий апельсин, соседствующий (по 4-ём направлениям) с протухшим,
 * становится тоже протухшим.
 * Вернуть минимальное количество минут, через которое все свежие апельсины станут протухшими,
 * или -1, если такое невозможно.
 */
int orangesRotting(std::vector<std::vector<int>>& grid) {
    if (grid.empty()) {
        return 0;
    }
    
    size_t n = grid.size();
    size_t m = grid.back().size();
    
    size_t fresh_oranges_cnt = 0;
    std::queue<std::pair<int, int>> q;
    
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                ++fresh_oranges_cnt;
            }
            if (grid[i][j] == 2) {
                q.push(std::make_pair(i, j));
            }
        }
    }
    
    int result = 0;
    const std::vector<std::vector<int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    while (!q.empty()) {
        
        if (fresh_oranges_cnt == 0)
            break;
        
        size_t layer_cnt = q.size();
        for (size_t i = 0; i < layer_cnt; ++i) {
            auto [x, y] = q.front(); q.pop();
            for (auto direction : directions) {
                int new_x = x + direction[0];
                int new_y = y + direction[1];
                if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) {
                    continue;
                }
                if (grid[new_x][new_y] == 1) {
                    q.push(std::make_pair(new_x, new_y));
                    grid[new_x][new_y] = 2;
                    --fresh_oranges_cnt;
                }
            }
        }
        
        result += 1;
    }
    return fresh_oranges_cnt == 0 ? result : -1;
}

int main()
{
    {
        std::vector<std::vector<int>> grid = { {1, 1}, {2, 1} };
        assert(orangesRotting(grid) == 2);
    }
    {
        std::vector<std::vector<int>> grid = { {2, 1, 1},
                                               {0, 1, 1},
                                               {1, 0, 1} };
        assert(orangesRotting(grid) == -1);
    }
    
    {
        std::vector<std::vector<int>> grid = { {2, 1, 1},
                                               {1, 1, 0},
                                               {0, 1, 1} };
        assert(orangesRotting(grid) == 4);
    }
    
    {
        std::vector<std::vector<int>> grid = {};
        assert(orangesRotting(grid) == 0);
    }
    
    {
        std::vector<std::vector<int>> grid = { {0, 2}, {2, 2} };
        assert(orangesRotting(grid) == 0);
    }
}
