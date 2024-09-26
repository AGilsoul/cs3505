CC = g++
CFLAGS = -Wall -fsanitize=undefined -fsanitize=address
SRC = src
INCLUDE = include

TrieTest: TrieTest.o Trie.o
	$(CC) $(CFLAGS) -o TrieTest TrieTest.o Trie.o

TrieTest.o: $(SRC)/TrieTest.cpp $(INCLUDE)/Trie.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)/TrieTest.cpp

Trie.o: $(SRC)/Trie.cpp $(INCLUDE)/Trie.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)/Trie.cpp

test:
	./TrieTest res/dictionary.txt res/query.txt

clean:
	rm -f TrieTest *.o