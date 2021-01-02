// Louis Doherty
// CS 202


#include <iostream>
#include "ArrayQueue.h"
#include "NodeQueue.h"

using namespace std;


int main()
{

   DataType d0 = DataType(0, 0);
   DataType d1 = DataType(1, 1);
   DataType d2 = DataType(2, 2);
   DataType d3 = DataType(3, 3);
   DataType d4 = DataType(4, 4);
   DataType d5 = DataType(5, 5);
   DataType d6 = DataType(6, 6);


   cout << "========== ARRAY QUEUE ==========" << endl << endl;


   cout << "Testing parametrized ctor: " << endl;
   ArrayQueue a2(ARRAY_MAX, d0);
   cout << a2 << endl << endl;

   cout << "Testing copy ctor: " << endl;
   ArrayQueue a1(a2);
   cout << a1 << endl << endl;


   cout << "Testing default ctor: " << endl;
   ArrayQueue a0 = ArrayQueue();


   cout << a0.empty() << endl;
   cout << a0 << endl << endl;

   cout << "Pushing single item: " << endl;
   a0.push(d0);
   cout << a0 << endl << endl;

   cout << "Pushing items without wrap-around: " << endl;
   a0.push(d1);
   a0.push(d2);
   a0.push(d3);
   cout << a0 << endl << endl;

   cout << "Pushing item to fill: " << endl;
   a0.push(d4);
   cout << a0 << endl << endl;

   cout << "Popping 3 items: " << endl;
   a0.pop();
   a0.pop();
   a0.pop();
   cout << a0 << endl << endl;

   cout << "Pushing 2 items for gap: " << endl;
   cout << "Back will be earlier than front: " << endl;
   a0.push(d5);
   a0.push(d6);
   cout << a0 << endl << endl;

   cout << "Testing copy ctor: " << endl;
   ArrayQueue a3(a0);
   cout << a1 << endl << endl;

   cout << "Pushing 3 items for gap: " << endl;
   cout << "Back will be earlier than front: " << endl;
   a0.push(d0);
   a0.push(d1);
   a0.push(d5);
   cout << a0 << endl << endl;

   cout << "Popping all items from the queue " << endl;
   for (int i = 0; i < ARRAY_MAX; i++)
   {
      a0.pop();
   }
   cout << a0 << endl << endl;

   a0.push(d0);
   cout << a0 << endl << endl;


   cout << "========== NODE QUEUE ==========" << endl << endl;

   
   cout << "Testing default ctor: " << endl;
   NodeQueue n0;
   cout << n0 << endl << endl;

   cout << "Pushing single item: " << endl;
   n0.push(d1);
   cout << n0 << endl << endl;


   cout << "Pushing 3 items: " << endl;
   n0.push(d2);
   n0.push(d3);
   n0.push(d4);
   cout << n0 << endl << endl;

   cout << "Testing 1 pop: " << endl;
   n0.pop();
   cout << n0 << endl << endl;

   cout << "Testing 10 pops: " << endl;
   for (int i = 0; i < 10; i++)
      n0.pop();
   cout << n0 << endl << endl;

   cout << "Pushing 3 more items: " << endl;
   n0.push(d0);
   n0.push(d1);
   n0.push(d2);
   cout << n0 << endl << endl;

   cout << "Testing parametrized ctor: " << endl;
   NodeQueue n1(5, d3);
   cout << n1 << endl << endl;

   cout << "Testing 10 pops: " << endl;
   for (int i = 0; i < 10; i++)
      n1.pop();
   cout << n1 << endl << endl;

   cout << "Pushing 3 more items: " << endl;
   n1.push(d0);
   n1.push(d1);
   n1.push(d2);
   cout << n1 << endl << endl;

   cout << "Testing copy ctor: " << endl;
   NodeQueue n2(n1);
   cout << n2 << endl << endl;

   cout << "Testing clear: " << endl;
   n2.clear();
   cout << n2 << endl;




   return 0;
}














