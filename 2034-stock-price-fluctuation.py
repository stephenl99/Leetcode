class StockPrice(object):

    def __init__(self):
        self.mapping = {}
        self.latestTime = -1
        self.minHeap = []
        self.maxHeap = []

    def update(self, timestamp, price):
        """
        :type timestamp: int
        :type price: int
        :rtype: None
        """
        self.mapping[timestamp] = price
        heapq.heappush(self.minHeap, (price, timestamp))
        heapq.heappush(self.maxHeap, (-price, timestamp))
        self.latestTime = max(self.latestTime, timestamp)


    def current(self):
        """
        :rtype: int
        """
        return self.mapping[self.latestTime]

    def maximum(self):
        """
        :rtype: int
        """
        while self.mapping[self.maxHeap[0][1]] != -self.maxHeap[0][0]:
            heapq.heappop(self.maxHeap)
        return -self.maxHeap[0][0]

    def minimum(self):
        """
        :rtype: int
        """
        while self.mapping[self.minHeap[0][1]] != self.minHeap[0][0]:
            heapq.heappop(self.minHeap)
        return self.minHeap[0][0]


# Your StockPrice object will be instantiated and called as such:
# obj = StockPrice()
# obj.update(timestamp,price)
# param_2 = obj.current()
# param_3 = obj.maximum()
# param_4 = obj.minimum()