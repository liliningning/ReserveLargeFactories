

OBJ = main.o addressBook.o
	TARGET = main

$(TARGET):$(OBJ)
	gcc $^ -o $@

main.o: main.c
	gcc -c $^ -o $@


addressBook.o: addressBook.c
	gcc -c $^ -o $@


clean:
	@rm -rf *.o $(TARGET)