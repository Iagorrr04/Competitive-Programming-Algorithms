/*
 * iagorrr ;)
 * Circular queue implementation. 
 *      - dynamic, realloc when it gets full.
 *      - 'methods':
 *          - initialize.
 *          - enqueue.
 *          - dequeue.
 *          - front.
 *          - back.
 *          - size.
 *          - full.
 *          - show_queue (must for debug)
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUESIZE (int)1e5
#define MINQUEUESIZE (int)4
#define Item_t int

typedef struct queue
{
    int l;
    int r;
    int maxsize;
    int csize;
    Item_t *q;
    
    void (*enqueue)(struct queue*, Item_t);
    void (*dequeue)(struct queue*);
    Item_t (*front)(struct queue*); 
    Item_t (*back)(struct queue*);
    int (*size)(struct queue*);
    void (*show)(struct queue*);
    char (*full)(struct queue*);

} queue;

void queue_enqueue(queue *q, Item_t i);
void queue_dequeue(queue*q);
Item_t queue_front(queue *q);
Item_t queue_back(queue *q);
int queue_empty(queue *q);
char queue_full(queue* q);
queue queue_initialize(void);
int queue_size(queue *q);
void queue_show(queue *q);
void queue_resize(queue*q, int new_size);

int main(void)
{
    queue q = queue_initialize();

    q.enqueue(&q, 1);
    q.enqueue(&q, 2);
    q.enqueue(&q, 3);
    q.enqueue(&q, 4);
    q.enqueue(&q, 5);

    q.show(&q);

    q.dequeue(&q);

    q.show(&q);

    q.dequeue(&q);

    q.enqueue(&q, -4);

    q.show(&q);

    q.enqueue(&q, -3);

    q.show(&q);

    q.enqueue(&q, -2);

    q.show(&q);

    q.enqueue(&q, -1);

    q.show(&q);
}




queue queue_initialize()
{
    queue new;
    
    new.q = malloc(sizeof(Item_t)*MINQUEUESIZE);

    new.l = 0;
    new.r = 0;
    new.csize = 0;
    new.maxsize = MINQUEUESIZE;
    
    
    new.enqueue = queue_enqueue;
    new.dequeue = queue_dequeue;
    new.front = queue_front;
    new.back = queue_back;
    new.size = queue_size;
    new.show = queue_show;
    new.full = queue_full;
    return new;
}

void queue_show(queue *q)
{
    printf("l: %d r: %d size: %d\n", q->l, q->r, q->size(q));

    for(int i = 0; i < q->maxsize; ++i) printf("%d ", q->q[i]);
    printf("\n");

}

char queue_full(queue* q)
{
    return q->csize == q->maxsize;
}

int queue_empty(queue *q)
{
    return q->l == q->r;
}

Item_t queue_back(queue *q)
{
    return q->q[q->r-1];
}

Item_t queue_front(queue *q)
{
    return q->q[q->l];
}

void queue_dequeue(queue*q)
{
    q->l = (q->l+1) % q->maxsize;
    q->csize--;
}

void queue_resize(queue*q, const int new_size)
{
    Item_t *new = malloc(sizeof(Item_t)*new_size);
    for(int i = 0; i < q->size(q); ++i)
        new[i] = q->q[(i+q->l)%q->maxsize];

    free(q->q);

    q->q = new;
    q->maxsize = new_size;

    q->l = 0;
    q->r = q->size(q);
}

void queue_enqueue(queue *q, Item_t i) {
    if(q->full(q))
    {
        queue_resize(q, q->maxsize*2);
    }
    
    q->q[q->r] = i;

    q->r = (q->r + 1) % q->maxsize;
    
    q->csize++;
}

int queue_size(queue* q)
{
    return q->csize;
}
