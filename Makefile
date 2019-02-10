all:
	gcc main.c mjQueue.c mjLinkedList.c mjString.c mjSort.c

clean:
	rm -fr a.out
