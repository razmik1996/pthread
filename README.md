# pthread ![git]( https://brokersireland.ie/wp-content/uploads/2014/11/independent-trustee.jpg "ITC")
## experiment

This is the README file of __threads__  _version 1.0_ developed
by __Instigate Training Center__ students.

### CONTENTS
1. AUTHOR
2. INTRODUCTION
3. PREREQUISITES/ INSTALL
4. DIRECTORY STRUCTURE
5. USAGE
6. DOCUMENTATION

___

### 1. AUTHOR

_Project Maintainer:_ students group of ITC <br/>
_email:_ <xxxxxxx@gmail.com>

### 2. INTRODUCTION
_"Program"_ is a console experiment code snippet written in C++ using POSIX pthread library.
It displays threads within file read/write work by CustomThread class.

### 3. PREREQUISITES / INSTALL
The following third party tools should be installed before the compilation.
>  Tools:
>> - [x] g++
>> - [x] doxygen
>> - [x] make

To start the threads, please use ./bin/threads.

### 4. DIRECTORY STRUCTURE
| Directory | Description   |
|-----------|---------------|
| src | contains the source, header files of the project|
| doc | contains the documentation of the project |
| makefile  | top level makefile to build the project |
|     |_Directories generated after using "make" command_ |
| bin | contains executable file of project |
| obj | contains generated object and dep files |
| lib | contains generated library of project |
| inc | contains hard links of hpp files |


### 5. USAGE

> Commands:
>> _"make"_      - generates executable file of the project <br/>
>> _"make doc"_  - generates doxygen documentation. <br/>
>> _"make clean"_    - cleans up the generated directories (bin, lib, obj, inc) with files. <br/>
>> _"make help"_ - displays the commands of makefile <br />
>> _"make push"_ - add, commit and push of git <br/>
>> Please use  _./bin/thread_ to start the threads.

### 6. DOCUMENTATION
_"make doc"_ command generates doxygen documentation.<br/>
The documentation is located in the directory doc/.<br/>
Doxygen generates documentation according to code comments.<br/>

To see the doxyfile documentation, please visit at [documentation](https://github.com/razmik1996/pthread/blob/master/doc/html/index.html).
