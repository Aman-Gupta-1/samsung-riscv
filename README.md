RISC-V Talent Development Program, where we learn about RISC-V processor and VLSI Design using various open source tools. The instructor for this program is Kunal Ghosh Sir.

Task 1 is to install all the essential tools required for this internship such as Ubuntu on VMBox, Leafpad, and to refer to C based and RISCV based lab videos and execute the task of compiling the C code using gcc and riscv compiler.

1. Install Ubuntu on Virtual Machine Box

![alt text](<virtualbox installation.png>)

2. Install leafpad 

Install leafpad using command:

sudo apt install leafpad

![alt text](<leafpad installed.png>)

3. C language Based lab

Write a C code for printing sum of n numbers using leafpad. Display code using cat command.

Commands:-
leafpad sum1ton.c &
cat sum1ton.c

![alt text](<c code sum1ton.png>) 

Compile C code using following command

gcc sum1ton.c
./a.out
![alt text](<c code compilation.png>)

4. RISCV based LAB

We have to do the same compilation of our code but this time using RISCV gcc compiler. Follow the given steps:

1. Run the following command to compile the code in riscv64 gcc compiler:

riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c

2. Open a new terminal and run the given command:

riscv64-unknown-elf-objdump -d sum1ton.o | less

![alt text](<O1 riscv  code.png>)

3. The Assembly Language code of our C code will be displayed on the terminal. Type /main to locate the main section of our code.

4. Change option -O1 to -Ofast and observe the changes.

![alt text](<Ofast riscv code.png>)

Assemply code generated using -O1 option has more number of instruction as compared to Assemply code generated using -Ofast option.