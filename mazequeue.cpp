#include <iostream>
#include <queue>
using namespace std;

class Position {
public:
    Position(int rowVal, int colVal) : m_row(rowVal), m_col(colVal) {}
    int row() const { return m_row; }
    int col() const { return m_col; }
private:
    int m_row;
    int m_col;
};

bool pathExistsQueue(char maze[][10], int sr, int sc, int er, int ec) {
    queue<Position> q;
    q.push(Position(sr, sc));
    maze[sr][sc] = '+';

    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0, -1 };
    int count = 0;

    while (!q.empty()) {
        Position p = q.front();
        q.pop();

        if (count < 12)
            cout << "(" << p.row() << "," << p.col() << ") ";
        count++;

        if (p.row() == er && p.col() == ec) {
            cout << endl;
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int r = p.row() + dr[i];
            int c = p.col() + dc[i];

            if (r >= 0 && r < 10 && c >= 0 && c < 10 && maze[r][c] == '.') {
                q.push(Position(r, c));
                maze[r][c] = '+';
            }
        }
    }
    cout << endl;
    return false;
}

int main() {
    char maze[10][10] = {
        {'X','X','X','X','X','X','X','X','X','X'},
        {'X','.','.','.','.','.','.','.','.','X'},
        {'X','X','.','X','.','X','X','X','X','X'},
        {'X','.','.','X','.','X','.','.','.','X'},
        {'X','.','.','X','.','.','.','X','.','X'},
        {'X','X','X','X','.','X','X','X','.','X'},
        {'X','.','X','.','.','.','.','X','X','X'},
        {'X','.','X','X','X','.','X','X','.','X'},
        {'X','.','.','.','X','.','.','.','.','X'},
        {'X','X','X','X','X','X','X','X','X','X'}
    };

    cout << "BFS first 12 coordinates: ";
    if (pathExistsQueue(maze, 6, 4, 1, 1))
        cout << "Solvable with queue (BFS)!" << endl;
    else
        cout << "Out of luck (BFS)!" << endl;

    return 0;
}
