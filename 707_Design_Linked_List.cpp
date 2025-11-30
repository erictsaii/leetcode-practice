class MyLinkedList {
public:
    class Node {
    public:
        int val;
        Node* next;
    };

    Node* dummy;
    int len;

    MyLinkedList() {
        dummy = new Node();
        len = 0;
    }
    
    int get(int index) {
        if (index > len-1) return -1;

        Node* curr = dummy->next;

        while (curr && index) {
            index--;
            curr = curr->next;
        }
        
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* new_node = new Node();
        new_node->val = val;
        new_node->next = dummy->next;
        dummy->next = new_node;
        len++;
    }
    
    void addAtTail(int val) {
        Node* curr = dummy;

        while (curr->next) {
            curr = curr->next;
        }

        Node* new_node = new Node();
        new_node->val = val;
        new_node->next = nullptr;
        curr->next = new_node;
        len++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > len) return;
        if (index == len) {
            addAtTail(val);
            return;
        }

        Node* curr = dummy;
        while (index) {
            curr = curr->next;
            index--;
        }

        Node* new_node = new Node();
        new_node->val = val;
        new_node->next = curr->next;
        curr->next = new_node;
        len++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= len) return;

        Node* curr = dummy;
        while (index) {
            curr = curr->next;
            index--;
        }

        Node* to_delete = curr->next;
        curr->next = curr->next->next;
        delete to_delete;
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
