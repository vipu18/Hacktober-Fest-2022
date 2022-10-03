class stackUsingArray {
    // member functions
    int *data;
    int nextIndex;
    int capacity;
    
    public:
    
    // constructor
    stackUsingArray(int totalSize) {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }
    
    // operation 1: Size of the stack
    int size() {
        return nextIndex;
    }
    
    // operation 2: checking if the stack is empty
    bool isEmpty() {
        return nextIndex == 0;
    }
    
    // operation 3: pushing/inserting the element
    void push(int element) {
        if(nextIndex == capacity) {
            cout << "Stack is Full" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    
    // operation 4: Popping/Deleteing the element
    int pop() {
        if(isEmpty()) {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    
    // operation 5: Seeing the top most element
    int top() {
        return data[nextIndex-1];
    }
};
