##### RISC-V Talent Development Program, where we learn about RISC-V processor and VLSI Design using various open source tools. The instructor for this program is Kunal Ghosh Sir.

> ##### Task 1: Task is to install all the essential tools required for this internship such as Ubuntu on VMBox, Leafpad, and to refer to C based and RISCV based lab videos and execute the task of compiling the C code using gcc and riscv compiler.

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

> ##### Task 2: Compile the C program using RISC-V GCC/SPIKE with the O1 and Ofast optimization options.

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

> ##### Task 3: Task is to identify instruction type of all the given instructions with its exact 32 bits instruction code in the desired instruction type format

###### INSTRUCTIONS FORMAT IN RISC-V
The instructions format of a processor is the way in which machine language instructions are structured and organized for a processor to execute. It is made up of series of 0s and 1s, each containing information about the location and operation of data.
There are 6 instruction formats in RISC-V:

1. R-format
2. I-format
3. S-format
4. B-format
5. U-format
6. J-format

###### 1. R-type Instructions
R-type instructions are used for operations that involve only registers. These instructions typically perform arithmetic, logical, and shift operations.

Format: 
![R-Type Instruction format](image.png)

* Opcode(opcode): A 6-bit operation code (0110011 for register - register operation).
* First source register(rs1): A 5-bit register address.
* Second source register(rs1): A 5-bit register address.
* Destination register(rd): A 5-bit register address.
* Function bits(func7 and func3): Function code that specifies the operation.

###### 2. I-Type Instructions
In I-type instruction, I stand for immediate which means that operations use Registers and Immediate value for their execution and are not related with memory location.This instruction type is used in immediate and load operations.

Format:
![I-Type Instruction format](image-1.png)

- Opcode: A 6-bit field that specifies the operation(0010011 for immediate arithmetic operations).
- Destination register: The register where the result is stored.
- Function bits(func3): Further specifies the operation.
- Source register: A register that provides a source operand.
- Immediate value: A constant or immediate value used as an operand.

###### 3. S-Type Instructions
S-type instructions are used to store data from a register to memory. The S-type instruction format is a 32-bit instruction format with a 12-bit immediate field.

Format:
![S-Type Instruction Format](image-2.png)

* Opcode(opcode): A 6-bit operation code (0100011 for store operation).
* imm: Immediate value (split into imm[11:5] and imm[4:0]).
* Function bits(func3): Function code that specifies the operation.
* First source register(rs1): A 5-bit register address.
* Second source register(rs1): A 5-bit register address.

###### 4. B-Type Instructions
B-type instructions are used for conditional branches in RISC-V instruction sets.

Format:
![B-Type Instruction Format](<Screenshot 2025-01-14 114304-1.png>)

* Opcode(opcode): A 6-bit operation code (1100011 for Branch operations).
* imm: Immediate value (split into imm[12], imm[10:5], imm[4:1], imm[11]).
* Function bits(func3): Function code that specifies the operation.
* First source register(rs1): A 5-bit register address.
* Second source register(rs1): A 5-bit register address.

###### 5. U-Type Instructions
U-Type instructions are used for operations like loading upper immediate (LUI) and adding upper immediate to PC (AUIPC).

Format:
![U-Type Instruction Format](<Screenshot 2025-01-14 115924-1.png>)

* Opcode(opcode): A 6-bit operation code (0110111 for LUI operations).
* Destination register(rd): A 5-bit register address.
* imm: Upper 20 bits of the immediate value.

###### 6. J-Type Instructions
A J-type instruction is a type of MIPS instruction that specifies a target address for a jump.

Format:
![J-Type Instructions Format](<Screenshot 2025-01-14 120433.png>)

* Opcode(opcode): A 6-bit operation code (1101111 for Jump operations).
* Destination register(rd): A 5-bit register address.
* imm: Immediate value (split into imm[20], imm[10:1], imm[11], imm[19:12])