class Solution:
    answer = []
    def letterCombinations(self, digits: str) -> List[str]:
        self.answer = []
        if len(digits) == 0:
            return []
        self.helper(digits, "")
        return self.answer
    def helper(self, digits, wordSoFar):
        if len(digits) == 1:
            letters = self.getLetters(digits[0])
            for letter in letters:
                self.answer.append(wordSoFar + letter)
            return
        num = digits[0]
        newDigits = digits[1:]
        for letter in self.getLetters(num):
            self.helper(newDigits, wordSoFar + letter)
    def getLetters(self, digit):
        if digit == "2":
            return {'a', 'b', 'c'}
        if digit == "3":
            return {'d', 'e', 'f'}
        if digit == "4":
            return {'g', 'h', 'i'}
        if digit == "5":
            return {'j', 'k', 'l'}
        if digit == "6":
            return {'m', 'n', 'o'}
        if digit == "7":
            return {'p', 'q', 'r', 's'}
        if digit == "8":
            return {'t', 'u', 'v'}
        if digit == "9":
            return {'w', 'x', 'y', 'z'}
