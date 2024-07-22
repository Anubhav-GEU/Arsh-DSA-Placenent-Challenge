Node* rearrangeLinkedListZigzag(Node* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    
    Node* node = head;
    bool flag = true;
    
    while(node->next != nullptr) {
        if(flag) {
            if(node->data > node->next->data) {
                int t = node->data;
                node->data = node->next->data;
                node->next->data = t;
            }
            flag = !flag;
        } else {
            if(node->data < node->next->data) {
                int t = node->data;
                node->data = node->next->data;
                node->next->data = t;
            }
            flag = !flag;
        }
        
        node = node->next;
    }
    
    return head;
}
