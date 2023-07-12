# notice the difference btw implementation of list and bst 
# in list we had extra class Node, but here we dont teh reason is trees involve recursion to solve them
# so one class req

class BinarySearchTree:
    def __init__(self, data = 0, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right
     
    # inorder traversal of bst gives sorted list, postorder gives descending order
    def print_tree(self):
        if self is None: return
        if self.left:
            self.left.print_tree()
        print(self.data, end = " ")
        if self.right:
            self.right.print_tree()
    
    # o(log(n)) or O(h)
    def search(self, data):
        if self is None: return
        if self.data == data:
            print("found")
            return
        if self.data > data:
            if self.left:
                return self.left.search(data)
            else:
                print("not found")
                return
        if self.data < data:
            if self.right:
                return self.right.search(data) # notice how the function call use return here
            else:
                print("not found")
                return

    # o(log(n)) insert a tree node
    def add_child(self, data):
        if self is None: self = BinarySearchTree(data)
        if self.data == data: # cant have same data values
           return
        if self.data > data:
            if self.left: 
                self.left.add_child(data)
            else:
                self.left = BinarySearchTree(data)
        else:
            if self.right: 
                self.right.add_child(data)
            else:
                self.right = BinarySearchTree(data)
    def deleteNode(self, data):
        if self is None: return None
        if self.data == data:
            #1 
            left = self.left
            right = self.right
            if left is None and right is None:
                return None
            #2
            if left and right is None:
                return left
            if left is None and right:
                return right
            #3 replace the root node with the min value found in the right subtree
            # go right to reach the right subtree
            cur = right
            # find min 
            while cur.left:
                cur = cur.left
            # cur now has the value of min. replace val of root with this
            self.data = cur.data
            # delete cur.data from root.right
            self.right = self.right.deleteNode(self.data)
            return self
        
        if self.data > data:
            if self.left:
                self.left = self.left.deleteNode(data)
            else:
                return self
        elif self.data < data:
            if self.right:
                self.right = self.right.deleteNode(data)
            else:
                return self
def build_tree(elements):
    print("Building tree with these elements:",elements)
    root = BinarySearchTree(elements[0])

    for i in range(1,len(elements)):
        root.add_child(elements[i])

    return root

if __name__ == "__main__":
    root = build_tree([1,2,3,4,5,6,7,8,9,9,10])
    root = build_tree([17, 4, 1, 20, 9, 23, 18, 34])
    root.print_tree()
    root.search(210)
    root.print_tree()
    print()
    root.deleteNode(4)
    root.deleteNode(9)
    root.print_tree()