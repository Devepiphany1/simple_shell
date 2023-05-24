#include "simple.h"

size_t list_len(const list_t *g) {
    size_t count = 0;

    while (g) {
        g = g->next;
        count++;
    }

    return count;
}

char **list_to_strings(list_t *g) {
    list_t *node = g;
    size_t count = list_len(g);
    char **strs;
    char *str;

    if (!g || !count)
        return NULL;

    strs = malloc(sizeof(char *) * (count + 1));
    if (!strs)
        return NULL;

    for (size_t i = 0; node; node = node->next, i++) {
        str = malloc(_strlen(node->v) + 1);
        if (!str) {
            for (size_t j = 0; j < i; j++)
                free(strs[j]);
            free(strs);
            return NULL;
        }

        str = _strcpy(str, node->v);
        strs[i] = str;
    }

    strs[count] = NULL;
    return strs;
}

size_t print_list(const list_t *g) {
    size_t count = 0;

    while (g) {
        _puts(convert_number(g->num, 10, 0));
        _putchar(':');
        _putchar(' ');
        _puts(g->v ? g->v : "(nil)");
        _puts("\n");
        g = g->next;
        count++;
    }

    return count;
}

list_t *node_starts_with(list_t *g, char *prefix, char c) {
    char *p = NULL;

    while (g) {
        p = starts_with(g->v, prefix);
        if (p && ((c == -1) || (*p == c)))
            return g;
        g = g->next;
    }

    return NULL;
}

ssize_t get_node_index(list_t *head, list_t *g) {
    size_t index = 0;

    while (head) {
        if (head == g)
            return index;
        head = head->next;
        index++;
    }

    return -1;
}

