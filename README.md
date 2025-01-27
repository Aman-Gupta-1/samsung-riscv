##### RISC-V Talent Development Program, where we learn about RISC-V processor and VLSI Design using various open source tools. The instructor for this program is Kunal Ghosh Sir.


<details><summary>
Task 1: Task is to install all the essential tools required for this internship such as Ubuntu on VMBox, Leafpad, and to refer to C based and RISCV based lab videos and execute the task of compiling the C code using gcc and riscv compiler.
</summary>
<br>
1. Install Ubuntu on Virtual Machine Box

![alt text](<Task-1/virtualbox installation.png>)

2. Install leafpad 

Install leafpad using command:

    sudo apt install leafpad

![alt text](<Task-1/leafpad installed.png>)

3. C language Based lab

Write a C code for printing sum of n numbers using leafpad. Display code using cat command.

Commands:-

    leafpad sum1ton.c &
    cat sum1ton.c

![alt text](<Task-1/c code sum1ton.png>) 

Compile C code using following command

    gcc sum1ton.c
    ./a.out

![alt text](<Task-1/c code compilation.png>)

4. RISCV based LAB

We have to do the same compilation of our code but this time using RISCV gcc compiler. Follow the given steps:

1. Run the following command to compile the code in riscv64 gcc compiler:
    
        riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c

2. Open a new terminal and run the given command:

        riscv64-unknown-elf-objdump -d sum1ton.o | less

![alt text](<Task-1/O1 riscv  code.png>)

3. The Assembly Language code of our C code will be displayed on the terminal. Type /main to locate the main section of our code.

4. Change option -O1 to -Ofast and observe the changes.

        riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
        riscv64-unknown-elf-objdump -d sum1ton.o | less

![alt text](<Task-1/Ofast riscv code.png>)

Assemply code generated using -O1 option has more number of instruction as compared to Assemply code generated using -Ofast option.
</details>
<details><summary>
Task 2: Compile the C program using RISC-V GCC/SPIKE with the O1 and Ofast optimization options.
</summary>
<br>
1. The target is to run the sum1ton.c code using both gcc compiler and riscv compiler, and both of the compiler must display the same output on the terminal. So to compile the code using gcc compiler, use the following command:

        gcc sum_1ton.c  
        ./a.out

And to compile the code using riscv compiler, use the following command:

    spike pk sum1ton.o

Open the debugger in another terminal by using the following command

    spike -d pk sum_1ton.o

![alt text](<Task-2/Spike debug sum1ton.png>)

2. Compile a C program for a basic application( Factorial of a Number ) using RISC-V GCC/SPIKE.

Open Leafpad editor to write C code factorial.c . Using following Command,

    leafpad factorial.c &

Now, Compile the code for using GCC and RISC-V. Using the following commands,

For GCC,

    gcc factorial.c 
    ./a.out

![alt text](<Task-2/factorial c code and compilation using gcc, riscv-gcc, spike.png>)

For RISC-V,

    riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o factorial.o factorial.c

![alt text](<Task-2/O1 assembly code for factorial c code.png>)

    riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o factorial.o factorial.c

![alt text](<Task-2/Ofast assemble code for factorial c code.png>)

To confirm the output of gcc compiler use command,

    spike pk factorial.o

To debug the assembly instructions using spike,

    spike -d pk factorial.o 

![alt text](<Task-2/factorial c code and compilation using gcc, riscv-gcc, spike.png>)
</details>
<details><summary>
Task 3: Task is to identify instruction type of all the given instructions with its exact 32 bits instruction code in the desired instruction type format
</summary>
<br>
INSTRUCTIONS FORMAT IN RISC-V
The instructions format of a processor is the way in which machine language instructions are structured and organized for a processor to execute. It is made up of series of 0s and 1s, each containing information about the location and operation of data.
There are 6 instruction formats in RISC-V:

1. R-format
2. I-format
3. S-format
4. B-format
5. U-format
6. J-format

##### 1. R-type Instructions
R-type instructions are used for operations that involve only registers. These instructions typically perform arithmetic, logical, and shift operations.

Format: 
![R-Type Instruction format](<Task-3/R-Type%20instruction%20format.png>)

* Opcode(opcode): A 6-bit operation code (0110011 for register - register operation).
* First source register(rs1): A 5-bit register address.
* Second source register(rs1): A 5-bit register address.
* Destination register(rd): A 5-bit register address.
* Function bits(func7 and func3): Function code that specifies the operation.

##### 2. I-Type Instructions
In I-type instruction, I stand for immediate which means that operations use Registers and Immediate value for their execution and are not related with memory location.This instruction type is used in immediate and load operations.

Format:
![I-Type Instruction format](Task-3/I-Type%20instructions%20format.png)

- Opcode: A 6-bit field that specifies the operation(0010011 for immediate arithmetic operations).
- Destination register: The register where the result is stored.
- Function bits(func3): Further specifies the operation.
- Source register: A register that provides a source operand.
- Immediate value: A constant or immediate value used as an operand.

##### 3. S-Type Instructions
S-type instructions are used to store data from a register to memory. The S-type instruction format is a 32-bit instruction format with a 12-bit immediate field.

Format:
![S-Type Instruction Format](<Task-3/S-Type instruction format.png>)

* Opcode(opcode): A 6-bit operation code (0100011 for store operation).
* imm: Immediate value (split into imm[11:5] and imm[4:0]).
* Function bits(func3): Function code that specifies the operation.
* First source register(rs1): A 5-bit register address.
* Second source register(rs1): A 5-bit register address.

##### 4. B-Type Instructions
B-type instructions are used for conditional branches in RISC-V instruction sets.

Format:
![B-Type Instruction Format](<Task-3/B-Type Instruction Format.png>)

* Opcode(opcode): A 6-bit operation code (1100011 for Branch operations).
* imm: Immediate value (split into imm[12], imm[10:5], imm[4:1], imm[11]).
* Function bits(func3): Function code that specifies the operation.
* First source register(rs1): A 5-bit register address.
* Second source register(rs1): A 5-bit register address.

##### 5. U-Type Instructions
U-Type instructions are used for operations like loading upper immediate (LUI) and adding upper immediate to PC (AUIPC).

Format:
![U-Type Instruction Format](<Task-3/U-type instructions type.png>)

* Opcode(opcode): A 6-bit operation code (0110111 for LUI operations).
* Destination register(rd): A 5-bit register address.
* imm: Upper 20 bits of the immediate value.

##### 6. J-Type Instructions
A J-type instruction is a type of MIPS instruction that specifies a target address for a jump.

Format:
![J-Type instruction format](<Task-3/J-Type instruction format.png>)

* Opcode(opcode): A 6-bit operation code (1101111 for Jump operations).
* Destination register(rd): A 5-bit register address.
* imm: Immediate value (split into imm[20], imm[10:1], imm[11], imm[19:12])

##### Instructions

    riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o factorial.o factorial.c

![Assembly code instructions](<Task-3/Assembly code for factorial c code using -O1 option.png>)

##### 1. addi sp, sp, -16

Immediate arithmetic instruction

- Opcode: 0010011 (7 bits)
- Immediate: -16 (12 bits, two's complement)
- Source Register (rs1): sp (x2, 5 bits)
- Destination Register (rd): sp (x2, 5 bits)
- Function (funct3): 000 (3 bits)

Breakdown:
- Immediate (-16): 1111 1111 0000
- rs1 (sp = x2): 00010
- funct3: 000
- rd (sp = x2): 00010
- Opcode: 0010011

Binary Code:

    1111 1111 0000 0001 0000 0001 0001 0011

Hexadecimal Code:

    0xFFF0 1093

##### 2. sd ra, 8(sp)

S-Type instruction

* Opcode: 0100011 (7 bits)
* Immediate: 8 (12 bits, split into two parts: imm[11:5] and imm[4:0])
* Source Register (rs2): ra (x1, 5 bits)
* Base Register (rs1): sp (x2, 5 bits)
* Function (funct3): 011 (3 bits)

Breakdown:
* Immediate (8): 000000010000 (split into imm[11:5] = 0000000 and imm[4:0] = 01000)
* rs2 (ra = x1): 00001
* rs1 (sp = x2): 00010
* funct3: 011
* Opcode: 0100011

Binary Code:

    0000 0000 0001 0001 0011 0100 0010 0011

Hexadecimal Code:

    0x0011 3423

##### 3. li a2, 120

U-Type instruction

* Opcode: 0110111 (7 bits)
* Immediate: 120 (20 bits)
* Destination Register (rd): a2 (x12, 5 bits)

Breakdown:
* Immediate (20 bits): 00000000000000000000
* rd (a2 = x12): 10010
* Opcode: 0110111

Binary Code:

    0000 0000 0000 0000 0000 1001 0011 0111

Hexadecimal Code:

    0x0000 0937

##### 4. li a1, 5

U-Type instruction

* Opcode: 0110111 (7 bits)
* Immediate: 5 (20 bits)
* Destination Register (rd): a1 (x11, 5 bits)

Breakdown:
* Immediate (20 bits): 00000000000000000000
* rd (a1 = x11): 10001
* Opcode: 0110111

Binary Code:

    0000 0000 0000 0000 0000 1000 1011 0111

Hexadecimal Code:

    0x0000 08B7

##### 5. lui a0, 0x21

U-Type instruction

* Opcode: 0110111 (7 bits)
* Immediate: 0x21 (20 bits)
* Destination Register (rd): a0 (x10, 5 bits)

Breakdown:
* Immediate (20 bits): 00000000000000000000
* rd (a0 = x10): 10000
* Opcode: 0110111

Binary Code:

    0000 0000 0000 0000 0000 1000 0011 0111

Hexadecimal Code:

    0x0000 0837

##### 6. addi a0, a0, 384

Immediate arithmetic instruction

- Opcode: 0010011 (7 bits)
- Immediate: 384 
- Source Register (rs1): a0 (x10, 5 bits)
- Destination Register (rd): a0 (x10, 5 bits)
- Function (funct3): 000 (3 bits)

Breakdown:
- Immediate (384): 0110 0000 0000
- rs1 (a0 = x10): 10000
- funct3: 000
- rd (a0 = x10): 10000
- Opcode: 0010011

Binary Code:

    0110 0000 0000 1000 0000 1000 0001 0011

Hexadecimal Code:

    0x6008 0813

##### 7. jal ra,10408

J-Type instruction

* Opcode: 1101111 (7 bits)
* Immediate: 0x10408(20 bits)
* Destination Register (rd): ra (x1, 5 bits)

Breakdown:
* Immediate (20 bits): 00000001010001010100 (splits into multiple parts for encoding)
* rd (ra = x1): 00001
* Opcode: 1101111

Binary Code:

    0000 1010 1001 0000 0010 0000 1110 1111

Hexadecimal Code:

    0x0A90 20EF

##### 8. li a0, 0

U-Type instruction

* Opcode: 0110111 (7 bits)
* Immediate: 5 (20 bits)
* Destination Register (rd): a0 (x10, 5 bits)

Breakdown:
* Immediate (20 bits): 00000000000000000000
* rd (a0 = x10): 10000
* Opcode: 0110111

Binary Code:

    0000 0000 0000 0000 0000 1000 0011 0111

Hexadecimal Code:

    0x0000 0837

##### 9. ld ra, 8(sp)

S-Type instruction

* Opcode: 0100011 (7 bits)
* Immediate: 8 (12 bits, split into two parts: imm[11:5] and imm[4:0])
* Source Register (rs2): ra (x1, 5 bits)
* Base Register (rs1): sp (x2, 5 bits)
* Function (funct3): 011 (3 bits)

Breakdown:
* Immediate (8): 000000010000 (split into imm[11:5] = 0000000 and imm[4:0] = 01000)
* rs2 (ra = x1): 00001
* rs1 (sp = x2): 00010
* funct3: 011
* Opcode: 0100011

Binary Code:

    0000 0000 0001 0001 0011 0100 0010 0011

Hexadecimal Code:

    0x0011 3423

##### 10. addi sp, sp, 16

Immediate arithmetic instruction

- Opcode: 0010011 (7 bits)
- Immediate: 16 
- Source Register (rs1): sp (x2, 5 bits)
- Destination Register (rd): sp (x2, 5 bits)
- Function (funct3): 000 (3 bits)

Breakdown:
- Immediate (16): 0000 0001 0000
- rs1 (sp = x2): 00010
- funct3: 000
- rd (sp = x2): 00010
- Opcode: 0010011

Binary Code:

    0000 0001 0000 0001 0000 0001 0001 0011

Hexadecimal Code:

    0x0101 0113
</details>

<details><summary>
Task 4: By making use of RISCV Core: Verilog Netlist and Testbench, perform an experiment of Functional Simulation and observe the waveforms
</summary>
<br>
Steps to perform functional simulation of RISCV

1. Download Files:
Download the code from the reference github repo.

2. Set Up Simulation Environment:
Install iverlog using commands:

        sudo apt-get install iverilog
        sudo apt install gtkwave

3. To run and simulate the verilog code, enter the following command:

        iverilog -o iiitb_rv32i iiitb_rv32i.v iiitb_rv32i_tb.v
        ./iiitb_rv32i

4. To see the simulation waveform in GTKWave, enter the following command:

        gtkwave iiitb_rv32i.vcd

32-bits instruction used in the code:

![Instructions](<Task-4/instructions.png>)

Analysing the Output Waveform of various instructions that we have covered in this task.

1. ADD R6,R1,R2

![ADD R6,R1,R2](<Task-4/ADD.jpg>)

2. SUB R7,R1,R2

![SUB R7,R1,R2](<Task-4/sub.jpg>)

3. And R8,R1,R3

![And R8,R1,R3](<Task-4/and.jpg>)

4. OR R9,R2,R5

![OR R9,R2,R5](<Task-4/or.jpg>)

5. XOR R10,R1,R4

![XOR R10,R1,R4](<Task-4/xor.jpg>)

6. SLT R11,R2,R4

![SLT R11,R2,R4](<Task-4/slt.jpg>)

7. ADDI R12,R4,5

![ADDI R12,R4,5](<Task-4/ADDI.jpg>)

8. BEQ R0,R0,15

![BEQ R0,R0,15](<Task-4/BEQ.jpg>)

9. ADD R14,R2,R2

![ADD R14,R2,R2](<Task-4/add(i11).jpg>)
</details>

<details><summary>
Task 5: Task is to implement any digital circuit using VSDSquadron Mini.
</summary>
<br>
 
**Overview**
This project involves the implementation of a **4-bit up counter** using the **VSDSquadron Mini**, a RISC-V based SoC development kit. The 4-bit counter is a fundamental digital circuit that counts from 0 to 15, with the output displayed on external **LEDs**. This project demonstrates the use of **digital logic** and **GPIO pins** for implementing a simple counting operation and showcases the practical application of the **RISC-V architecture**. The counting operation is simulated using the **PlatformIO IDE**, and the counter's value is visually displayed by toggling LEDs connected to the **VSDSquadron Mini**.

**Components Required**
- **VSDSquadron Mini** SoC Development Kit
- **LEDs** (4 LEDs to display the 4-bit counter output)
- **Breadboard** (for connecting components)
- **Jumper Wires** (for making connections)
- **VS Code** (for software development)
- **PlatformIO IDE** (for simulation and development)

**Hardware Connections**
- **Inputs**: There are no direct inputs required for the 4-bit counter; it operates as an autonomous counter.
- **Outputs**: Four LEDs are connected to the GPIO pins of the **VSDSquadron Mini** to display the counter's 4-bit value. These LEDs will toggle according to the binary count (0 to 15).
- The **GPIO pins** are configured according to the **VSDSquadron Mini Reference Manual**, ensuring the correct flow of signals between the components for accurate display of the counter output.

Program:

        #include<stdio.h>
        #include<debug.h>
        #include<ch32v00x.h>

        // GPIO Configuration Function
        void GPIO_Config(void) {
            GPIO_InitTypeDef GPIO_InitStructure = {0}; // GPIO configuration structure

            // Enable clocks for the required GPIO ports
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); // Enable clock for Port C

            // Configure output pins (for LEDs)
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // Configure as push-pull output
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Set output speed
            GPIO_Init(GPIOC, &GPIO_InitStructure);
        }

        // Simple delay function
        void Delay_ms(uint32_t ms) {
            uint32_t count;
            while (ms--) {
            for (count = 0; count < 8000; count++); // Approx. delay for 1ms (tune as needed)
            }
        }
        
        // Main Function
        int main(void) {
            uint8_t counter = 0; // 4-bit counter (0 to 15)

            NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // Set priority grouping
            SystemCoreClockUpdate();                       // Update system clock
            Delay_Init();                                  // Initialize delay
            GPIO_Config();                                 // Initialize GPIO

            while (1) {
            // Write the 4-bit counter value to GPIO pins
            GPIO_Write(GPIOC, (counter & 0x0F)); // Only use the lower 4 bits of the counter

            // Increment counter (wraps around after 15)
            counter = (counter + 1) & 0x0F; // Keep counter within 4 bits

            // Add a delay for visibility
            Delay_ms(500); // 500ms delay for visible LED changes
            }
        }

</details>