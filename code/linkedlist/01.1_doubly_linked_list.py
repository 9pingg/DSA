class Node:
    def __init__(self, data, prev = None ,next = None):
        self.data = data
        self.prev = prev
        self.next = next

class DLL:
    def __init__(self):
        self.head = None
        self.end = None

    def add_start(self, data):
        if self.head is None:
            self.head = Node(data)
            self.end = self.head
            return
        node = Node(data)
        self.head.prev = node
        node.next = self.head
        self.head = node

    def add_back(self, data):
        if self.end is None:
            self.head = Node(data)
            self.end = self.head
            return
        node = Node(data)
        self.end.next = node
        node.prev = self.end
        self.end = node
    def print_next(self):
        cur = self.head
        while cur:
            print(cur.data, end = " ")
            cur = cur.next
        print()

    def print_prev(self):
        cur = self.end

        while cur:
            print(cur.data, end = " ")
            cur = cur.prev
        print()

    def delete(self, data): # delete all nodes with values eq to data
        """
        in dl we do not need to stop one node before the node is to be deleted as we have prev
        so no need of cur.next is in loop.
        """
        if self.head is None: 
            print("empty list")
            return
        # deletion of an head node and end node is diferent as both these varaibles have to be moved
        if self.head.data == data:

            self.head = self.head.next
            self.head.prev = None
            return

        if self.end.data == data:
            self.end = self.end.prev
            self.end.next = None
            return

        cur = self.head 
        back = self.end
        while cur or back:
            if cur and cur.data == data:    
                cur.prev.next = cur.next
                cur.next.prev = cur.prev       
                return
            if back and back.data == data:
                back.prev.next = back.next
                back.next.prev = back.prev       
                return
            if cur:
                cur = cur.next
            if back:
                back = back.prev
                
if __name__ == "__main__":
    dl = DLL()
    dl.add_start(1)
    dl.add_start(2)
    dl.add_start(3)
    dl.add_start(4)
    dl.add_start(5)
    dl.add_back(9)
    dl.delete(3)
    dl.print_next()
    dl.print_prev()