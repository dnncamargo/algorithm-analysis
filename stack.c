#include<stdio.h>

#define DELIM " - "
#define LEN 10

void printarray(int*, int);
void printallarray(int*);
void push(int*, int*, int);
int pop(int*, int*);
void multipop(int*, int*, int);
int isempty(int);
int isfull(int);

int main(){
    int stack[LEN];
    int top = -1;

    int elim;
    push(stack, &top, 5);
    push(stack, &top, 7);
    push(stack, &top, 9);
    push(stack, &top, 11);
    push(stack, &top, 13);
    push(stack, &top, 15);
    push(stack, &top, 17);
    push(stack, &top, 19);
    push(stack, &top, 21);
    push(stack, &top, 23);
    push(stack, &top, 25);
    push(stack, &top, 27);
    elim= pop(stack, &top);
    elim= pop(stack, &top);
    elim= pop(stack, &top);
    elim= pop(stack, &top);
    elim= pop(stack, &top);
    elim= pop(stack, &top);
    elim= pop(stack, &top);
    push(stack, &top, 16);
    push(stack, &top, 18);
    push(stack, &top, 20);

    multipop(stack, &top, 3);

    printarray(stack, top);
}

void printarray(int* arr, int top)
{
    for (int i = 0; i < top; i++)
        printf("%d %s", arr[i], DELIM);
        //cout << arr[top] << endl << "Top is " << top << endl;
        printf("\n");
}

/**
 * Imprime toda a pilha
 */
void printallarray(int* arr)
{
    for (int i = 0; i < LEN -1; i++)
        printf("%d %d", arr[i], DELIM);
        printf("%d\n", arr[LEN-1], DELIM);
}


/**
 * Insere um elemento no topo da pilha
 */
void push(int* arr, int *top, int value)
{
    if(isfull(*top))
    {
        printf("Stack is full\n");
    } else {
        *top = *top + 1;

        printf("Stacking up with %d at %d position\n",value,*top);
        arr[*top] = value;
    }
}

/**
 * Remove o último elemento da pilha
 */
int pop(int* arr, int *top)
{
    if(isempty(*top))
    {
        printf("Stack is empty\n");
        return -1;
    } else {
        printf("Value Removed %d at %d position\n",arr[*top], *top);
        int elimined = arr[*top];
        *top = *top - 1;
        return elimined;
    }
}

void multipop(int* arr, int* top, int k){
    while (!isempty(*top) && (k > 0)){
        pop(arr, top);
        k--;
    }
}

/**
 * Verifica se a pilha está vazia
 */
int isempty(int top)
{
    return top == -1;
}

/**
 * Verifica se a pilha está cheia
 */
int isfull(int top)
{
    return top == LEN - 1;
}

