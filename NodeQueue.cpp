// Louis Doherty
// CS 202

#include "NodeQueue.h"
#include <iostream>


NodeQueue::NodeQueue()
{
   reset();
}

NodeQueue::NodeQueue(size_t size, const DataType & value)
{
   reset();

   for (int i = 0; i < size; i++)
      push(value);
}

NodeQueue::NodeQueue(const NodeQueue & other)
{
   reset();
   for (Node * curr = other.m_front; curr != NULL; curr = curr->m_next)
   {
      push(curr->m_data);
   }
}

NodeQueue & NodeQueue::operator=(const NodeQueue & rhs)
{
   if (this != &rhs)
   {
      reset();
      for (Node * curr = rhs.m_front; curr != NULL; curr = curr->m_next)
      {
         push(curr->m_data);
      }
   }
   return *this;
}

NodeQueue::~NodeQueue()
{
   clear();
}

DataType & NodeQueue::front()
{
   if (!empty())
      return m_front->m_data;
}

const DataType & NodeQueue::front () const
{
   if (!empty())
      return m_front->m_data;
}

DataType & NodeQueue::back()
{
   if (!empty())
      return m_back->m_data;
}

const DataType & NodeQueue::back() const
{
   if (!empty())
      return m_back->m_data;
}

size_t NodeQueue::size() const
{
   return m_size;
}

bool NodeQueue::empty() const
{
   if (m_front == NULL)
      return true;
   return false;
}

bool NodeQueue:: full() const
{
   return false;
}

void NodeQueue::reset()
{
   m_size = 0;
   m_front = NULL;
   m_back = NULL;
}

void NodeQueue::clear()
{
   Node * curr = m_front;
   Node * prev = NULL;
   while (curr != NULL)
   {
      prev = curr;
      curr = curr->m_next;
      delete prev;
   }
   reset();
}

void NodeQueue::push(const DataType & value)
{
   Node * newNode = NULL;
   try
   {
      newNode = new Node(value);
   }
   catch(std::bad_alloc &ex)
   {
      throw;
   }
   std::cout << "Pushing: " << value << std::endl;
   newNode->m_next = NULL;
   if (empty())
   {

      m_front = newNode;
      m_back = newNode;
   }
   else
   {
      m_back->m_next = newNode;
      m_back = newNode;
   }

   ++m_size;
}

void NodeQueue::pop()
{
   if (empty())
      std::cout << "The list is empty, nothing to pop. " << std::endl;
   else
   {
      std::cout << "Popping 1 item " << std::endl;
      Node * temp = m_front;
      m_front = m_front->m_next;
      delete temp;
      --m_size;
   }
}

void NodeQueue::serialize(std::ostream & os) const
{
   os << "Front: " << m_front << std::endl;
   os << "Back: " << m_back << std::endl;
   os << "Size: " << m_size << std::endl;
   int i = 0;
   for (Node * curr = m_front; curr != NULL; curr = curr->m_next, i++)
      os << i << ": " << curr->m_data << std::endl;
   os << std::endl;
}

std::ostream & operator<<(std::ostream & os,
                          const NodeQueue & nodeQueue)
{
   nodeQueue.serialize(os);
   return os;
}





