# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Pair:
    def __init__(self, node, index):
        self.node = node
        self.index = index
    def __lt__(self, other):
        return self.node.val < other.node.val
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        answer = ListNode(0)
        head = answer
        heap = []
        for i in range(len(lists)):
            if lists[i] is not None:
                heapq.heappush(heap, Pair(lists[i], i))
        while heap:
            pair = heapq.heappop(heap)
            answer.next = ListNode(pair.node.val)
            answer = answer.next
            if pair.node.next is not None:
                heapq.heappush(heap, Pair(pair.node.next, i))
        return head.next
