#include <iostream>
using namespace std;

class LinkedList {
  private:
    class Node{
      public:
        int data;
        Node *next;

        Node(int i){
          data = i;
        }

        Node(){

        }
    };

    int size = 0;
    Node *head = nullptr;

  public:
    LinkedList(){
    }

    // Deallocate memory
    ~LinkedList(){
      // Store the current node
      Node *current = head;

      // Repeat until next node is not nullptr
      while(current != nullptr){
        // Store the next node
        Node *next = current->next;

        // Delete the current node
        delete current;

        // Let the current node be the next node
        current = next;
      }
    }

    void add(int i){
      if(size == 0){
        head = new Node(i);
      }else{
        // Get the last node
        Node &tail = *get(size - 1);

        // Point the last node to the next node
        tail.next = new Node(i);
      }

      size++;
    }

    void remove(int index){

        // For either deleting the head of a linked list or not
        if(index == 0 && size > 0){
          head = head->next;
        }else{
          // Get node before the one we want to remove
          Node *prev = get(index - 1);

          // Create pointer to the current node
          Node *current = prev->next;

          // Assign the previous node to the node after the one we're removing
          prev->next = current->next;
        }
        
        size--;
    }

    Node getFirst(){
      return *head;
    }

    // Returns pointer to the node itself at specified index
    Node* get(int index){
      if(index >= size || index < 0){
        throw std::out_of_range("Invalid index: " + std::to_string(index)
         + " for LinkedList size: " + std::to_string(size));
      }

      if(index == 0){
        return head;
      }

      Node *temp = head;

      // Iterate linked list until we hit the specified index
      for(int i = 0; i < index; i++){
        temp = temp->next;
      }

      return temp;
    }

    // Prints linked list
    string to_string(){
      string s = "[";
      Node *temp = head;

      while(temp != nullptr){
        s += std::to_string(temp->data);

        temp = temp->next;

        if(temp != nullptr){
           s += ", ";
        }
      }

      s += "]";
      return s;
    }

    int getSize(){
      return size;
    }
};

int main() {
  LinkedList ll = LinkedList();
  
  ll.add(5);
  ll.add(10);
  ll.add(15);

  cout << ll.to_string();

  ll.remove(ll.getSize() - 1);
  ll.remove(ll.getSize() - 1);
  ll.remove(ll.getSize() - 1);

  cout << ll.to_string();
} 