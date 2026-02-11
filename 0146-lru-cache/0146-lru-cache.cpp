class LRUCache {
public:
    struct Node {
        int key, val;
        Node *next, *prev;
        Node(int k, int v): key(k), val(v), next(nullptr), prev(nullptr) { }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newNode) {
        Node *temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node *delNode) {
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node *temp = mp[key];
            int res = temp->val;

            mp.erase(key);
            deleteNode(temp);
            addNode(temp);

            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node *curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }

        if(mp.size() == cap) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};
