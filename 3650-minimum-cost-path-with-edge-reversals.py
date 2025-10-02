class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        edgeSets = defaultdict(list)
        for edge in edges:
            edgeSets[edge[0]].append((edge[1], edge[2]))
            edgeSets[edge[1]].append((edge[0], edge[2] * 2))
        distance = [math.inf] * n
        distance[0] = 0
        pq = []
        heapq.heappush(pq, (0, 0))
        while pq:
            top = heapq.heappop(pq)
            distance[top[1]] = top[0]
            if top[1] == n - 1:
                return top[0]
            for edge in edgeSets[top[1]]:
                if top[0] + edge[1] < distance[edge[0]]:
                    distance[edge[0]] = top[0] + edge[1]
                    heapq.heappush(pq, (top[0] + edge[1], edge[0]))
        return -1
