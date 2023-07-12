class TreeNode:
    def __init__(self, data = 0):
        self.data = data
        self.children = []
        self.parent_node = None
    
    def level(self):
        p = self.parent_node
        cnt = 0
        while p:
            cnt+=1
            p = p.parent_node
        return cnt
    
    def add_child(self, child):
        child.parent_node = self
        self.children.append(child)
    
    def print_tree(self):
        if self is None: return
        print(end = "\t" * self.level())
        print(self.data)
        # print(end = "\t") # doing this doesnt work, we need to know level of the node for proper formatting
        for child in self.children:
            child.print_tree()
    
def build_product_tree():
    root = TreeNode("Electronics")

    laptop = TreeNode("Laptop")
    laptop.add_child(TreeNode("Mac"))
    laptop.add_child(TreeNode("Surface"))
    laptop.add_child(TreeNode("Thinkpad"))

    cellphone = TreeNode("Cell Phone")
    cellphone.add_child(TreeNode("iPhone"))
    cellphone.add_child(TreeNode("Google Pixel"))
    cellphone.add_child(TreeNode("Vivo"))

    tv = TreeNode("TV")
    tv.add_child(TreeNode("Samsung"))
    tv.add_child(TreeNode("LG"))

    root.add_child(laptop)
    root.add_child(cellphone)
    root.add_child(tv)
    return root

if __name__ == '__main__':
    
    # root = TreeNode("a")
    # child = TreeNode("aa")
    # root.add_child(child)
    # print(root.children[0].data)

    root = build_product_tree()
    root.print_tree()