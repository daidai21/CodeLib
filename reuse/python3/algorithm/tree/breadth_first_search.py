class BinaryTreeNode(object):
    def __init__(self, val):
        self.left = None
        self.right = None
        self.val = val


# Returns nodes with equal values
def breadth_first_search(root, target):
    if root is None:
        return 
    que = [root]
    while que:
        nxt_que = []
        for node in que:
            if node.val == target:
                return node
            if node.left is not None:
                nxt_que.append(node.left)
            if node.right is not None:
                nxt_que.append(node.right)
        que = nxt_que
