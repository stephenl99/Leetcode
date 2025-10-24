class Pair {
    public:
    int val;
    int playerId;
    Pair(int val, int playerId) {
        this->val = val;
        this->playerId = playerId;
    }
    bool operator<(const Pair& other) const {
        return this->val < other.val;
    }
};
class Leaderboard {
public:
    priority_queue<Pair> pq;
    unordered_map<int, int> mapp;
    Leaderboard() {

    }
    
    void addScore(int playerId, int score) {
        if (!mapp.contains(playerId)) {
            mapp[playerId] = 0;
        }
        mapp[playerId] += score;
        pq.push(Pair(mapp[playerId], playerId));
    }
    
    int top(int K) {
        return compute(pq, mapp, K);
    }

    int compute(priority_queue<Pair> pq, unordered_map<int, int>& map, int k) {
        int count = 0;
        int total = 0;
        unordered_set<int> seen;
        while (count < k) {
            Pair pair = pq.top();
            pq.pop();
            if (!seen.contains(pair.playerId) && mapp[pair.playerId] == pair.val) {
                count++;
                total += pair.val;
                seen.insert(pair.playerId);
            }
        }
        return total;
    }
    
    void reset(int playerId) {
        mapp[playerId] = 0;
        pq.push(Pair(0, playerId));
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */