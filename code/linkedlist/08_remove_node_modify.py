
def deleteNode(self, node):
    
    # here in the question it is mentioned that given node is never a tail node, what if it wa tail?
    # just add this condition, this makes the tail node = None 
    if node.next is None: node = None

    # node argument is by value not by reference so this doesnt work
    # node = node.next
    # changes have to made to node variable as nothing is returned
    
    """
    node is point to an element in that list, we use node = node.next, just like         
    reasignment, the original list doesn't change. But when we use node.val = node.next.val...   ,
    we actually modify the element in the list.
    """
    node.val = node.next.val
    node.next = node.next.next

    
