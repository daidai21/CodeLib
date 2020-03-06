class BinaryTreeNode(object):
    def __init__(self, val):
        self.left = None
        self.right = None
        self.val = val


# Returns nodes with equal values
def depth_first_search(root, target):
    if root is None:
        return 
    if root.val == target:
        return root
    if root.left is not None:
        depth_first_search(root.left, target)
    if root.right is not None:
        depth_first_search(root.right, target)
