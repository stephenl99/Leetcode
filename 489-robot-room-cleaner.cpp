/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    void cleanRoom(Robot& robot) {
        vector<vector<bool>> grid(210, vector<bool> (410, false));
        int x = 104;
        int y = 204;
        stack<vector<int>> stack;
        bool isFirst = true;
        while (!stack.empty() || isFirst) {
            isFirst = false;
            if (!grid[x][y]) {
                robot.clean();
                grid[x][y] = true;
                stack.push({x, y});
            }
            if (!grid[x][y + 1] && robot.move()) {
                y++;
                continue;
            } 
            if (!grid[x + 1][y]) {
                robot.turnRight();
                if (robot.move()) {
                    x++;
                    robot.turnLeft();
                    continue;
                }
                robot.turnLeft();
            } 
            if (!grid[x - 1][y]) {
                robot.turnLeft();
                if (robot.move()) {
                    x--;
                    robot.turnRight();
                    continue;
                }
                robot.turnRight();
            } 
            if (!grid[x][y - 1]) {
                robot.turnLeft();
                robot.turnLeft();
                if (robot.move()) {
                    y--;
                    robot.turnLeft();
                    robot.turnLeft();
                    continue;
                }
                robot.turnLeft();
                robot.turnLeft();
            }
            vector<int> next = stack.top();
            if (next[0] == x && next[1] == y) {
                stack.pop();
            }
            if (next[0] == x && next[1] == y + 1) {
                robot.move();
                y++;
            } else if (next[0] == x + 1 && next[1] == y) {
                robot.turnRight();
                robot.move();
                robot.turnLeft();
                x++;
            } else if (next[0] == x - 1 && next[1] == y) {
                robot.turnLeft();
                robot.move();
                robot.turnRight();
                x--;
            } else if (next[0] == x && next[1] == y - 1) {
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
                y--;
            }
        }
    }
};