class TimeMap(object):

    def __init__(self):
        self.mapping = defaultdict(list)

    def set(self, key, value, timestamp):
        """
        :type key: str
        :type value: str
        :type timestamp: int
        :rtype: None
        """
        self.mapping[key].append((timestamp, value))
    def get(self, key, timestamp):
        """
        :type key: str
        :type timestamp: int
        :rtype: str
        """
        if not key in self.mapping or len(self.mapping[key]) == 0:
            return ""
        stampList = self.mapping[key]
        left = 0
        right = len(stampList) - 1
        while left < right:
            mid = int((left + right) / 2)
            if stampList[mid][0] == timestamp:
                return stampList[mid][1]
            elif stampList[mid][0] < timestamp:
                if mid != len(stampList) - 1 and stampList[mid + 1][0] > timestamp:
                    return stampList[mid][1]
                left = mid + 1 
            else:
                right = mid - 1
        if left == 0 and stampList[left][0] > timestamp:
            return ""
        return stampList[left][1]



# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)