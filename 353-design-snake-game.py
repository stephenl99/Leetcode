class SnakeGame(object):

    def __init__(self, width, height, food):
        """
        :type width: int
        :type height: int
        :type food: List[List[int]]
        """
        self.head = (0, 0)
        self.length = 1
        self.food = deque(food)
        self.height = height
        self.width= width
        self.snakeLocsDeque = deque()
        self.snakeLocsDeque.append((0, 0))
        self.snakeLocsSet = set()
        self.snakeLocsSet.add((0, 0))
    def move(self, direction):
        """
        :type direction: str
        :rtype: int
        """
        def getPos(head, direction):
            if direction == "U":
                return (head[0] - 1, head[1])
            elif direction == "D":
                return (head[0] + 1, head[1])
            elif direction == "L":
                return (head[0], head[1] - 1)
            elif direction == "R":
                return (head[0], head[1] + 1)
        def OOB(nextPos):
            if nextPos[0] < 0 or nextPos[0] >= self.height or nextPos[1] < 0 or nextPos[1] >= self.width:
                return True
            return False
        nextPos = getPos(self.head, direction)
        if len(self.food) > 0 and nextPos == tuple(self.food[0]):
            self.length += 1
            self.food.popleft()
            if nextPos in self.snakeLocsSet:
                return -1
        else:
            if OOB(nextPos):
                return -1
            tail = self.snakeLocsDeque[-1]
            self.snakeLocsDeque.pop()
            self.snakeLocsSet.remove(tail)
            if nextPos in self.snakeLocsSet:
                return -1
        self.snakeLocsSet.add(nextPos)
        self.snakeLocsDeque.appendleft(nextPos)
        self.head = nextPos
        return self.length - 1


# Your SnakeGame object will be instantiated and called as such:
# obj = SnakeGame(width, height, food)
# param_1 = obj.move(direction)