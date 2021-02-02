#
# In order to execute this "Makefile" just type "make"
#	A. Delis (ad@di.uoa.gr)
#

OBJS	= main.o calendar.o events.o phonecalls.o projects.o
SOURCE	= main.cpp calendar.cpp events.cpp phonecalls.cpp projects.cpp
HEADER	= calendar.hpp events.hpp phonecalls.hpp projects.hpp
OUT	= Prog2
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

calendar.o: calendar.cpp
	$(CC) $(FLAGS) calendar.cpp

events.o: events.cpp
	$(CC) $(FLAGS) events.cpp

phonecalls.o: phonecalls.cpp
	$(CC) $(FLAGS) phonecalls.cpp

projects.o: projects.cpp
	$(CC) $(FLAGS) projects.cpp

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
