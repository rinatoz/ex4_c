CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_MY_TRIE=trie.o
FLAGS= -Wall -g

all: limytrie.so limytrie.a frequencys frequency	
frequencys: $(OBJECTS_MAIN) limytrie.a
	$(CC) $(FLAGS) -o frequencys $(OBJECTS_MAIN) limytrie.a
frequency: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o frequency $(OBJECTS_MAIN) ./limytrie.so
limytrie.so: $(OBJECTS_MY_TRIE) 
	$(CC) -shared -o limytrie.so $(OBJECTS_MY_TRIE)
limytrie.a: $(OBJECTS_MY_TRIE) 
	$(AR) -rcs limytrie.a $(OBJECTS_MY_TRIE) 	
trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c
main.o: main.c trie.h  
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so progmains progmaind
