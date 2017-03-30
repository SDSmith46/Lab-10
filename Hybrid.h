#if !defined (HYBRID_H)
#define HYBRID_H

#include "QueueLinked.h"
using CSC2110::QueueLinked;
#include "SortedListDoublyLinked.h"

template < class T >
class Hybrid
{

   private:
      QueueLinked<T>* q;
      SortedListDoublyLinked<T>* sldl; 
	  T* remove (DoubleNode< T >* curr);

   public:
      Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item));
      ~Hybrid();

      bool isEmpty();
      void enqueue(T* item);
      T* dequeue();
      ListDoublyLinkedIterator<T>* iterator();
	

};

template < class T >
Hybrid<T>::Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item))
{
   q = new QueueLinked<T>();
   sldl = new SortedListDoublyLinked<T>(comp_items, comp_keys);
}

template < class T >
Hybrid<T>::~Hybrid()
{
   delete q;
   delete sldl;
}

//DO THIS
//complete the implementation for the Hybrid ADT in two different ways
//as outlined in the Lab 10 description

//remove in fifo order takes deque first in queue then remove it in the sorted doublly linked list
//Easy Implmentation
template <class T>
void Hybrid<T>::enqueue (T* item)
{
	q->enqueue(item);
	sldl->add(item);
}

template <class T>
T* Hybrid<T>::dequeue()
{
	T* hold = q->dequeue();
	sldl->remove(hold);
	return hold;
}

template < class T >
ListDoublyLinkedIterator<T>* Hybrid<T>::iterator()
{
   //locate the head/first node for the iterator without moving the interior node (loc)
   return sldl->iterator();
}
//simply comment the first implementation out when working on the second implementation
//use the getKey method to dequeue/remove






#endif
