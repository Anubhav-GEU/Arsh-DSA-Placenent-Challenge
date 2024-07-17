void sortList(Node *head) {
  int count[3] = {0, 0, 0};
 
  // Count the number of 0's, 1's, and 2's in the linked list
  Node *current = head;
  while (current != nullptr) {
    count[current->data]++;
    current = current->next;
  }
 
  // Overwrite the linked list with the sorted elements
  current = head;
  int i = 0;
  while (current != nullptr) {
    if (count[i] == 0) {
      i++;
    } else {
      current->data = i;
      count[i]--;
      current = current->next;
    }
  }
}
