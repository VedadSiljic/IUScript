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

template <typename VT> class List {
    protected:
        listNode<VT> *start = NULL, *end = NULL;
        sizeT size;
    public:
        List(){}
        ~List(){}
};
#endif