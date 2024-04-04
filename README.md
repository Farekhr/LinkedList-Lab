# LinkedList-Lab
COMPENG 2SI3 Linked List Lab.

Here, I delved deep into likedlist implementations, learning how to work with this abstract data type. 

Constructor and Destructor:
- Implement both to manage resources properly. The constructor should initialize the list with dummy head and tail nodes.

Size Management Functions:
- `getSize()`: Returns the number of elements in the list.
- `isEmpty()`: Checks if the list is empty.

Element Insertion Functions:
- `insertHead(const objPos &thisPos)`: Inserts an element at the beginning of the list, just after the dummy head.
- `insertTail(const objPos &thisPos)`: Adds an element at the end, just before the dummy tail.
- `insert(const objPos &thisPos, int index)`: Inserts an element at a specified index, with checks to delegate to `insertHead` or `insertTail` as appropriate.

Element Retrieval Functions:
- `getHead() const`: Retrieves the first real element after the dummy head.
- `getTail() const`: Gets the last real element before the dummy tail.
- `get(int index) const`: Fetches an element at a specified index, with boundary checks to return head or tail elements as needed.

Element Modification Function:
- `set(const objPos &thisPos, int index)`: Updates the element at the specified index with new data.

Element Removal Functions:
- `removeHead()`: Removes and returns the first real element.
- `removeTail()`: Deletes and returns the last real element.
- `remove(int index)`: Removes and returns an element at a specific index, with boundary checks to delegate to `removeHead` or `removeTail` as appropriate.

List Traversal and Debugging:
- **Persistent Read Head (`persistHead`)**: Manage a pointer for efficient list traversal, with two design choices for its behavior in advancing through the list.
- `printList() const`: Debugging utility to visually display the structure and content of the list, highlighting the connections between nodes.

