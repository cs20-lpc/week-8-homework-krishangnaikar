template <typename T>
LinkedListStack<T>::LinkedListStack() {
    top = nullptr;
    this->length = 0;
}

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    top = nullptr;
    this->length = 0;
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
    while (top != nullptr) {
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }
    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    if (copyObj.top == nullptr) {
        top = nullptr;
        this->length = 0;
        return;
    }

    // Copy first node
    Node<T>* src = copyObj.top;
    top = new Node<T>(src->data);
    Node<T>* dest = top;
    src = src->next;

    // Copy remaining nodes
    while (src != nullptr) {
        dest->next = new Node<T>(src->data);
        dest = dest->next;
        src = src->next;
    }

    this->length = copyObj.length;
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
    if (isEmpty()) {
        throw string("No elements to peek");
    }
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    if (isEmpty()) {
        throw string("No element to pop");
    }

    Node<T>* temp = top;
    top = top->next;
    delete temp;
    this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    Node<T>* n = new Node<T>(elem);
    n->next = top;
    top = n;
    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    if (this->length <= 1) {
        throw string("Not enough elements to rotate");
    }

    if (dir == Stack<T>::Direction::LEFT) {
        // Move bottom node to top
        Node<T>* curr = top;
        Node<T>* prev = nullptr;

        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }

        // curr is last node, prev is second last
        prev->next = nullptr;
        curr->next = top;
        top = curr;
    } else {
        // Move top node to bottom
        Node<T>* first = top;
        top = top->next;
        first->next = nullptr;

        Node<T>* curr = top;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = first;
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.";
    } else {
        Node<T>* curr = top;
        while (curr != nullptr) {
            cout << curr->data;
            if (curr->next != nullptr) {
                cout << "\t";
            }
            curr = curr->next;
        }
    }
    cout << endl;
}