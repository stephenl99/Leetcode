class Solution:
    def addBinary(self, a: str, b: str) -> str:
        answer = ""
        index = 0
        isCarried = False
        while index < max(len(a), len(b)):
            aVal = 0
            bVal = 0
            if len(a) - 1 - index >= 0:
                aVal = int(a[len(a) - 1 - index])
            if len(b) - 1 - index >= 0:
                bVal = int(b[len(b) - 1 - index])
            if aVal + bVal == 2:
                if isCarried:
                    answer = '1' + answer
                else:
                    answer = '0' + answer
                    isCarried = True
            elif aVal + bVal == 1:
                if isCarried:
                    answer = '0' + answer
                else:
                    answer = '1' + answer
                    isCarried = False
            else:
                if isCarried:
                    answer = '1' + answer
                else:
                    answer = '0' + answer
                isCarried = False
            index += 1
        if isCarried:
            answer = '1' + answer
        return answer
