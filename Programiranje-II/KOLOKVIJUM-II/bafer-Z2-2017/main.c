#include <stdio.h>
#include <stdlib.h>

/**Neka je definisan tip:
typedef struct buffer{
void *start, *front, *rear;
int size, capacity;
} BUFFER;
koji predstavlja kružni bafer podataka proizvoljnog tipa, pri čemu je: start – adresa početka bafera u memoriji, front – adresa prvog podatka u
baferu, rear – adresa posljednjeg podataka u baferu, size – veličina jednog podatka u baferu, capacity – kapacitet bafera tj. maksimalan broj
podataka u baferu. Pri tome, ako je bafer prazan, onda je front = NULL  rear = NULL, te ako bafer ima tačno jedan element, onda je front ≠
NULL  front = rear.
Napisati funkciju koja dodaje novi podatak u bafer bez prepisivanja, a vrada informaciju o tome da li je podatak uspješno dodan u bafer (0 =
podatak nije dodan u bafer, 1 = podatak je dodan u bafer). Prototip funkcije je:
int add_norewrite(BUFFER *b, const void *data);
Napisati funkciju koja dodaje novi podatak u bafer sa prepisivanjem, a vrada informaciju o tome da li je prilikom dodavanja podatka došlo do
prepisivanja (0 = nije bilo prepisivanja, 1 = bilo je prepisivanja). Prototip funkcije je:
int add_rewrite(BUFFER *b, const void *data);*/

typedef struct buffer
{
    void *start, *front, *rear;
    int size, capacity;
} BUFFER;


int add_norewrite(BUFFER *b, const void *data)
{
    if(b->front == b->start && b->rear == b->start + (b->capacity - 1) * b->size)
        return 0;
    if(b->front == NULL && b->rear == NULL)b->front = b->rear = b->start;
    else
    {
        void *new_rear = b->rear + b->size;
        if(new_rear == b->start + b->capacity*b->size)
            new_rear = b->start;
        if(new_rear == b->front)
            return 0;
        b->rear = new_rear;
    }
    memcpy(b->rear, data, b->size);
    return 1;
}


int add_rewrite(BUFFER *b, const void *data)
{
    int state=0;
    if(b->front == NULL && b->rear == NULL)b->front = b->rear = b->start;
    else
    {
        void *new_rear = b->rear + b->size;
        if(new_rear == b->start + b->capacity*b->size)
            new_rear = b->start;

        if(new_rear == b->front)
        {
            void *new_front = b->front + b->size;
            if(new_front == b->start + b->capacity*b->size)
                new_front = b->start;

            b->front = new_front;
            state=1;
        }
        b->rear = new_rear;
    }
    memcpy(b->rear, data, b->size);
    return state;
}

/**MAIN Chat GPT*/
int main()
{
    int capacity = 5;
    BUFFER buffer;
    buffer.size = sizeof(int);
    buffer.capacity = capacity;
    buffer.start = malloc(buffer.capacity * buffer.size);
    buffer.front = NULL;
    buffer.rear = NULL;

    int data[] = {1, 2, 3, 4, 5, 6};
    int result;

    printf("Adding without overwrite:\n");
    for (int i = 0; i < 6; i++) {
        result = add_norewrite(&buffer, &data[i]);
        if (result == 1) {
            printf("Added %d successfully.\n", data[i]);
        } else {
            printf("Failed to add %d. Buffer is full.\n", data[i]);
        }
    }

    buffer.front = buffer.rear = NULL; // Reset buffer

    printf("\nAdding with overwrite:\n");
    for (int i = 0; i < 6; i++) {
        result = add_rewrite(&buffer, &data[i]);
        if (result == 1) {
            printf("Added %d with overwrite.\n", data[i]);
        } else {
            printf("Added %d successfully.\n", data[i]);
        }
    }

    printf("\nBuffer contents:\n");
    int *ptr = (int *)buffer.front;
    for (int i = 0; i < capacity; i++) {
        printf("%d ", *ptr);
        ptr = (int *)((char *)ptr + buffer.size);
        if (ptr == (int *)((char *)buffer.start + buffer.capacity * buffer.size)) {
            ptr = (int *)buffer.start;
        }
        if (ptr == buffer.front) {
            break;
        }
    }
    printf("\n");

    free(buffer.start);
    return 0;
}
