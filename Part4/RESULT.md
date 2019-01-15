Answers Part 4
--------------------

One would expect the output to be i = 0, but it is typically not. The reason for which is illustrated by the following example:

1. thread_1 fetches the value of i, and increments it
2. thread_2 fetches the value of i, before it is incremented (i = 0), and decrements it
3. thread_1 writes the result (i = 1) back to i
4. thread_2 writes its result (i = -1) to i, thus overwriting the operation performed by thread_1.

Sequences similar to this (but not necessarily identical) happening over and over will result in i having a "random" value on the interval [-1000000, 1000000] when both threads are joined at the end.