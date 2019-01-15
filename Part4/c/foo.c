#include <pthread.h>
#include <stdio.h>

/* Questions
* Why is the return type void*?
* What does pthread_join(thread_id, NULL) do?
*/

int i = 0;

// Note the return type: void*
void* incrementingThreadFunction(){
    // TODO: increment i 1_000_000 times
    for (int n = 0; n < 1000000; ++n) {
        ++i;
    }
    return NULL;
}

void* decrementingThreadFunction(){
    // TODO: decrement i 1_000_000 times
    for (int n = 0; n < 1000000; ++n) {
        --i;
    }
    return NULL;
}


int main(){
    // TODO: declare incrementingThread and decrementingThread (hint: google pthread_create)
    pthread_t incrementingThread;
    pthread_t decrementingThread;
     
    // Reference: http://man7.org/linux/man-pages/man3/pthread_create.3.html
    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);
    
    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);
    
    printf("The magic number is: %d\n", i);
    return 0;
}
