class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        fromTo = defaultdict(list)
        answer = []
        indegree = [0] * numCourses
        for prereq in prerequisites:
            fromTo[prereq[0]].append(prereq[1])
            indegree[prereq[1]] += 1
        q = deque()
        for i in range(len(indegree)):
            if indegree[i] == 0:
                q.append(i)
        while q:
            front = q.popleft()
            answer.append(front)
            for dest in fromTo[front]:
                indegree[dest] -= 1
                if indegree[dest] == 0:
                    q.append(dest)
        if len(answer) < numCourses:
            return []
        answer.reverse()
        return answer

        

        