# Reasons for concurrency and parallelism


To complete this exercise you will have to use git. Create one or several commits that adds answers to the following questions and push it to your groups repository to complete the task.

When answering the questions, remember to use all the resources at your disposal. Asking the internet isn't a form of "cheating", it's a way of learning.

 ### What is concurrency? What is parallelism? What's the difference?
 Parallelism: Processes are actually executing simultaneously, on different CPUs (or pipelining on one CPU?).
 
 Concurrency: Processes appear to be running in parallell, but are in reality interleaving each other. Keywords: time sharing, one task begins before the previous one has completed.
 
 ### Why have machines become increasingly multicore in the past decade?
 Quantum physical concerns makes it difficult to produce chips with higher transistor density. Introducing multiple CPUs (cores), the parallellism of a computer can be increased, as an alternative way to speed it up. 
 
 ### What kinds of problems motivates the need for concurrent execution?
 (Or phrased differently: What problems do concurrency help in solving?)
 Problems with independent processes, e.g. lights blinking at different frequencies or the processes in an OS. Problems where sequential computing would result in a lot of waiting, e.g. when interfacing with I/O - units.
 
 ### Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
 (Come back to this after you have worked on part 4 of this exercise)
 Probably both, need to revisit this.
 
 ### What are the differences between processes, threads, green threads, and coroutines?
 Process: A unit of resources

 Thread: A unit of scheduling and execution. A process typically consists of multiple threads that share the processes exectuable code and variables, i.e. they share resources. Processes do not share resources with other processes. Simple: A program can be split into multiple threads that can execute concurrently. 

 Green thread: Threads that are scheduled (controlled?) by a library or VM instead of the OS (natively). Makes multithreading possible even without native support.

 Coroutine: One coroutine must willingly give up control to allow another to run. This differs from threads, who are typically preemptively scheduled. This means that a thread may be interrupted, and then its execution continues at a later time.

 Source: https://en.wikipedia.org/wiki/Thread_(computing)#Processes,_kernel_threads,_user_threads,_and_fibers.
 
 ### Which one of these do `pthread_create()` (C/POSIX), `threading.Thread()` (Python), `go` (Go) create?
 `pthread_create()` from C and `threading.Thread()` from Python create threads. `go` from Go creates a goroutine, which consists of coroutines spread out over a set of threads (when one is blocking, others are transferred to runnable threads). Question for studass: Why are threads not "light", is it because they require a lot of resources (ambiguous use of the word) to set up?  
 
 Source: https://stackoverflow.com/questions/18058164/is-a-go-goroutine-a-coroutine.
 
 ### How does pythons Global Interpreter Lock (GIL) influence the way a python Thread behaves?
 A Python thread needs to aquire the GIL before it can access any Python objects (but blocking I/O operations can be done without holding the GIL).
 
 ### With this in mind: What is the workaround for the GIL (Hint: it's another module)?
 The `multiprocessing` module allows the programmer to side-step the GIL, by using subprocesses instead of threads. As previously mentioned, processes do not share resources (memory), making it more difficult to share resources.
 
 Source: https://stackoverflow.com/questions/3044580/multiprocessing-vs-threading-python.
 
 ### What does `func GOMAXPROCS(n int) int` change? 
 `func GOMAXPROCS(n int) int` sets the maximum number of CPUs that can be executing simultaneously. 
 
 Source: https://golang.org/pkg/runtime/#GOMAXPROCS.
