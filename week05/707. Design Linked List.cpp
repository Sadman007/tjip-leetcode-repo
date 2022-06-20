class MyLinkedList {
public:
    class linkedListNode{
    public:
        int value;
        linkedListNode* next;

        linkedListNode(int val, linkedListNode* nxt){
            value = val;
            next = nxt;
        }
    };
    linkedListNode* head;
    int DUMMYVALUE = INT_MIN;

    MyLinkedList() {
        head = new linkedListNode(DUMMYVALUE, NULL);
    }

    int get(int index) {
        linkedListNode* curNode = head;
        index++;
        while(index && curNode->next != NULL){
            //cout<<curNode->value<<'\n';
            curNode = curNode->next;
            index--;
        }
        if(index == 0){
            return curNode->value;
        }
        return -1;
    }

    void addAtHead(int val) {
        //head->next = new linkedListNode(val, head->next);
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        linkedListNode* curNode = head;
        while(curNode->next != NULL){
            curNode = curNode->next;
        }
        curNode->next = new linkedListNode(val, NULL);
    }

    void addAtIndex(int index, int val) {
        linkedListNode* curNode = head;

        while(index && curNode->next){
            curNode = curNode->next;
            index --;
        }
        if(index == 0){
            curNode->next = new linkedListNode(val, curNode->next);
        }
    }

    void deleteAtIndex(int index) {
        linkedListNode* curNode = head;

        while(index && curNode->next && curNode->next->next){
            curNode = curNode->next;
            index--;
        }

        if(index == 0){
            auto dumpNode = curNode->next;
            curNode->next = curNode->next->next;
            delete(dumpNode);
        }
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
