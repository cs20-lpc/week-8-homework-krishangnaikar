template <typename T>
LinkedListStack<T>::LinkedListStack()
{ }

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    Node* temp;
    Node* current = top;
    while (top != nullptr) {
        temp = top->next;
        delete current;
        current = temp;
    }

    top = nullptr;
    
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    while (copyObj.getLength() > 0) {
        Node* n = new Node(copyObj.peek());
        n->next = top;
        top = n;
        copyObj.pop();
    }
    
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    if (this->length > 0) {
        return top->data;
    } else {
        throw string("No elements to peak");
    }
}

template <typename T>
void LinkedListStack<T>::pop() {
    if (this->length > 0) {
        top = top->next;
        this->length -= 1;
    } else {
        throw string("No element to pop");
    }
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    if (this->length > 0) {
        Node* n = new Node(elem);
        n->next = top;
        top = n;
        
    } else {
        top = new Node(elem);

    }
    this->length += 1;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TODO
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
