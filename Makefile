#Marc Giannandrea | AC21008
#Makefile
#Used to build,run and clean the relevant source files


CFLAGS = -Wall -Wextra –pedantic  @#Set compiler to alert at any warnings.

build:
	g++ -o HashTable *.cpp
	@#Build all c files and output as executable HashTable

clean:
	rm -f HashTable
	@#Delete HashTable file

run:
	@([ -f ./HashTable ] && ./HashTable) || (make build && ./HashTable)
	@#If HashTable file exists then run. If not then call make build and then run HashTable
	
help:
	@echo "make build = build source files"
	@echo "make clean = clean up the built executable"
	@echo "make run = runs the executable. It will also rebuild if file doesn't exist"
	@echo "make help = prints this help section
	@#Echo all the commands possible in the make file.
