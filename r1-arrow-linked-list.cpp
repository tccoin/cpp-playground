// implement linked list by overloading operator->
// example: start->item(2)->item(3)
#include <iostream>

class Node {
private:
    int _data;
    Node* _next = nullptr;
public:
    Node() {}
    Node(int data) {
        _data = data;
    }

    Node& item(int data) {
        _data = data;
        return *this;
    }

    Node* operator->() {
        _next = new Node();
        return _next;
    }

    void show() {
        std::cout << _data << std::endl;
    }
    Node& getNext() {
        return *_next;
    }

};


int main() {
    auto list = Node(1);
    list->item(2)->item(3);
    list.show();
    list.getNext().show();
    list.getNext().getNext().show();
    
    // for(auto& i:list){
    //     i->show();
    // }
    return 0;
}
