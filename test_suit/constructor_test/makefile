PROGNAME := "threads"
SOURCESWITHMAIN := $(wildcard src/*.cpp)
HEADERS := $(wildcard src/*.hpp)
HEADERS := $(patsubst src/%.hpp, inc/%.hpp, $(HEADERS))
SOURCES := $(patsubst main.cpp, , $(SOURCESWITHMAIN))
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
DEPENDS := $(patsubst src/%.cpp, obj/%.dep, $(SOURCESWITHMAIN))

bin/program: ./bin lib/libStat.a src/main.cpp $(HEADERS)
	@g++ -std=c++14 -pthread src/main.cpp -L lib -l Stat -o bin/$(PROGNAME) -I /inc
	@echo "Succesfully compiled..."
inc/%.hpp: src/%.hpp ./inc
	@ln -f $< $@
./inc:
	@echo "inc folder created..."
	@mkdir -p inc
./bin:
	@mkdir -p bin
	@echo "bin folder created..."
lib/libStat.a: ./lib $(OBJECTS)
	@ar rc lib/libStat.a $(OBJECTS)
	@echo "static lib created..."
./lib:
	@mkdir -p lib
	@echo "lib folder created..."
obj/%.o: src/%.cpp
	@mkdir -p obj
	@g++ -pthread -std=c++14 -c $< -o $@ 

obj/%.dep: src/%.cpp
	@mkdir -p obj
	@g++ -MM $< -MT "$@ $(patsubst %.dep, %.o, $@)" -o $@
-include $(DEPENDS)

.PHONY: clean
clean:
	@rm -rf bin/ lib/ obj/ inc/ out/ filename.txt res/testResult.txt
	@echo "Cleaning..."

.PHONY: push
push:
	@git add .
	@git commit -m"some changes"
	@git push origin master

.PHONY: help
help:
	@echo "type make for compiling"
	@echo "type make clean for cleaning"
	@echo "type make push for fast pushing to repo"

.PHONY: test
test: ./out
	@./bin/$(PROGNAME) >> out/output.txt
	@./bin/$(PROGNAME) >> out/output.txt
	@diff -u out/output.txt res/waited.txt > res/testResult.txt
	@echo "Succesfully tested..."

./out:
	@mkdir -p out
