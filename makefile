target: bitmap.o Hungarian.o graph.o verifyGraph.o global.o treeNode.o Heur-GED
CC=g++
CFLAGS= -O3 -std=c++0x -D_FILE_OFFSET_BITS=64 -D_LARGE_FILE 

Heur-GED: bitmap.o Hungarian.o graph.o verifyGraph.o global.o treeNode.o Heur-GED.cpp 
	$(CC) $(CFLAGS) bitmap.o Hungarian.o graph.o verifyGraph.o global.o treeNode.o Heur-GED.cpp -o Heur-GED
bitmap.o: bitmap.cpp
	$(CC) -c $(CFLAGS) bitmap.cpp
Hungarian.o: Hungarian.cpp
	$(CC) -c $(CFLAGS) Hungarian.cpp
graph.o: graph.cpp
	$(CC) -c $(CFLAGS) graph.cpp
verifyGraph.o: verifyGraph.cpp
	$(CC) -c $(CFLAGS) verifyGraph.cpp
global.o: global.cpp
	$(CC) -c $(CFLAGS) global.cpp
treeNode.o: treeNode.cpp
	$(CC) -c $(CFLAGS) treeNode.cpp 
clean:
	rm -rf main *.o *~ Heur-GED

