class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        k= len(words[0])
        n= k * len(words)
        answer = []
        currMapping = defaultdict(int)
        setOfWords = defaultdict(int)
        count = 0
        for word in words:
            setOfWords[word] += 1
        for index in range(k):
            currMapping = defaultdict(int)
            count = 0
            for i in range(index, len(s) - k + 1, k):
                nextWord = s[i: i + k]
                if nextWord in setOfWords:
                    currMapping[nextWord] += 1
                    if currMapping[nextWord] <= setOfWords[nextWord]:
                        count += 1
                if i >= n:
                    wordToRemove = s[i - n : i - n + k]
                    if wordToRemove in setOfWords:
                        currMapping[wordToRemove] -= 1
                        if currMapping[wordToRemove] < setOfWords[wordToRemove]:
                            count -= 1
                if count == len(words):
                    answer.append(i - n + k)
        return answer


