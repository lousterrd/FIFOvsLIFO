# FIFOvsLIFO


*Purpose*

The purpose of the project was to have us compare and contrast two different implementations of a Queue.  

===== Array Queue =====
*Design*
In my implementation of the array FIFO Queue, the front of the list is where the oldest values were stored and then popped. The back of the list is where the newest items are pushed onto. When pushing an item, When size = 0 and when size = 1, the m_back and m_front both pointed to the same location. The m_back only incremented after the size > 1. The wrap around was not difficult to implement, as I re-read the lecture slides and used the Modulo operator to accomplish this.

*Problems*
When pushing an item to the list, I always incremented to m_back value, even when the the array was empty. I found that this lead to a bug, so I rewrote the code and fixed it, which I explain above. 

*Changes*
As I fully completed the implementation, I do not believe that I have any changes to make, other than add a few more comments.


===== Node Queue ======
*Design*
In this implementation of the linked list FIFO Queue, the front of the list is where the oldest values were stored and then popped. The back of the list is where the newest items are pushed onto. The clear method traverses the list, then removes and deletes all of the nodes in that list. After this occurs, a reset method is called. This method sets the front and back pointers to NULL, as well as setting the size counter to 0.

*Problems*
Initially, I had a few problems where I struggled to fully understand which side I was popping from or pushing to the list. However, after some diagrams and re-reading of the lecture notes, I was able to figure it out and was able to fully complete this project.

*Changes*
As I fully completed the implementation, I do not believe that I have any changes to make, other than add a few more comments.
