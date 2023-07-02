def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
    # return None
    # brute force O(N*M) for every node of A check every node of b 
    while headA:
        temp = headB
        while temp:
            if(temp == headA): return temp
            temp = temp.next
        headA = headA.next
    return None

# better approach uses hashing store address of all nodes in a map and check if other linked list has them
# T o(n) + o(m) S: O(n)
def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
    if(headA is None or headB is None): return None
    m = {} # declare a map
    while headA:        
        m[headA] = 1 # store node in the map
        headA = headA.next
    while headB:
        if(headB in m): return headB # if node exists in map then return that node
        headB = headB.next
    return None

# optimal approach 
# take two pointers l1 and l2 which start at head of both the list move them one by one
# move them till of them goes to null.
# if l1 becomes none then set it to l1 = head2
# if l2 becomes none then set it to l2 = head1
# keep iterating eventually they both would align themselves and move together and point the intersect node

def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
    if(headA is None or headB is None): return None
    h_a = headA
    h_b = headB
    cnt = 0
    # to ways to get out of the loop if both are equal or both become eq to None (only achievable when both pointers are aligned)
    # which is done after these statements if(headA is None): headA = h_b if(headB is None): headB = h_a
    while headA and headB:
        if(headA == headB): 
            return headA
    
        headA = headA.next
        headB = headB.next

        if(headA is None and headB is None): return None      
        if(headA is None): 
            headA = h_b
        if(headB is None): 
            headB = h_a
        
    return None
