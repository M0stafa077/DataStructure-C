CC = gcc
MAIN = main.c
LINKED_LIST =  Linked_List/single_linked_list.c
QUEUE = Queue/queue.c 
STACK = Stack/stack.c
BINARY_TREE = Binary_Tree/binary_tree.c
HASH_TABLE = Hash-Table/Linear-Probing/hash_table.c
HASH_TABLE_QUADRATIC = Hash-Table/Quadratic-Probing/hashTable_Quadratic.c
TARGET = out

all:
	$(CC) -o $(TARGET) $(MAIN) $(LINKED_LIST) $(QUEUE) $(STACK) $(BINARY_TREE) $(HASH_TABLE) $(HASH_TABLE_QUADRATIC)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
