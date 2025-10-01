class Encrypter(object):
    def __init__(self, keys, values, dictionary):
        """
        :type keys: List[str]
        :type values: List[str]
        :type dictionary: List[str]
        """
        self.keys = keys
        self.keyMap = {}
        self.keys = []
        self.valMap = defaultdict(list)
        self.values = []
        self.dictionary = defaultdict(int)
        for i in range(len(keys)):
            self.keyMap[keys[i]] = i
        self.values = values
        for i in range(len(values)):
            self.valMap[values[i]].append(i)
        for word in dictionary:
            wo = self.encrypt(word)
            self.dictionary[wo] += 1
    def encrypt(self, word1):
        """
        :type word1: str
        :rtype: str
        """
        word2 = ""
        for i in range(len(word1)):
            if word1[i] not in self.keyMap:
                return ""
            word2 += self.values[self.keyMap[word1[i]]]
        return word2
    def decrypt(self, word2):
        """
        :type word2: str
        :rtype: int
        """
        return self.dictionary[word2]


# Your Encrypter object will be instantiated and called as such:
# obj = Encrypter(keys, values, dictionary)
# param_1 = obj.encrypt(word1)
# param_2 = obj.decrypt(word2)