#ifndef _CPU_H_
#define _CPU_H_

// Holds all information about the CPU
struct cpu {
  // TODO
  // PC
  int pc;
  unsigned int registers[8];
  /* int reg0[0] = 0; */
  /* int reg1[0] = 0; */
  /* int reg2[0] = 0; */
  /* int reg3[0] = 0; */
  /* int reg4[0] = 0; */
  /* int reg5[0] = 0; // interrupt mask */
  /* int reg6[0] = 0; // interrupt status */
  /* int reg7[0] = 0; // stack pointer */
  // registers (array)
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

#define LDI  0b10000010
#define HLT  0b00000001
#define PRN  0b01000111
// TODO: more instructions here. These can be used in cpu_run().

// Function declarations

extern void cpu_load(struct cpu *cpu);
extern void cpu_init(struct cpu *cpu);
extern void cpu_run(struct cpu *cpu);

#endif
