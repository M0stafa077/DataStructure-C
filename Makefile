all: main.o linked_list.o
	gcc main.o linked_list.o -o out
linked_list.o:
	gcc -c Linked_List\single_linked_list.c -o linked_list.o
main.o:
	gcc -c main.c -o main.o
clean:
	rm main.o linked_list.o out.exe
