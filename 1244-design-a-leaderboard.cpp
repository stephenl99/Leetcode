/**

player_id -> score
priority queue based on scores + access using player id

Score struct:
- score
- player id


**/

class Leaderboard {
public:
    Leaderboard() {}
    
    void addScore(int playerId, int score) {
        auto it = scores.find(playerId);
        if (it != scores.end()) {
            int before = it->second;
            auto b_it = score_board.find(before);
            if (b_it->second == 1) score_board.erase(b_it);
            else --b_it->second;
            scores[playerId] = score + before;
            ++score_board[score + before];
        } else {
            scores[playerId] = score;
            ++score_board[score];
        }
    }
    
    int top(int K) {
        int result = 0;
        for (auto it = score_board.rbegin(); it != score_board.rend(); ++it) {
            if (it->second < K) {
                result += it->second * it->first;
                K -= it->second; 
            } else {
                result += K * it->first;
                break;
            }
        }
        return result;
    }
    
    void reset(int playerId) {
        auto it = scores.find(playerId);
        int before = it->second;
        scores.erase(it);
        auto b_it = score_board.find(before);
        if (b_it->second == 1) score_board.erase(b_it);
        else --b_it->second;
    }

private:
    unordered_map<int, int> scores;
    map<int, int> score_board;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */