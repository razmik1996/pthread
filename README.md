# pthread ![git]( https://brokersireland.ie/wp-content/uploads/2014/11/independent-trustee.jpg "ITC")
## experiment

This is the README file of the project __"threads"__  _version 1.0_
developed by __Instigate Training Center__ students.

### CONTENTS
1. AUTHOR
2. INTRODUCTION
3. PREREQUISITES / INSTALL
4. DIRECTORY STRUCTURE
5. USAGE
6. DOCUMENTATION
___


### 1. AUTHOR

_Project Maintainer:_ students group of ITC <br/>
_email:_ <xxxxxxx@gmail.com>


### 2. INTRODUCTION
_"threads"_ is a console experiment code snippet written in C++ using POSIX pthread library.
It creates and displays threads within file read/write work by CustomThread class.
The mentioned class have member functions, that have appropriate options,
plus pthreads creation using help functions, see details below:<br/>
Read member function displays the content of the file.<br/>
Write member function add new data into the file.<br/>
Find member function find the given word in the content of the file.<br/>
Note that the user will be informed by the corresponding notification if an error occurs.<br/>
The project contains tests as well (test\_suit directory), that allows to check whether the constructor and mentioned functions work correctly.<br/>
:) to be continue asap ...


### 3. PREREQUISITES / INSTALL
The following third party tools should be installed before the compilation.
>  Tools:
>> - [x] g++
>> - [x] doxygen
>> - [x] make

>  Libraries
>> - [x] pthread.h


### 4. DIRECTORY STRUCTURE
| Directory | Description   |
|-----------|---------------|
| src | contains the source, header files of the project|
| doc | contains the documentation of the project |
| test\_suit |  contains constructorTest, find\_ut, unit\_test\_template directories with their makefiles |
| makefile  | top level makefile to build the project |
|     |_Directories generated after using "make" command_ |
| bin | contains executable file of the project |
| obj | contains generated object and dep files |
| lib | contains generated library of project |
| inc | contains hard links of hpp files |


### 5. USAGE
> Commands:
>> _"make"_          - generates executable file of the project.<br/>
>> _"make doc"_      - generates doxygen documentation.<br/>
>> _"make clean"_    - cleans up the generated directories (bin, lib, obj, inc) with files.<br/>
>> _"make help"_     - displays the commands of makefile.<br/>
>> _"make push"_     - makes add, commit and push commands of git.<br/>
>> _"./bin/threads"_ - runs the program.<br/>


### 6. DOCUMENTATION
_"make doc"_ command generates doxygen documentation.<br/>
The documentation is located in the directory doc/, see [documentation](https://github.com/razmik1996/pthread/blob/master/doc/documentation). <br/>
Doxygen generates documentation according to the code comments.<br/>
The generated HTML documentation can be viewed by pointing a HTML browser to the index.html file in the html directory. For the best results a browser that supports cascading style sheets (CSS) should be used (e.g. Mozilla Firefox, Google Chrome, Safari, and sometimes IE8, IE9, and Opera to test the generated output).<br/>

To generate the doxyfile HTML documentation, please use "make doc" command,<br/>
then visit at doc/html/index.html, e.g. firefox doc/html/index.html
