class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        mint = 1440
        timeSet = set()
        for time in timePoints:
            hours = int(time[:2])
            mins = int(time[-2:])
            realTime = hours * 60 + mins
            if realTime in timeSet:
                return 0
            timeSet.add(realTime)
        prev = -1
        firstTime = -1
        times = sorted(timeSet)
        for time in times:
            if not prev == -1 and time - prev < mint:
                mint = time - prev
            if prev == -1:
                firstTime = time
            prev = time
        if firstTime != -1:
            finalTime = firstTime + (1440 - prev)
            mint = min(finalTime, mint)
        return mint
        

