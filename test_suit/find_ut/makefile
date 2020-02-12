EXE:=main
S:=$(wildcard src/*.cpp)
H:=$(patsubst src/%.hpp,inc/%.hpp,$(wildcard src/*.hpp))
O:=$(patsubst src/%.cpp,obj/%.o,$(S))
D:=$(patsubst src/%.cpp,obj/%.dep,$(S))

all: $(EXE) $(H) 

$(EXE): $(O)
	gcc $^ -lstdc++ -o $@

obj/%.o: src/%.cpp
	gcc -xc++ -c $< -o $@

obj/%.dep: src/%.cpp
	@mkdir -p obj
	gcc -xc++ -MM $< -MT "$@ $(patsubst obj/%.dep,obj/%.o,$@)" -o $@

inc/%.hpp: src/%.hpp
	@mkdir -p inc
	ln $< inc 

-include $(D)

.PHONY: clean
clean: 
	rm -r obj $(EXE) output.txt inc 

.PHONY: doxyclean
doxyclean: 
	rm -r doxygen/html doxygen/latex 

.PHONY: test 
test: $(EXE)
	./main A.txt test 1
	@if cmp -s output.txt golden.txt ; then echo test succesfully pssed! ; else echo test faild ; fi
