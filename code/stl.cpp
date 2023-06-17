#include <bits/stdc++.h>
// NAMESPACE STD DEFINED IN IOSTREAM
using namespace std;
#define int long long

/*
Now when cout<<“GeeksforGeeks”; is written, the compiler searches for cout in our program which is kept 
in the std namespace, so the instruction given to the compiler that if the compiler doesn’t find anything 
in the current scope, try finding it in the std namespace.
*/

/* 
there are namespaces in c++ baiscally used to define varaibles with same name or functions in 
different namepaces. As in the above code variable x and method fun() were limited to namespaces n1 and n2. 
Thus, their scope was not outside the n1 or n2. Every time using the scope resolution operator (::) in a 
variable or a function defined is not required, it can be solved with “using” directive.
*/

// instead of resolution operator we can also use
namespace n1{
    void func(){
        cout << "func" << endl;
    }
}
// using namespace n1;
void printUnorderedSet(unordered_set<int> &s){
	cout << "size: " << s.size() << endl;
	for(auto it: s){
		cout << it << endl;
	}
}
void printSet(multiset<string> &s){
	cout << "size: " << s.size() << endl;
	for(auto it: s){
		cout << it << endl;
	}
}
void printMap(unordered_map<int , string> &m){
	 // O(N)
	for(auto it : m){
		cout << it.first << " " << it.second << endl;		
	}
	cout << "asakgdjhas";
}
void using_pairs(){
     // pairs 
    pair<int,string> p = {1, "h"};
    p.first = 1;
    p.second = "hello";
    cout << p.first << " " << p.second << endl;
    pair<int, map<int, string> > p1; // this can also be done 
    pair<int, vector<int> > p2;
    pair<int, int > p_arr[100]; // array of pairs
}

void using_vectors(){
    // dynamic in nature always inc in size, arrays are defined only of fixed size
    //Vector is a type of sequential container like array and dequeue.  A vector stores elements in contiguous memory locations.
    vector<int> v = {1,2,3,4,5,6,7,8,9}; // creates an empty container
    // v.emplace_back(2);
    vector<pair<int,int> > v_p;
    // v_p.push_back({1,2});
    // v_p.emplace_back(1,2);
    
    const int SIZE = 10;
    const int DEFAULT_VAL = 100;
    vector<int> v1 (SIZE, DEFAULT_VAL);

    // copy one vector to another
    vector<int> v2(v1); // copies v1 to v2 O(N)

    vector<int>::iterator it = v.begin(); // points to the mem where first element of vector is stored.
    vector<int>::iterator it_e = v.end();// points to the end + 1 position of teh vector, where end is the last element
    cout << *(it) << endl; // to print the value of the memory
    it += 2; // shifts to 2 places ahead

    cout << v.front() << endl;
    for(auto val : v){ // auto it detect type by itself vector<int>::iterator
        cout << val << " ";
    }

    // to delete elements from vector we use erase O(N)
    v.erase(v.begin()+1); // deletes element at 1 pos. 
    // to delete elements in a range
    // {10, 20, 30, 40, 50, 60, 70, 80 ,90, 100}
    v.erase(v.begin(), v.begin() + 3); // [start, end) so give end index after the element u want to delete
    // after this {30, 40, 50, 60, 70, 80 ,90, 100}

    v.insert(v.begin(), 10); // (POS_TO_INSERT, ELEMENT)

    cout << v.size();
    v.pop_back(); // O(1)
    v.empty(); 
}


void using_lists(){ // same as dequeue<int>
    // uses a doubly linked list, so push at front and back both pos unlike vector in O(1).
    list<int> l1;
    l1.push_back(1);
    l1.push_front(1);
    cout<< endl << l1.size() << endl;
    cout << l1.front() << " " << l1.back() << endl;
    l1.pop_back();
    l1.pop_front();
}


void using_stack(){ // lifo
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    // only has top access
    cout << s.top();
    s.pop();
    s.empty();
    s.size();
}

void using_qeueu(){ // fifo
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    // has front and back access.
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();
}

// Priority Queue is the implementation of Max Heap by default
// returns teh largest element by default
/*
A max-heap is a complete binary tree in which the value in each internal node is greater 
than or equal to the values in the children of that node. Mapping the elements of a heap
into an array is trivial: if a node is stored an index k, then its left child is stored 
at index 2k + 1 and its right child at index 2k + 2.
*/
void using_pq(){ 
    priority_queue<int> pq; // max heap
    pq.push(1); // O(log n) as we need to reset the tree when element is inserted such that top elemetn could be accessed in O(1)
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    int i = 1;
    while (pq.empty() != 1) {
        int peek = pq.top();
 
        cout << "The " << i++ << " th max element is " << peek << endl;
 
        // Pops the maximum element
        // out of priority queue
        pq.pop(); // //popping an elemetn is O(logn) as it has to arranged back
        priority_queue<int, vector<int>, greater<int> > pq_min_heap; // min heap
    }
}

/*
There are multiple types of sets: 
unordered set : hash table
unordered multisest: hash map
set: bst
multiset: rb tree (they are self balancing bst)

*/
void using_sets(){ // insert, erase, find all logn if unordered
    unordered_set<int> s;
	// just like unordered maps the complexity for insertion, deletion, and find is O(1).
	// no complex data types allowed, and hash tables are used.
	s.insert(0);
	s.insert(1);
	s.insert(1);
	s.insert(2);
	s.insert(100);
	s.insert(99); 
	printUnorderedSet(s);
	auto it = s.find(1);
	if(it != s.end()){
		s.erase(it); // deleting iterator takes O(1)
	}
	else{
		cout << "# the element is not in the set" << endl;
	}
	// elements are printed in random order.
	printUnorderedSet(s);


	multiset<string> m;
	// uses rb tree, can have same elements.
	// all ops are O(logn)
	// can be used as priority queues.
	// prints elements in lexicographical order
	m.insert("abc");
	m.insert("abc");

	m.insert("bce");
	m.insert("fskljs");
	printSet(m);
	auto itt = m.find("abc");
	if(itt != m.end()){
		m.erase(itt);
	}
	else{
		cout << "# the element is not in the set" << endl;
	}
	printSet(m);
	m.erase("abc");
	// difference between provind an iterator or the value to the erase function is,
	//when value is provided then each element which is same as the value provided gets deleted.
	//but when iterator is provided only one element is deleted.
	printSet(m);

}

/*  Difference between map and unordered map
		1. they use hash table instead of rb tree.
		2. all the operations now take O(1) insert, find, erase.
		3. complex keys cannot be used.
*/

void using_map(){
    unordered_map<int, string> m;
	m[1] = "dfshk"; // O(1)
	m[5] = "ahsd";
	m[2] = "ersj";
	m.insert({4, "suehgdjsk"}); // O(1)
	printMap(m);
	auto it = m.find(4); //O(1)
	cout << "find: "<< (*it).first << " " << (*it).second << endl;
	m.erase(4); // O(1)
	cout << "after erasing "<< endl;
	printMap(m);


	// print the frequency of the strings.
	unordered_map<string, int> m1;
	string s;
	int n;
	cin >> n;
	for(int i=0; i < n ; i++){
		cin >> s;
		m1[s]++;
	}
	
	
}

 
int32_t main() {
    // func(); // if we use using namespace n1, this runs 
    n1::func();
    using_pairs();
    using_vectors();
    using_lists();

}