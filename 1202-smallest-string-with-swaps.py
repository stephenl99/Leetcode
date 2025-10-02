class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        def getParent(index):
            if parents[index] == index:
                return index
            return getParent(parents[index])
        parents = [_ for _ in range(len(s))]
        qs = defaultdict(list)
        for pair in pairs:
            parent1 = getParent(pair[0])
            parent2 = getParent(pair[1])
            if parent1 < parent2:
                parents[parent2] = parent1
            else:
                parents[parent1] = parent2
        for i in range(len(s)):
            heapq.heappush(qs[getParent(i)], s[i])
        answer = ""
        for i in range(len(s)):
            answer += heapq.heappop(qs[getParent(i)])
        return answer
