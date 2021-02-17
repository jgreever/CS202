#
# In order to execute this "Makefile" just type "make"
#	A. Delis (ad@di.uoa.gr)
#

OBJS	= main.o calendar.o day.o entry.o items.o
SOURCE	= main.cpp calendar.cpp day.cpp entry.cpp items.cpp
HEADER	= calendar.hpp day.hpp entry.hpp items.hpp
OUT	= Prog2
CC	 = g++
FLAGS	 = -g3 -c -Wall
LFLAGS	 = -lpthread
# -g option enables debugging mode 
# -c flag generates object code for separate files

all: ## Compile the program and create logs
	$(MAKE) obj 2>&1 | tee build.log

obj: $(OBJS) ## Make all objects and executables
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

# create/compile the individual files >>separately<<
main.o: main.cpp ## Compile only main.o
	$(CC) $(FLAGS) main.cpp

calendar.o: calendar.cpp ## Compile only calendar.o
	$(CC) $(FLAGS) calendar.cpp

day.o: day.cpp ## Compile only day.o
	$(CC) $(FLAGS) day.cpp

entry.o: entry.cpp ## Compile only entry.o
	$(CC) $(FLAGS) entry.cpp

items.o: items.cpp ## Compile only items.o
	$(CC) $(FLAGS) items.cpp

# clean house
clean: ## Cleanup all files from compilation
	rm -f $(OBJS) $(OUT) valgrind.log build.log

# run the program
run: $(OUT) ## Runs the program
	./$(OUT)

# compile program with debugging information
debug: $(OUT) ## Compiles with debugging information
	valgrind ./$(OUT)

# run program with valgrind for errors
valgrind: $(OUT) ## Runs valgrind to check for errors
	valgrind ./$(OUT)

# run program with valgrind for leak checks
valgrind_leakcheck: $(OUT) ##Run valgrind with leak tests
	valgrind --leak-check=full ./$(OUT)

# run program with valgrind for leak checks (extreme)
valgrind_extreme: $(OUT) ## Runs valgrind for ALL leak tests
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes --log-file=valgrind.log ./$(OUT)

# show the user help for running the make command
.PHONY: help

help: ## Show make command usage
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

# default message when 'make' is ran
.DEFAULT_GOAL := help