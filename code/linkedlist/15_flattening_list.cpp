// two ways to flatten a linked list 1) merger two adj list and so on
// 2) put all nodes in priority queue, then pop the elements out and keep adding them

// priority queue method T: O(M*N*log(MN)) and S: O(M*N) 
// but we can further optimize this by only pushing the head node of every linked list into it not the bottom nodes
// after inserting pop element, print it and add node->bottom into the queue if it is not None. do this till every element is printed or queue is empty

// needs a custom cmp
struct cmp {
    bool operator() (Node* a, Node* b){
       if(a->data >= b->data) return true;
        else return false;
    }
};
Node *flatten(Node *root)
{   
    priority_queue<Node*, vector<Node*>, cmp> pq; 
    Node* cur = root;
    while(cur != NULL){
        Node* temp = cur;
        while( temp != NULL){
            // cout << temp->data << endl;
            pq.push(temp);
            temp = temp->bottom;
        }
        cur = cur->next;
    }
    Node* res = NULL;
    cur = res;
    while(!pq.empty()){
        cur = pq.top();
        cout << cur->data << " ";
        pq.pop();
        cur = cur->bottom;
    
    }
    return res;
}

/* Time Complexity: O(N * M * log(N))
where N is the no of nodes in the main linked list (reachable using the next pointer) and M is the no of nodes in a single sub-linked list (reachable using a bottom pointer).
Auxiliary Space: O(N) - where N is the no of nodes in the main linked list (reachable using the next pointer).
*/
Node *Betterflatten(Node *root)
{   
    priority_queue<Node*, vector<Node*>, cmp> pq; 
    Node* cur = root;
    while(cur != NULL){
        pq.push(cur);
        cur = cur->next;
    }
    Node* res = NULL;
    cur = res;
    while(!pq.empty()){
        cur = pq.top();
        cout << cur->data << " ";
        pq.pop();
        cur = cur->bottom;
        if(cur != NULL) pq.push(cur);
    }
    return res;
}


// MERGE ADJ lists python code o(m*n*n)

// Time Complexity: O(N * N * M) - where N is the no of nodes in the main linked list 
// and M is the no of nodes in a single sub-linked list 
// why ?
/*
After adding the first 2 lists, the time taken will be O(M+M) = O(2M).
Then we will merge another list to above merged list -> time = O(2M + M) = O(3M).
Then we will merge another list -> time = O(3M + M).
We will keep merging lists to previously merged lists until all lists are merged.
Total time taken will be O(2M + 3M + 4M + .... N*M) = (2 + 3 + 4 + ... + N) * M
Using arithmetic sum formula: time = O((N * N + N - 2) * M/2)
The above expression is roughly equal to O(N * N * M) for a large value of N
*/


def merge(l1, l2):
    cur = res = Node(1)
    temp = l2.next
    l2.next = None
    l1.next = None
    while l1 and l2:
        if(l1.data <= l2.data):
            cur.bottom = l1
            l1 = l1.bottom
            cur = cur.bottom
        else:
            cur.bottom = l2
            l2 = l2.bottom
            cur = cur.bottom
    if l1 is None:
        cur.bottom = l2
        cur = cur.bottom
    else:
        cur.bottom = l1
        cur = cur.bottom
    res = res.bottom
    res.next = temp 
    return res


def flatten(root):
    cur = root
    while cur.next:
        cur = merge(cur, cur.next)
    return cur

