    while (current == NULL && top != -1)
        {
            current = stack[top];
            if (current->right == NULL || current->right == prev)
            {
                printf("%d ", current->data);
                top--;
                prev = current;
                current = NULL;
            }
            else
            {
                current = current->right;
            }
        }