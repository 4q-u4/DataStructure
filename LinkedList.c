//Exercise 1 Part a: Add an element at the end of the list

void insertAtBack(List * L, element item)
{
    List newNode, curNode;

    // Step 1: Create a new node and assign 'item' to its 'data' field
    newNode = (List)malloc(sizeof(Node)); // A new node newNode is created using dynamic memory allocation (malloc) to allocate memory for a Node structure.
    newNode->data = item;
    newNode->next = NULL; // Make sure the new node points to NULL (end of the list)

    // Step 2: Handle the particular case where the list is empty
    if (*L == NULL)
        *L = newNode; // If the list is empty, the new node becomes the head

    // Step 3: For a non-empty list, traverse to the end of the list
    else
    {
        curNode = *L;
        while (curNode->next != NULL) // Move to the last node (where next is NULL)
            curNode = curNode->next;

        // Step 4: Append the new node at the end of the list
        curNode->next = newNode;
    }
}


//Exercise 1 part b : Add an item at position p in the list

void insertAtPosition(List * L, element item, int p)
{
    List newNode, predNode, curNode;
    int i = 1;

    // Initialize pointers
    predNode = NULL;
    curNode = *L;

    // Traverse the linked list to find the position p or the end of the list
    while (curNode != NULL && i < p)
    {
        predNode = curNode; // Keep track of the previous node
        curNode = curNode->next; // Move to the next node
        i++; // Increment the position counter
    }

    // Check if p is a valid position (i.e., i == p)
    if (i == p)
    {
        // Create a new node and assign data to it
        newNode = (List)malloc(sizeof(Node));
        newNode->data = item;
        newNode->next = curNode; // Set the new node's next to the current node (curNode)

        // Check if the linked list is empty or p is the first position
        if (predNode == NULL)
            *L = newNode; // Update the head of the list to the new node
        else
            predNode->next = newNode; // Insert the new node after the previous node (predNode)
    }
}

//Exercise 1 part c : //A function that deletes the first element of the list

int deleteFromHead(List * L)
{
    if (*L == NULL)
        return 0; // Return 0 if the linked list is empty (no nodes to delete)

    // Save the current head node in curNode
    List curNode = *L;

    // Update the head of the linked list to the next node (second node)
    *L = (*L)->next;

    // Free the memory occupied by the previous head node
    free(curNode);

    return 1; // Return 1 to indicate successful deletion
}


//Exercise 1 part d: A function that deletes the last element of the list

int deleteFromBack(List * L)
{
    if (*L == NULL)
        return 0; // Return 0 if the linked list is empty (no nodes to delete)

    List predNode, curNode;
    predNode = NULL;
    curNode = *L;

    // Traverse the linked list to find the last node (stop at the second-to-last node)
    while (curNode->next != NULL)
    {
        predNode = curNode; // Keep track of the previous node
        curNode = curNode->next; // Move to the next node
    }

    // Check if the linked list contains only one node
    if (predNode == NULL)
    {
        free(*L); // Free the memory occupied by the head node
        *L = NULL; // Set the head of the list to NULL (empty the list)
    }
    else
    {
        predNode->next = NULL; // Update the previous node's next pointer to NULL
        free(curNode); // Free the memory occupied by the last node
    }

    return 1; // Return 1 to indicate successful

// Exercise 1 part e : delete all occurences of a given target

void removeAllOccurences(List * L, element target)
{
    while(removeElement(L,target) == 1);
}
void main()
{
    List L = NULL;
    //print list
    traversal(L);
    printf("\n");
    //prepend 2 then 3 then 4
    prepend(&L, 2);
    prepend(&L, 3);
    prepend(&L, 4);
    //print list
    traversal(L);
    printf("\n");
    //delete 3
    removeElement(&L, 3);
    //print list
    traversal(L);
    printf("\n");
    //delete 4
    removeElement(&L, 4);
    //print list
    traversal(L);
    printf("\n");
    //delete 5
    removeElement(&L, 5);
    //print list
    traversal(L);
    printf("\n");
    //insert 6 at the end
    insertAtBack(&L, 6);
    //print list
    traversal(L);
    printf("\n");
    //insert At position 1
    insertAtPosition(&L, 3, 1);
    //print list
    traversal(L);
     printf("\n");
    //insert At position 4
    insertAtPosition(&L, 5, 4);
    //print list
    traversal(L);
    printf("\n");
    //insert At position 3
    insertAtPosition(&L, 7, 3);
    //print list
    traversal(L);
    printf("\n");
    //delete from head
    deleteFromHead(&L);
    //print list
    traversal(L);
    printf("\n");
    //delete from Back
    deleteFromBack(&L);
    //print list
    traversal(L);
    printf("\n");
    //insert 7 at head and at back
    prepend(&L, 7);
    insertAtBack(&L, 7);
    //print list
    traversal(L);
    printf("\n");
    //delete all occurences of 7
    removeAllOccurences(&L, 7);
    //print list
    traversal(L);
    printf("\n");
}