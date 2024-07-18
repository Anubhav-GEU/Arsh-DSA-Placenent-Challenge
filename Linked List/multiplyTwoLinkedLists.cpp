class solution {
  public:
    long long mod = 1e9+7;
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        Node* temp1 = first;
        Node* temp2 = second;
        long long int s1=0, s2=0;
        while(temp1) {
            s1 = (s1*10+temp1->data)%mod;
            temp1 = temp1->next;
        }
        while(temp2) {
            s2 = (s2*10+temp2->data)%mod;
            temp2 = temp2->next;
        }
        return (s1*s2)%mod;
    }
};
