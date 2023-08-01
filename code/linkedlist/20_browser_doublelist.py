# multiple solutions exist for this even array / 2 stacks can be used.
class Node:
    def __init__(self, url = ""):
        self.url = url
        self.next = None
        self.prev = None
class BrowserHistory:

    def __init__(self, homepage: str):
        self.head = Node(homepage)
        self.tail = self.head
        self.cur = self.head
       
    # o(1) basically adding a new node.
    # new visit node becomes the new tail of list.
    def visit(self, url: str) -> None:
        # as constructor gives a homepage this is not required.
        if self.head is None: 
            self.head = Node(url)
            self.tail = self.head
            self.cur = self.head

        else:
            node = Node(url)
            self.cur.next = node
            node.prev = self.cur
            self.tail = node
            self.cur = node
    
    # o(n) 
    def back(self, steps: int) -> str:
        while self.head != self.cur and steps:
            self.cur = self.cur.prev
            steps = steps-1 
        return self.cur.url
            
        
    # o(n)
    def forward(self, steps: int) -> str:
        while self.tail != self.cur and steps:
            self.cur = self.cur.next
            steps = steps-1 
        return self.cur.url

        


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)