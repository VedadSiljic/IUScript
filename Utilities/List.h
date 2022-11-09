#ifndef NULL
#define NULL 0
#endif

#ifndef List_H_Included
#define List_H_Included
typedef unsigned int sizeT;

template <typename VT> struct listNode {
  listNode<VT> *Next = NULL, *Previous = NULL;
  VT value;
};

template <typename VT> class List;
template <typename VT> class ListItterator {
private:
  listNode<VT> *itterator = NULL;
  List<VT> *selectedList = NULL;

public:
  void trackList(List<VT> *listToTrack) {
    selectedList = listToTrack;
    itterator = listToTrack->start;
  }

  ListItterator() {}
  ListItterator(List<VT> *listToTrack) { trackList(listToTrack); }
  ListItterator(List<VT> &listToTrack) { trackList(&listToTrack); }

  void operator++(int increment) {
    if (itterator)
      itterator = itterator->Next;
  }
  VT &operator*() { return itterator->value; }

  void goToEnd() {
    itterator = selectedList->end;
  } // Set itterator to the staret
  void goToStart() {
    itterator = selectedList->start;
  } // Set itterator to the end
  bool ATE() { return itterator == selectedList->end; }   // At The End
  bool ATS() { return itterator == selectedList->start; } // At The Start
  bool outside() { return !itterator; }
};

template <typename VT> class List {
protected:
  listNode<VT> *start = NULL, *end = NULL;
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
  void Add(VT valueToAdd, const sizeT index) {
    if (index > this->size)
      throw "Invalid Position";
    else if (index == size) {
      if (!size)
        start = end = new listNode<VT>;
      else {
        end->Next = new listNode<VT>;
        end->Next->Previous = end;
        end = end->Next;
      }
      end->value = valueToAdd;
    } else {
      listNode<VT> *temp = getInstance(index),
                   *valueNodeToAdd = new listNode<VT>;
      if (temp == start)
        start = valueNodeToAdd;

      valueNodeToAdd->value = valueToAdd;
      valueNodeToAdd->Previous = temp->Previous;
      valueNodeToAdd->Next = temp;

      if (valueNodeToAdd->Previous)
        valueNodeToAdd->Previous->Next = valueNodeToAdd;
      temp->Previous = valueNodeToAdd;
    }

    this->size = this->size + 1;
  } // Adds a value to the specific index

  void Add(VT valueToAdd) { Add(valueToAdd, this->size); }

  void Remove(const sizeT indexToRemove) {
    listNode<VT> *temp = this->getInstance(indexToRemove);
    if (start == temp)
      start = temp->Next;
    if (end == temp)
      end = temp->Previous;

    if (temp->Previous != NULL)
      temp->Previous->Next = temp->Next;
    if (temp->Next != NULL)
      temp->Next->Previous = temp->Previous;

    delete temp;
    this->size = this->size - 1;
  } // Removes a value at a index

  void Remove() { Remove(this->size - 1); }

  void clear() {
    while (this->size != 0)
      Remove();
  }

  List(VT *array = NULL, const sizeT size = 0) {
    this->size = 0;
    for (sizeT i = 0; i < size; i++)
      Add(*(array + i));
  }

  void copyList(List<VT> &objToCopy) {
    this->size = 0;

    for (ListItterator<VT> i = objToCopy; !i.outside(); i++)
      Add(*i);
  }

  List(List<VT> &objToCopy) { copyList(objToCopy); }

  List<VT> &operator=(List<VT> &objToCopy) {
    clear();
    copyList(objToCopy);
    return *this;
  }

  ~List() { clear(); }

  VT get(const sizeT index) {
    return this->getInstance(index)->value;
  } // gets a value at the index

  VT operator[](const sizeT index) { return get(index); }

  sizeT length() { return this->size; } // returns the length of the list

  friend class ListItterator<VT>;
};
#endif