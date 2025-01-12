##### RISC-V Talent Development Program, where we learn about RISC-V processor and VLSI Design using various open source tools. The instructor for this program is Kunal Ghosh Sir.

##### Task 1 is to install all the essential tools required for this internship such as Ubuntu on VMBox, Leafpad, and to refer to C based and RISCV based lab videos and execute the task of compiling the C code using gcc and riscv compiler.

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

##### Task 2 Compile the C program using RISC-V GCC/SPIKE with the O1 and Ofast optimization options.

1. The target is to run the sum1ton.c code using both gcc compiler and riscv compiler, and both of the compiler must display the same output on the terminal. So to compile the code using gcc compiler, use the following command:

gcc sum_1ton.c  
./a.out

And to compile the code using riscv compiler, use the following command:

spike pk sum1ton.o

Open the debugger in another terminal by using the following command

spike -d pk sum_1ton.o

![alt text](<Spike debug sum1ton.png>)

2. Compile a C program for a basic application( Factorial of a Number ) using RISC-V GCC/SPIKE.

Open Leafpad editor to write C code factorial.c . Using following Command,

leafpad factorial.c &

Now, Compile the code for using GCC and RISC-V. Using the following commands,

For GCC,

gcc factorial.c 
./a.out

![alt text](<factorial c code and compilation using gcc, riscv-gcc, spike-1.png>)

For RISC-V,

riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o factorial.o factorial.c

![alt text](<O1 assembly code for factorial c code.png>)

riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o factorial.o factorial.c

![alt text](<Ofast assemble code for factorial c code.png>)

To confirm the output of gcc compiler use command,

spike pk factorial.o

To debug the assembly instructions using spike,

spike -d pk factorial.o 

![alt text](<factorial c code and compilation using gcc, riscv-gcc, spike.png>)