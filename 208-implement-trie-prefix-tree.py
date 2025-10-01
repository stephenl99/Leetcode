class Node:
    def __init__(self, value):
        self.value = value
        self.nextValues = [None] * 26
        self.isEnd = False
    def setIsEnd(self):
        self.isEnd = True
class Trie:

    def __init__(self):
        self.head = Node("")

    def insert(self, word: str) -> None:
        currNode = self.head
        for char in word:
            index = string.ascii_lowercase.index(char)
            if not currNode.nextValues[index]:
                currNode.nextValues[index] = Node(currNode.value + char)
            currNode = currNode.nextValues[index]
        currNode.setIsEnd()



    def search(self, word: str) -> bool:
        currNode = self.head
        for char in word:
            index = string.ascii_lowercase.index(char)
            if not currNode.nextValues[index]:
                return False
            currNode = currNode.nextValues[index]
        return currNode.isEnd
    def startsWith(self, prefix: str) -> bool:
        currNode = self.head
        for char in prefix:
            index = string.ascii_lowercase.index(char)
            if not currNode.nextValues[index]:
                return False
            currNode = currNode.nextValues[index]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)