// #include "arrStack.h"
// #include "arrQueue.h"
// #include "LLStack.h"
// #include "LLQueue.h"
#include "CursorBasedStack.h"
#include "CursorBasedQueue.h"
#include "studtype.h"


int main(){ 
    /* Datas */ 
    Studtype students[11] = {
        {{"Johnson", "Mary", 'A'}, 202202, "BSIT", 1},
        {{"Williams", "David", 'S'}, 201903, "BSEE", 4},
        {{"Smith", "John", 'D'}, 202101, "BSCS", 2},
        {{"Brown", "Jennifer", 'M'}, 202004, "BSCE", 3},
        {{"Jones", "Michael", 'R'}, 202105, "BSME", 2},
        {{"Garcia", "Linda", 'F'}, 201906, "BSN", 4},
        {{"Miller", "Robert", 'P'}, 202207, "BSA", 1},
        {{"Davis", "Patricia", 'L'}, 202008, "BSBA", 3},
        {{"Rodriguez", "James", 'C'}, 202109, "BSPsy", 2},
        {{"Martinez", "Susan", 'E'}, 202210, "BSCrim", 1},
        {{"Lebron", "James", 'C'}, 202119, "NBA", 2},
    };
    
    Stack S = malloc(sizeof(StackS));
    Queue Q = malloc(sizeof(QueueS));
    
    initStack(S);
    initQueue(Q);
    
    for(int ndx = 0; ndx < 10; ndx++){
        push(S, students[ndx]);
        enq(Q, students[ndx]);
    }
    
    displayStack(S);
    displayQueue(Q);
    
    for(int i=0; i<2; i++){
        pop(S);
        deq(Q);
    }

    displayStack(S);
    displayQueue(Q);

    /* Data for testing the next funcitons */
    Studtype data1 = {{"Smith", "John", 'D'}, 202101, "BSCS", 2};
    Studtype data2 = {{"Pascua", "Villa", 'B'}, 202222, "BSCS", 3};
    Studtype data3 = {{"Ant", "Man", 'R'}, 202123, "BSFM", 1};
    
    /* Adding non-unique data */
    pushUnique(S, data1);
    enqUnique(Q, data1);

    /* Adding unique data */
    pushUnique(S, data2);
    enqUnique(Q, data2);
    
    /* Display test */
    displayStack(S);
    displayQueue(Q);
    
    /* Removing unique data */
    popUnique(S, data3);
    deqUnique(Q, data3);

    /* Removing non-unique data */
    popUnique(S, data2);
    deqUnique(Q, data2);

    /* Display test */
    displayStack(S);
    displayQueue(Q);

    // Empty Test
    emptyS(S);
    emptyQ(Q);
    displayStack(S);
    displayQueue(Q);
    return 0;
}