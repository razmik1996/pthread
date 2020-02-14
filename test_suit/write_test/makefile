EXE:=bin/main
SRC:=$(wildcard src/*.cpp)
HEADER:=$(patsubst src/%.hpp,inc/%.hpp,$(wildcard src/*.hpp))
OBJ:=$(patsubst src/%.cpp,obj/%.o,$(SRC))
DEP:=$(patsubst src/%.cpp,obj/%.dep,$(SRC))

all: $(EXE) $(HEADER) 
	@touch file.txt

$(EXE): $(OBJ)
	@mkdir -p bin
	@g++ -std=c++11 -pthread $^ -o $@
	@echo "Write_test compiled..."

obj/%.o: src/%.cpp
	@g++ -std=c++11 -pthread -xc++ -c $< -o $@

obj/%.dep: src/%.cpp
	@mkdir -p obj
	@gcc -xc++ -MM $< -MT "$@ $(patsubst obj/%.dep,obj/%.o,$@)" -o $@

inc/%.hpp: src/%.hpp
	@mkdir -p inc
	@ln $< inc 

-include $(DEP)

.PHONY: clean
clean: 
	@rm -r bin obj inc file.txt output.txt 
	@echo "Write_test cleaning..."

.PHONY: test 
test: $(EXE)
	@./$(EXE)
	@if cmp -s file.txt golden.txt ; then echo Write_test passed succesfully...; else echo Write_test failed...; fi
	@diff -u file.txt golden.txt > output.txt
