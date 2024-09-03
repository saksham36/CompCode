# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import defaultdict
class Solution(object):
    def findClosestLeaf(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        graph = defaultdict(list)
        self.dfs(graph, root)
        return self.bfs(graph, k)
    
    def dfs(self, graph, root, parent = None):
        if root:
            if parent is None:
                graph[root.val].append(parent)
                graph[parent].append(root.val)
            else:
                graph[root.val].append(parent.val)
                graph[parent.val].append(root.val)
            self.dfs(graph, root.left, root)
            self.dfs(graph, root.right, root)
    
    def bfs(self,graph, k):
        q = []
        for node in graph:
            if node and node == k:
                q.append(node)
        seen = set(q)
        while q:
            node = q.pop(0)
            if node:
                if len(graph[node]) <= 1:
                    return node
                for n in graph[node]:
                    if n not in seen:
                        seen.add(n)
                        q.append(n)