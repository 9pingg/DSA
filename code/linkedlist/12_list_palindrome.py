# this is the first question which uses preivious questions to get to the final result
# here find out if linked list is palindrome
# how to do ?

# find middle of list and then break the list from the middle
# then reverse the second part of the list.

# after reversing compare the two 

def isPalindrome(self, head: Optional[ListNode]) -> bool:
    # step 1 find middle node
    
    # there is difference btw the middle node question here
    # in the middle node question we give right most middle node
    # here we give the left most middle node
    # head = [1,2,2,1]
    
    f = head
    s = head

    while f.next and f.next.next:
        f = f.next.next
        s = s.next
    # s = [2,2,1]
    # rev = [2,1]
    rev = s.next

    # step 2 find reverse of part 2 of list
    prev = None
    cur = rev

    while cur:
        temp = cur.next
        cur.next = prev
        prev = cur
        cur = temp
    
    # prev point the reversed linked list
    # prev [1,2]

    # compare the two lists
    while head and prev:
        if(head.val != prev.val): return False
        head = head.next
        prev = prev.next
        
    return True