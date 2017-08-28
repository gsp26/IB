/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRUCache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

 NOTE: If you are using any global variables, make sure to clear them in the constructor. 
Example :

Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 

*/

map<int, int> myMap;
int maxi = 0;
int current = 0;

struct Node{
  int val;
  Node *next;
  Node *prev;
  Node(int x){
      val = x;
      next = NULL;
      prev = NULL;
  }
};

Node* first;
Node* lru;

LRUCache::LRUCache(int capacity) {
    myMap.erase(myMap.begin(), myMap.end());
    maxi = capacity;
    current = 0;
    first = NULL;
    lru = NULL;
}

int LRUCache::get(int key) {
    if(current > 0){
        auto it = myMap.find(key);
        if(it != myMap.end()){
            int temp = it->second;
            int value = it->first;
            Node* curr = first;
            while(curr->val != value){
                curr = curr->next;
            }
            Node* prv = curr->prev;
            Node* nxt = curr->next;
            if(prv != NULL){
                prv->next = nxt;
                if(nxt == NULL){
                    lru = prv;
                }
                else{
                    nxt->prev = prv;
                }
                curr->next = first;
                curr->prev = NULL;
                first->prev = curr;
                first = curr;
            }
            return temp;
        }
    }
    return -1;
}

void LRUCache::set(int key, int value) {
    if(myMap.find(key) == myMap.end()){
        Node* temp = new Node(key);
        myMap.insert({key, value});
        if(current != maxi){
            current++;
            if(current == 1){
                lru = temp;
                first = lru;
            }
            else{
                temp->next = first;
                first->prev = temp;
                first = temp;
            }
        }
        else{
            int t = lru->val;
            auto it = myMap.find(t);
            myMap.erase(it);
            if(lru->prev != NULL){
                lru = lru->prev;
                lru->next = NULL;    
                temp->next = first;
                first->prev = temp;
                first = temp;
            }
            else{
                lru = temp;
                first = lru;
            }
        }
    }
    else{
        myMap[key] = value;
        Node* curr = first;
        while(curr->val != key){
            curr = curr->next;
        }
        Node* prv = curr->prev;
        Node* nxt = curr->next;
        if(prv != NULL){
            prv->next = nxt;
            if(nxt == NULL){
                lru = prv;
            }
            else{
                nxt->prev = prv;
            }
            curr->next = first;
            curr->prev = NULL;
            first->prev = curr;
            first = curr;
        }
    }
}
