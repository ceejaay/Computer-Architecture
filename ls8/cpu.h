#ifndef _CPU_H_
#define _CPU_H_

// Holds all information about the CPU
struct cpu {
  // TODO
  // PC
  int pc;
  unsigned char registers[8];
  unsigned char ram[256]; // not sure how long this should be.
  // ram (array)
};

// ALU operations
enum alu_op {
	ALU_MUL
	// Add more here
};

// Instructions

// These use binary literals. If these aren't available with your compiler, hex
// literals should be used.

#define LDI  0b10000010 // 130
#define HLT  0b00000001
#define PRN  0b01000111
#define HELLO 0b1100011
#define MUL 0b10100010

/* #define HELLO */ 
// TODO: more instructions here. These can be used in cpu_run().

// Function declarations

extern void cpu_load(struct cpu *cpu, char **argv, int argc);
extern void cpu_init(struct cpu *cpu);
extern void cpu_run(struct cpu *cpu);

#endif
