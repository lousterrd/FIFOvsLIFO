// Louis Doherty
// CS 202

#include "ArrayQueue.h"

using namespace std;


ArrayQueue::ArrayQueue()
{
   m_front = 0;
   m_back = 0;
   m_size = 0;
}

ArrayQueue::ArrayQueue(size_t count, const DataType & value)
{
   m_front = 0;

   if (count <= ARRAY_MAX)
   {
      m_back = count - 1;
      m_size = count;

      for (int i = m_front; i < m_size; i++)
      {
         m_array[i] = value;
      }
   }
   else
   {
      cout << "You entered a 'count' above the maximum alotted size" << endl;
      m_back = 0;
      m_size = 0;
   }
}

ArrayQueue::ArrayQueue(const ArrayQueue & other)
{
   m_front = other.m_front;
   m_back = other.m_back;
   m_size = other.m_size;

   for (int i = 0; i < ARRAY_MAX; i++)
   {
      m_array[i] = other.m_array[i];
   }
}


ArrayQueue::~ArrayQueue()
{
   // No dynamically allocated memory to be delete
   // Not necessary
}

ArrayQueue & ArrayQueue::operator=(const ArrayQueue & rhs)
{
   if (this != &rhs)
   {
      m_front = rhs.m_front;
      m_back = rhs.m_back;
      m_size = rhs.m_size;

      for (int i = 0; i < m_size; i++)
      {
         m_array[i] = rhs.m_array[i];
      }
   }
   return *this;
}

DataType & ArrayQueue::front()
{
   if (!empty())
      return m_array[m_front];
}

const DataType & ArrayQueue::front() const
{
   if (!empty())
      return m_array[m_front];
}

DataType & ArrayQueue::back()
{
   if (!empty())
      return m_array[m_back];
}

const DataType & ArrayQueue::back() const
{
   if (!empty())
      return m_array[m_back];
}

void ArrayQueue::push(const DataType & value)
{
   if (full())
   {
      cout << "There is no space to push." << endl;
   }
   else
   {
      if (!empty())
         m_back = (m_back + 1) % ARRAY_MAX;

      m_array[m_back] = value;
      ++m_size;
   }
}

void ArrayQueue::pop()
{
   if (!empty())
   {
      if (m_size > 1)
         m_front = (m_front+1) % ARRAY_MAX;

      --m_size;

      /*if (empty())
         m_front = m_back;*/
   }
   else
      cout << "There is nothing to pop." << endl;
}

size_t ArrayQueue::size() const
{
   return m_size;
}

bool ArrayQueue::empty() const
{
   if (m_size == 0)
      return true;
   else
      return false;
}

bool ArrayQueue::full() const
{
   if (m_size == ARRAY_MAX)
      return true;
   else
      return false;
}

void ArrayQueue::clear()
{
   m_front = 0;
   m_back = 0;
   m_size = 0;
}

void ArrayQueue::serialize(std::ostream & os) const
{
   os << "Front: " << m_front << endl;
   os << "Back: " << m_back << endl;
   os << "Size: " << m_size << endl;
   for (int i = m_front; i < m_front + m_size;
        i++)
   {
      size_t pos = i % ARRAY_MAX;
      os << "Position: " << pos << " ";
      os << m_array[pos] << endl;
   }
}

std::ostream & operator<<(std::ostream & os, const ArrayQueue & arrayQueue)
{

   arrayQueue.serialize(os);
   return os;
}

























