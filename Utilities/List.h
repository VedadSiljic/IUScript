#ifndef NULL
#define NULL 0
#endif

#ifndef List_H_Included
#define List_H_Included
typedef unsigned int sizeT;

template < typename VT > struct listNode {
  listNode < VT > * Next = NULL, * Previous = NULL;
  VT value;
};

template < typename VT > class List {
  protected:
    listNode < VT > * start = NULL, * end = NULL;
    sizeT size;

    listNode<VT> *getInstance(const sizeT index) {
        if (index >= this->size)
            throw "Invalid Index";
        else {
            listNode<VT> *temp;
            if (index <= this->size / 2 - 1) {
                temp = start;
                for (unsigned int i = 0; i < index; i++)
                temp = temp->Next;
            } else {
                temp = end;
                for (unsigned int i = this->size - 1; i > index; i--)
                temp = temp->Previous;
            }

            return temp;
        }
    }
  public:
    void Add(VT valueToAdd,
      const sizeT index) {
      if (index > this -> size)
        throw "Invalid Position";
      else if (index == size) {
        if (!size)
          start = end = new listNode < VT > ;
        else {
          end -> Next = new listNode < VT > ;
          end -> Next -> Previous = end;
          end = end -> Next;
        }
        end -> value = valueToAdd;
      } else {
        listNode < VT > * temp = getInstance(index), * valueNodeToAdd = new listNode < VT > ;
        if (temp == start)
          start = valueNodeToAdd;

        valueNodeToAdd -> value = valueToAdd;
        valueNodeToAdd -> Previous = temp -> Previous;
        valueNodeToAdd -> Next = temp;

        if (valueNodeToAdd -> Previous)
          valueNodeToAdd -> Previous -> Next = valueNodeToAdd;
        temp -> Previous = valueNodeToAdd;
      }

      this -> size = this -> size + 1;
    } // Adds a value to the specific index

  void Add(VT valueToAdd) {
    Add(valueToAdd, this -> size);
  }

  void Remove(const sizeT indexToRemove) {
    listNode < VT > * temp = this -> getInstance(indexToRemove);
    if (start == temp)
      start = temp -> Next;
    if (end == temp)
      end = temp -> Previous;

    if (temp -> Previous != NULL)
      temp -> Previous -> Next = temp -> Next;
    if (temp -> Next != NULL)
      temp -> Next -> Previous = temp -> Previous;

    delete temp;
    this -> size = this -> size - 1;
  } // Removes a value at a index

  void Remove() {
    Remove(this -> size - 1);
  }

  List(VT * array = NULL,
    const sizeT size = 0) {
    this -> size = 0;
    for (sizeT i = 0; i < size; i++)
      Add( * (array + i), this -> size);
  }
  
  ~List() {
    while (!this -> size)
      Remove();
  }
};
#endif