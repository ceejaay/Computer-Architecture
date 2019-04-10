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
    exit(1);
    /* return 1; */
  }

  FILE *fp;
  char lines[1024];
  int counter = 0;
  fp = fopen(arg_v[1], "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    exit(1);
  }
  while(fgets(lines, 1024, fp) != NULL) {



    char *endptr;
    unsigned char val = strtoul(lines, &endptr, 2);
    if(lines == endptr) {
      printf("skipping: %s", lines);
      continue;
    }
    cpu->ram[counter] = val;
    /* printf(" thsese are the values => %02d\n", val); */
    counter++;
  }
  /* for(int i = 0; i< 20; i++) { */
  /*   printf("ram => %x index: %d\n", cpu->ram[i], i); */
  /* } */

  fclose(fp);





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
  unsigned char arg_1, arg_2, arg_3;
  while (running) {
    printf("Registers: \n[ ");
    for (int i =0; i<8; i++) {
      printf("%d ", cpu->registers[i]);
    }
    printf("]\n");

    /* int command = 0; */
    /* for(int i = 0; i<10; i++) { */
    /*  printf("ram stuff => %x\n", cpu->ram[i] ) ; */
    /* } */
    unsigned int stack_pointer = sizeof(cpu->ram)/sizeof(cpu->ram[0]);
/* printf("stack pointer: %d\n",  stack_pointer); */
    unsigned int command = cpu->ram[cpu->pc];
    int arg_count = command >> 6;
  /* printf(" arg count: %d\n", arg_count ) ; */


    switch(command) {
/* printf(" inside switch command\n"); */
      case HLT:
        /* printf("HLT command\n"); */
        running = 0;
        break;

      case MUL:
        /* printf("Trying to multiply\n"); */
        /* cpu->pc += */ 
        arg_1 = cpu->registers[cpu->pc + 1];

        arg_2 = cpu->registers[cpu->pc + 2];
        /* printf("arg 1: %d arg2: %d\n", arg_1, arg_2); */
        running = 0;
        break;

      case PUSH:

printf(" stack pointer value %d\n", stack_pointer );
      stack_pointer--;
      arg_1 = cpu->ram[cpu->pc + 1]; //;
printf(" AFTER stack pointer value %d\n", stack_pointer );
      /* take the value from register 0 */
        /* which is */
       /* printf(" value at command + 2 %d\n", arg_1) ; */
       cpu->ram[stack_pointer] = cpu->registers[arg_1];
       cpu->pc += arg_count + 1;
        /* running = 0; */
        break;

      case POP:
       printf("POP!!\n") ;
       cpu->pc += arg_count + 1;

      case LDI:
         arg_1 = cpu->ram[cpu->pc + 1];
         arg_2 = cpu->ram[cpu->pc + 2];
         cpu->registers[arg_1] = arg_2;
         cpu->pc += arg_count + 1;
         /* cpu->pc += 3; */
         break;

      case PRN:
/* printf(" inside the prn\n"); */
       /* printf("command in PRN=> %d\n", command); */
       arg_3 = cpu->ram[cpu->pc + 1];
       printf("PRN: %d\n", cpu->registers[arg_3]);
       cpu->pc += arg_count + 1;
       break;

      default:
        printf("command in defalut=> %d\n", command);
        /* printf("cpu->pc: %d, cpu->ram instruction: %d\n", cpu->pc, cpu->ram[0]); */
        printf("Unrecognized instructions\n");
        exit(1);
    }
    /* arg_count += cpu->pc + 1; */
    /* cpu->pc += arg_count + 1; */

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
