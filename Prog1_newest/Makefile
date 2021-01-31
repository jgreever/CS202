#
# In order to execute this "Makefile" just type "make"
#	A. Delis (ad@di.uoa.gr)
#

OBJS	= main.o distribution.o product.o warehouse.o
SOURCE	= main.cpp distribution.cpp product.cpp warehouse.cpp
HEADER	= distribution.hpp product.hpp warehouse.hpp node.hpp
OUT	= Prog1
CC	 = g++
FLAGS	 = -g3 -c -Wall
LFLAGS	 = -lpthread
# -g option enables debugging mode 
# -c flag generates object code for separate files


all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)


# create/compile the individual files >>separately<<
main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

distribution.o: distribution.cpp
	$(CC) $(FLAGS) distribution.cpp

project.o: project.cpp
	$(CC) $(FLAGS) project.cpp

warehouse.o: warehouse.cpp
	$(CC) $(FLAGS) warehouse.cpp


# clean house
clean:
	rm -f $(OBJS) $(OUT) valgrind.log

# run the program
run: $(OUT)
	./$(OUT)

# compile program with debugging information
debug: $(OUT)
	valgrind ./$(OUT)

# run program with valgrind for errors
valgrind: $(OUT)
	valgrind ./$(OUT)

# run program with valgrind for leak checks
valgrind_leakcheck: $(OUT)
	valgrind --leak-check=full ./$(OUT)

# run program with valgrind for leak checks (extreme)
valgrind_extreme: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes --log-file=valgrind.log ./$(OUT)
