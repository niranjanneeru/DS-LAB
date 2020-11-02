// Aim :- Implement Priority Queue Data Structure using Array

// Input:- enqueue,dequeueHighestPriority
// Output:- deque after operations
// Data Structure used :- Deque (Array in FIFO) pointed by FRONT and REAR
//
// Start
// 1. Take a array of size N QUEUE[N]
// 2. Initialize FRONT = -1 and REAR = -1
//       ITEM has data and priority
// 3. enqueue(ITEM)
// 4.     if(N-1==REAR)
// 5.          print "QUEUE OVERFLOW"
// 6.
// 7.     else if(FRONT == -1 && REAR == -1)
// 8.          FRONT=REAR=0
// 9.          QUEUE[REAR] = ITEM
// 10.    else
// 11.         REAR = REAR + 1
// 12.         QUEUE[REAR] = ITEM
// 13. dequeueHighestPriority()
// 14.     if(FRONT == -1)
// 15.          print "QUEUE UNDERFLOW"
// 16.
// 16.     ITEM = QUEUE[FRONT]
// 17.     else if(FRONT == REAR)
// 18.          FRONT=REAR=-1
// 19.     else
// 20.          FRONT = FRONT + 1
// 21.     return ITEM
// Stop


// Time Complexity
// enqueue(ITEM)
// Worst Case :- O(1)

// Space Complexity
// Worst Case :- O(1)


// dequeue()
// Worst Case :- O(1)

// Space Complexity
// Worst Case :- O(1)

