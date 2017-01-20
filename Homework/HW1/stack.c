#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stackT *NewStack(void)
{
    stackT * temp = malloc(sizeof(stackT));
    temp->head = NULL;
    return temp;
}

void Push(stackT *stack, valueT value)
{
    nodeT * temp = malloc(sizeof(nodeT));
    temp->value = value;


    if(stack->head == NULL)
    {

        temp->next = NULL;
    }
    else
    {

        temp->next = stack->head;
    }

    stack->head = temp;

}

valueT Pop(stackT *stack)
{
    if(stack->head == NULL)
    {
        printf("Stack is empty.\n");
        return 0;
    }

    nodeT * temp = stack->head;

    if(stack->head->next != NULL)
    {
        stack->head = stack->head->next;
    }
    else
    {
        stack->head = NULL;
    }
    char val = temp->value;

    free(temp);

    return val;
}

void EmptyStack(stackT *stack)
{
    while(stack->head != NULL)
    {
        nodeT * temp = stack->head;
        if(temp->next == NULL)
        {
            stack->head = NULL;
        }
        else
        {
            stack->head = stack->head->next;
        }


        free(temp);
    }

    printf("Stack emptied.\n");
}

void FreeStack(stackT *stack)
{
    if(stack->head != NULL)
    {
        printf("Stack is not empty!\n");
        return 0;
    }
    else
    {
        free(stack);
    }

}

bool IsEmpty(stackT *stack)
{
    if(stack->head == NULL)
    {
		return true;
	}else{
		return false;
	}
}

