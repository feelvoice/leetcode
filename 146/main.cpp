struct Node {
    int key, value;
    Node(int k, int v):key(k), value(v) {}
};
typedef list<Node> nodelist;
typedef unordered_map<int, nodelist::iterator> hashmap; 

class LRUCache{
private:
    int capacity_;
    nodelist nlist;
    hashmap nmap;
    
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        hashmap::iterator it = nmap.find(key);
        if (it == nmap.end()) return -1;
        
        int value = (*(it->second)).value;
        nlist.erase(it->second);
        nlist.push_front(Node(key, value));
        nmap[key] = nlist.begin();
        return value;
    }
    
    void set(int key, int value) {
        hashmap::iterator it = nmap.find(key);
        if (it == nmap.end()) {
            if (nmap.size() == capacity_) {
                Node &last = nlist.back();
                nmap.erase(last.key);
                nlist.pop_back();
            }
            nlist.push_front(Node(key, value));
            nmap[key] = nlist.begin();
        }
        else {
            nlist.erase(it->second);
            nmap.erase(key);
            nlist.push_front(Node(key, value));
            nmap[key] = nlist.begin();
        }
    }
};

