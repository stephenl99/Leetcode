class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        def getParent(i):
            if parents[i] == i:
                return i
            realParent = getParent(parents[i])
            return realParent
        mapping = {}
        parents = list(range(len(accounts)))
        answer = []
        sets = [set() for _ in range(len(accounts))]
        for i in range(len(accounts)):
            account = accounts[i]
            for j in range(1, len(account)):
                if account[j] in mapping:
                    parentI = getParent(i)
                    parentOther = getParent(mapping[account[j]])
                    parents[parentI] = parentOther
                else:
                    mapping[account[j]] = i
                sets[i].add(account[j])
        for i in range(len(accounts)):
            account = accounts[i]
            parentA = getParent(i)
            if parentA != i:
                for j in range(1, len(account)):
                    if not account[j] in sets[parentA]:
                        sets[parentA].add(account[j])
        for i in range(len(accounts)):
            account = accounts[i]
            parentA = getParent(i)
            if parentA == i:
                answerToAdd = [account[0]]
                answerToAdd = answerToAdd + sorted(sets[i])
                answer.append(answerToAdd)
        return answer

