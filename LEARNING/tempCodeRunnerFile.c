else
        {
            node *t = head;
            node *p = NULL;
            while (t->next != head && t->data != e)
            {
                p = t;
                t = t->next;
            }
            if (t->data == e)
            {
                p->next = t->next;
                t->next->prev = p;
            }
            else
            {
                printf("Element not found\n");
            }
        }
    }
}