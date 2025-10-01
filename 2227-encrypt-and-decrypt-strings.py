class Encrypter:

    def __init__(self, keys: List[str], values: List[str], dictionary: List[str]):
        self.charToCodeMapping = {}
        for i in range(len(keys)):
            self.charToCodeMapping[keys[i]] = values[i]
        self.encryptedPossible = defaultdict(int)
        for word in dictionary:
            self.encryptedPossible[self.encrypt(word)] += 1


    def encrypt(self, word1: str) -> str:
        finalString = ""
        for char in word1:
            if char not in self.charToCodeMapping:
                return ""
            finalString += self.charToCodeMapping[char]
        return finalString



    def decrypt(self, word2: str) -> int:
        return self.encryptedPossible[word2]
        


# Your Encrypter object will be instantiated and called as such:
# obj = Encrypter(keys, values, dictionary)
# param_1 = obj.encrypt(word1)
# param_2 = obj.decrypt(word2)