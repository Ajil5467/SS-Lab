#include<stdio.h>
#include<stdlib.h>
int w, mutex = 1, full = 0, empty = 4, x = 0, b[4];
main()//driver code
{
    int n;
    void producer(); //Function Declaration void consumer();
    int wait(int);//operation on semaphore
    int signal(int)//operation on semaphore;
    printf("\nProducer-Consumer Problem\n");
    printf("\n1.Produce\n2.Consume\n3.Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", & n);
        switch (n)
        {
        case 1: //Produce if((mutex==1)&&(empty!=0))
            producer();//go to the function defined below
            break;
            else
                printf("Buffer full\n");
        case 2: //Consume
                if((mutex==1)&&(full!=0))
                    consumer();//go to the function defined below
           
            else
                printf("Buffer empty\n");
                break;
        case 3:
            exit(0);
            break;
        }
    }
    while (1);
}
int wait(int s) //wait operation
{
    return (--s);
}
int signal(int s) //signal operation
{
    return (++s);
}
void producer()
{
    mutex = wait(mutex);
    full = signal(full);//one item will be added to the buffer
    empty = wait(empty);
    printf("Enter the value: ");
    scanf("%d", & b[x]);
    printf("Producer produces the item %d\n", b[x]);
    x++;
    mutex = signal(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);//one item consumed from buffer
    printf("Consumer consumes item %d\n", b[x - 1]);
    x--;
    mutex = signal(mutex);
}
