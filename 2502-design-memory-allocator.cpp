class Allocator {
public:
    vector<int> memory;
    unordered_map<int, vector<int>> pointers;
    Allocator(int n) {
        memory.resize(n);
    }
    
    int allocate(int size, int mID) {
        int count = 0;
        int startIndex = -1;
        for (int i = 0; i < memory.size(); i++) {
            if (memory[i] == 0) {
                count++;
                if (count == size) {
                    startIndex = i - size + 1;
                    break;
                }
            } else {
                count = 0;
            }
        }
        if (startIndex == -1) {
            return -1;
        }
        for (int i = startIndex; i < startIndex + size; i++) {
            memory[i] = mID;
        }
        pointers[mID].push_back(startIndex);
        return startIndex;
    }
    
    int freeMemory(int mID) {
        int size = 0;
        for (int address : pointers[mID]) {
            int index = address;
            while (index < memory.size() && memory[index] == mID) {
                memory[index] = 0;
                index++;
                size++;
            }
        }
        return size;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */