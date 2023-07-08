
struct cmp{
        bool operator() (ListNode* a, ListNode* b){
            if(a->val >= b->val){
                return true;
            }else{
                return false;
            }
        }
    };
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
    if(lists.size() == 0) return NULL;
    if(lists.size() == 1 && lists[0] == NULL)  return NULL;
    // o(n*log(n)) number of lists
    for (auto i : lists){
        if(i!=NULL) pq.push(i);
    }
    ListNode* res = new ListNode();
    ListNode* cur = res;
    while(!pq.empty()){
        cur->next = pq.top();
        pq.pop();
        cur = cur->next;
        if(cur->next != NULL){
            pq.push(cur->next);
        }
        cur->next = NULL;
    }
    return res->next;
}