#include "simple.h"

list_t *add_node(list_t **g, const char *v, int num)
{
list_t *new_head;

if (!g)
return (NULL);

new_head = malloc(sizeof(list_t));
if (!new_head)
return (NULL);

memset((void *)new_head, 0, sizeof(list_t));
new_head->num = num;

if (v)
{
new_head->str = strdup(v);
if (!new_head->str)
{
free(new_head);
return (NULL);
}
}

new_head->next = *g;
*g = new_head;
return (new_head);
}

list_t *add_node_end(list_t **g, const char *v, int num)
{
list_t *new_node, *node;

if (!g)
return (NULL);

node = *g;
new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);

memset((void *)new_node, 0, sizeof(list_t));
new_node->num = num;

if (v)
{
new_node->str = strdup(v);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}

if (node)
{
while (node->next)
node = node->next;
node->next = new_node;
}
else
{
*g = new_node;
}

return (new_node);
}

size_t print_list_str(const list_t *h)
{
size_t count = 0;

while (h)
{
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
count++;
}

return (count);
}

int delete_node_at_index(list_t **g, unsigned int v)
{
list_t *node, *prev_node;
unsigned int i = 0;

if (!g || !*g)
return (0);

if (!v)
{
node = *g;
*g = (*g)->next;
free(node->str);
free(node);
return (1);
}

node = *g;
while (node)
{
if (i == v)
{
prev_node->next = node->next;
free(node->str);
free(node);
return (1);
}

i++;
prev_node = node;
node = node->next;
}

return (0);
}

void free_list(list_t **g)
{
list_t *node, *next_node, *head;

if (!g || !*g)
return;

head = *g;
node = head;

while (node)
{
next_node = node->next;
free(node->str);
free(node);
node = next_node;
}

*g = NULL;
}

