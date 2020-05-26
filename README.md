### Instuctions

1. build
 
    `./build`
    
2. run a file
 
    `./run_single_file TestFiles/"some_dir"/"test_file"` 

### Description
The code for the complier is all stored in `src` dir (including lex,bison, and c++ code). Using the ./build command 
will compile the src code into the `Compiler` dir. The `./run` command will result in an `.asm` file in the project 
directory. That file will then automatically be feed into the included `mmips.jar` program, running the assembly code, 
and outputing `std::cout`. Note that`std::cerr` and `std::clog` are also being used, however they are being 
silenced in `src/main.cpp`. Simply comment out lines `10-11` in `src/main.cpp` to reopen the log, and re-run `./build`. 

Currently the code is expected to pass all Simple Expressions, User Defined Types, and Control Statements, while 
resulting in an "gone fishing" error message being printed as a result of running any of the Function files. 
Please Email: [Colton.Hill@aggiemail.usu.edu](Colton.Hill@aggiemail.usu.edu) if this result does not happen so the 
scr code can be brought into compliance with your software(s) version.

**Thank you!**