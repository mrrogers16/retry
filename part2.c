#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "pagetable.h"
#include "phypages.h"

#define PAGE_SIZE 128
#define FRAME_SIZE 128
#define OFFSET_BITS 7
#define PAGE_BITS 5
#define PHYSICAL_MEMORY 1024
#define VIRTUAL_MEMORY 4096
#define TOTAL_FRAMES (PHYSICAL_MEMORY / PAGE_SIZE)
#define PAGE_TABLE_SIZE (VIRTUAL_MEMORY / PAGE_SIZE)

FILE *open_file_rb(char *filename)
{
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        fprintf(stderr, "Error opening %s\n", filename);
        return NULL;
    }
    return file;
}

FILE *open_file_wb(char *filename)
{
    FILE *file = fopen(filename, "wb");

    if (file == NULL)
    {
        fprintf(stderr, "Error opening %s\n", filename);
        return NULL;
    }
    return file;
}

int main(int argc, char *argv[])
{

    uint64_t virtual_addr;
      if (argc != 3)
    {
        fprintf(stderr, "Usage: ./%s input_file output_file", argv[0]);
        return -1;
    }

    FILE *input = open_file_rb(argv[1]);
    FILE *output = open_file_wb(argv[2]);
    struct PageTableEntry page_table[PAGE_TABLE_SIZE];


    while(fread(&virtual_addr, sizeof(uint64_t), 1, input) == 1)
    {




    }


    return 0;
}