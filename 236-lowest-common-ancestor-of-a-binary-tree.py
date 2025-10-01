# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def helper(self, curr, p, q):
        if curr == None:
            return 0
        left = self.helper(curr.left, p, q)
        right = self.helper(curr.right, p, q)
        if left == 2 or right == 2:
            return 2
        elif (left == 1 and right == 1) or (left == 1 and (curr.val == p.val or curr.val == q.val) or (right == 1 and (curr.val == p.val or curr.val == q.val))):
            self.answer = curr
            return 2
        elif left == 1 or right == 1 or curr.val == p.val or curr.val == q.val:
            return 1
        else:
            return 0
        
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.answer = TreeNode(-1)
        self.helper(root, p, q)
        return self.answer
        

        