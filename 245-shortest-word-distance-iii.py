class Solution:
    def shortestWordDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        if word1 == word2:
            last = -1
            minn = math.inf
            for i in range(len(wordsDict)):
                word = wordsDict[i]
                if word == word1:
                    if last == -1:
                        last = i
                        continue
                    minn = min(minn, i - last)
                    last = i
            return minn
        last1 = -1
        last2 = -1
        minn = math.inf
        for i in range(len(wordsDict)):
            word = wordsDict[i]
            if word == word1:
                if last2 == -1:
                    last1 = i
                    continue
                minn = min(minn, i - last2)
                last1 = i
            elif word == word2:
                if last1 == -1:
                    last2 = i
                    continue
                minn = min(minn, i - last1)
                last2 = i
        return minn