class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        monoStack = deque()
        answer = [0] * len(temperatures)
        for i in range(len(temperatures) - 1, -1, -1):
            while not len(monoStack) == 0 and temperatures[monoStack[-1]] <= temperatures[i]:
                monoStack.pop()
            if monoStack:
                answer[i] = monoStack[-1] - i
            monoStack.append(i)
        return answer
