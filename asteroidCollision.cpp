class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> answer;
        deque<int> stack;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] < 0) {
                bool wasEqual = false;
                while (!stack.empty() && -1 * asteroids[i] >= stack.back()) {
                    if (-1 * asteroids[i] == stack.back()) {
                        wasEqual = true;
                        stack.pop_back();
                        break;
                    } else {
                        stack.pop_back();
                    }
                }
                if (stack.empty() && !wasEqual) {
                    answer.push_back(asteroids[i]);
                }
            } else {
                stack.push_back(asteroids[i]);
            }
        }
        while (!stack.empty()) {
            answer.push_back(stack.front());
            stack.pop_front();
        }
        return answer;
    }
};