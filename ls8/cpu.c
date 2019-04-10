#include <stdlib.h>
#include "cpu.h"
#include <stdio.h>
#include <string.h>
#define DATA_LEN 6

/**
 * Load the binary bytes from a .ls8 source file into a RAM array
 */
void cpu_load(struct cpu *cpu, char **arg_v, int arg_c)
{ 
  if (arg_c != 2) {
    printf(" Correct usage: ./files file_name.extension\n");
    /* return 1; */
  }

  FILE *fp;
  char lines[1024];
  int counter = 0;
  fp = fopen(arg_v[1], "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    /* return 2; */
  }
  while(fgets(lines, 1024, fp) != NULL) {



    char *endptr;
    unsigned char val = strtoul(lines, &endptr, 2);
    if(lines == endptr) {
      printf("skipping: %s", lines);
    }
    cpu->ram[counter] = val;
    /* printf(" thsese are the values => %02d\n", val); */
    counter++;
  }
  for(int i = 0; i< 20; i++) {
    printf("ram => %x index: %d\n", cpu->ram[i], i);
  }

  fclose(fp);




  /* printf(" argv => %s\n", arg_v[2] ); */
  /* char data[DATA_LEN] = { // From print8.ls8 */
  /*   /1* 0b10000010, // LDI R0,8 *1/ */
  /*   /1* 0b00000000, // 0 *1/ */
  /*   /1* 0b00001000, //8 *1/ */
  /*   /1* 0b01000111, // PRN R0 *1/ */
  /*   /1* 0b00000000, // 0k *1/ */
  /*   /1* 0b00000001  // HLT *1/ */
  /* }; */

  /* int address = 0; */
  /* for (int i = 0; i < DATA_LEN; i++) { */
  /*   cpu->ram[address++] = data[i]; */
  /*   /1* printf(" cpu ram : %u \n", cpu->ram[address - 1]); *1/ */
  /* } */
  /* cpu->ram[0] = 130; */

  // TODO: Replace this with something less hard-coded
}


/* void cpu_ram_read(struct cpu *cpu, int index) { */
/*   /1* return the value at the index *1/ */
/* } */

/* void cpu_ram_write(struct cpu *cpu, int value) { */
/*   /1* write it into the memory array *1/ */
/* /1* return the index? *1/ */
/* } */

/**
 * ALU
 */
/* void alu(struct cpu *cpu, enum alu_op op, unsigned char regA, unsigned char regB) */
/* { */
/*   switch (op) { */
/*     case ALU_MUL: */
/*       // TODO */
/*       break; */

/*     // TODO: implement more ALU ops */
/*     /1* case HTL; *1/ */
/*     /1*   break; *1/ */
/*   } */
/* } */

/**
 * Run the CPU
 */
void cpu_run(struct cpu *cpu)
{
  int running = 1; // True until we get a HLT instruction
  while (running) {
    /* int command = 0; */
    /* for(int i = 0; i<10; i++) { */
    /*  printf("ram stuff => %x\n", cpu->ram[i] ) ; */
    /* } */
    unsigned int command = cpu->ram[cpu->pc];
    /* unsigned int command */
    /* printf("command => %X\n", command); */
    /* for(int i = 0; i<8; i++) { */
    /*   printf("%X  ", cpu->registers[i]); */

    /* } */

    switch(command) {
/* printf(" inside switch command\n"); */
      case HLT:
        /* printf("HLT command\n"); */
        running = 0;
        break;

      /* case HELLO: */
      /*   printf("hello world\n"); */
      /*   cpu->pc += 1; */
      /*   break; */

      case MUL:
        printf("Trying to multiply");
        break;

      case LDI:
        printf("ldi is working\n");
        /* set the value of a register to an integer */
       /* printf("BEFORE cpu -> pc %d\n", cpu->pc ) ; */
       /* printf("BEFORE cpu -> ram %d\n", cpu->ram[cpu->pc]) ; */
        /* int reg0 = */ 
        int arg_1 = cpu->ram[cpu->pc + 1];
        int arg_2 = cpu->ram[cpu->pc + 2];
        cpu->registers[arg_1] = arg_2; 
        cpu->pc += 3;

      case PRN:
/* printf(" inside the prn\n"); */
       printf("command in PRN=> %X\n", command);
       printf("PRN: %d\n", cpu->registers[cpu->ram[cpu->pc + 1]]);
       cpu->pc += 2;
       break;

      default:
        printf("command => %X\n", command);
        /* printf("cpu->pc: %d, cpu->ram: %d\n", cpu->pc, cpu->ram[0]); */
        printf("Unrecognized instructions\n");
        exit(1);
    }
    // TODO
    // 1. Get the value of the current instruction (in address PC).
    // 2. Figure out how many operands this next instruction requires
    // 3. Get the appropriate value(s) of the operands following this instruction
    // 4. switch() over it to decide on a course of action.
    // 5. Do whatever the instruction should do according to the spec.
    // 6. Move the PC to the next instruction.
  }
}

/**
 * Initialize a CPU struct
 */
void cpu_init(struct cpu *cpu)
{
  cpu->pc = 0;
  /* printf("initializing cpu\n"); */
  unsigned int n = 0;
  memset(cpu->ram, 0, n * sizeof(cpu->ram[0]));
  memset(cpu->registers, 0, n * sizeof(cpu->registers[0]));
    /* for (int i = 0; i<8; i++) { */
    /*   /1* what is going on here? There seems to be some values that are not 0 *1/ */
    /*   printf("should be zeor => %d\n", cpu->registers[i]); */
    /* } */

  // TODO: Initialize the PC and other special registers
}
