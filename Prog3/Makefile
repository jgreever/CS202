#
# In order to execute this "Makefile" just type "make"
#	A. Delis (ad@di.uoa.gr)
#
# Files for this program:
# 	main.cpp
# 	contact.hpp contact.cpp
# 	device.hpp device.cpp
# 	methods.hpp methods.cpp
#
# Log files generated during build/test:
# 	build.log
# 	valgrind.log
#

OBJS	= main.o contact.o device.o methods.o
SOURCE	= main.cpp contact.cpp device.cpp methods.cpp
HEADER	= contact.hpp device.hpp methods.hpp
OUT	= prog3
CC	 = g++
FLAGS	 = -g3 -c -Wall
LFLAGS	 = -lpthread
# -g option enables debugging mode 
# -c flag generates object code for separate files

all: ## Compile the program and create logs
	$(MAKE) objs 2>&1 | tee build.log

objs: $(OBJS) ## Make all objects and executables
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

# create/compile the individual files >>separately<<
main.o: main.cpp ## Compile only main.o
	$(CC) $(FLAGS) main.cpp

contact.o: contact.cpp ## Compile only contact.o
	$(CC) $(FLAGS) contact.cpp

device.o: device.cpp ## Compile only device.o
	$(CC) $(FLAGS) device.cpp

methods.o: methods.cpp ## Compile only methods.o
	$(CC) $(FLAGS) methods.cpp

# clean house
clean: ## Cleanup all files from compilation
	rm -f $(OBJS) $(OUT) valgrind.log build.log leaks.log

# run the program
run: $(OUT) ## Runs the program
	./$(OUT)

# compile program with debugging information
debug: $(OUT) ## Compiles with debugging information
	valgrind ./$(OUT)

# run program with 'leaks' for macOS, since valgrind is broken
# on Big Sur and complains about dydl cache errors, check here
# for info: https://github.com/LouisBrunner/valgrind-macos/issues/19
leaks: $(OUT) ## Runs leaks for leak tests on macOS
	leaks --atExit -- ./$(OUT) 2>&1 | tee leaks.log

# run program with valgrind for leak checks (extreme)
valgrind: $(OUT) ## Runs valgrind for ALL leak tests
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes --log-file=valgrind.log ./$(OUT)

# show the user help for running the make command
.PHONY: help

help: ## Show make command usage
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

# default message when 'make' is ran
.DEFAULT_GOAL := help
