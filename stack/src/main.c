#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "debug.h"
#include "stack.h"

#define MAIN_DBG(message, ...)	\
 		MSG("%s" message "%s",   LIGHT_GREEN, ##__VA_ARGS__, RESET)

#define MAIN_PRT_DBG(message, ...)	\
			MSG("%s" message "%s", CYAN, ##__VA_ARGS__, RESET)

int main (int argc, char* argv[])
{
	MAIN_DBG("BEGIN\n");
	
#ifdef __STACK_A__ 
	STACK_H h;

	srand(time(NULL));

	if (false == stack_init(&h, STACK_MAXIMAL_NODE))
	{
		return -1;
	}
	
	if (true == stack_is_empty(&h))
	{
		MAIN_DBG("Stack is empty\n");
	}
	
	if (true == stack_is_full(&h))
	{
		MAIN_DBG("Stack is full\n");
	}

	stack_push(&h, (rand() % 100) + 1);
	stack_push(&h, (rand() % 100) + 1);
	stack_push(&h, (rand() % 100) + 1);
	stack_push(&h, (rand() % 100) + 1);
	stack_push(&h, (rand() % 100) + 1);
	stack_push(&h, (rand() % 100) + 1);
	stack_push(&h, (rand() % 100) + 1);
	stack_push(&h, (rand() % 100) + 1);
	stack_push(&h, (rand() % 100) + 1);
	stack_push(&h, (rand() % 100) + 1);

	if (true == stack_is_empty(&h))
	{
		MAIN_DBG("Stack is empty\n");
	}
	
	if (true == stack_is_full(&h))
	{
		MAIN_DBG("Stack is full\n");
	}

	MAIN_PRT_DBG("%d popped from stack\n", stack_pop(&h));
	MAIN_PRT_DBG("%d popped from stack\n", stack_pop(&h));
	MAIN_PRT_DBG("%d popped from stack\n", stack_pop(&h));
	MAIN_PRT_DBG("%d popped from stack\n", stack_pop(&h));
	MAIN_PRT_DBG("%d popped from stack\n", stack_pop(&h));
	MAIN_PRT_DBG("%d popped from stack\n", stack_pop(&h));
	MAIN_PRT_DBG("%d popped from stack\n", stack_pop(&h));

	stack_print(&h);
	MAIN_PRT_DBG("%d peek from stack\n", stack_peek(&h));
		
	MAIN_PRT_DBG("%d popped from stack\n", stack_pop(&h));
	MAIN_PRT_DBG("%d popped from stack\n", stack_pop(&h));
	MAIN_PRT_DBG("%d popped from stack\n", stack_pop(&h));
	
	if (false == stack_destroy(&h))
	{
		MAIN_DBG("memory destroy has some problems!\n");
		return -1;
	}
#else	/* __STACK_L__ */

	STACK_NODE_H h;
	srand(time(NULL));

	if (false == stack_init(&h))
	{
		return -1;
	}
	
	/* checking stack is empty */
	MAIN_DBG("Stack %s empty\n", (true == stack_is_empty(&h)) ? "is" : "is not");

	/* push three data to stack */
	stack_push(&h, (rand() % 100) + 1);
	stack_push(&h, (rand() % 100) + 1);
	stack_push(&h, (rand() % 100) + 1);

	/* print the stack */
	stack_print(&h);

	/* checking stack is empty */
	MAIN_DBG("Stack %s empty\n", (true == stack_is_empty(&h)) ? "is" : "is not");
	
	/* pop two data to stack */
	MAIN_PRT_DBG("%d popped from stack\n", stack_pop(&h));
	MAIN_PRT_DBG("%d popped from stack\n", stack_pop(&h));

	/* push one data to stack */
	stack_push(&h, (rand() % 100) + 1);
	
	/* print the stack */
	stack_print(&h);
	
	/* pop one data to stack */
	MAIN_PRT_DBG("%d popped from stack\n", stack_pop(&h));

	/* checking stack is empty */
	MAIN_DBG("Stack %s empty\n", (true == stack_is_empty(&h)) ? "is" : "is not");
	
	if (false == stack_destroy(&h))
	{
		MAIN_DBG("memory destroy has some problems!\n");
		return -1;
	}
#endif /* __STACK_A__ */

	MAIN_DBG("END\n");
	return 0;
}
