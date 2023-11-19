#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "phypages.h"

#define PAGE_SIZE 128
#define OFFSET_BITS 7
#define PAGE_BITS 5

int max_frame;

// PageTableEntry struct
struct PageTableEntry
{
    int frame_number;
    int isValid;
    int lru_counter;
};

// Initiate one page table entry
void initPageTableEntry(struct PageTableEntry *entry, int frame)
{
    entry->frame_number = frame;
    entry->isValid = 0;
    entry->lru_counter = 0;
}

// Initiate the entire page table
// TODO calculate tableSize in main to be passed here
void initPageTable(struct PageTableEntry *page_table, int tableSize)
{
    int i;

    for (i = 0; i < tableSize; i++)
    {
        initPageTableEntry(&page_table[i], i);
    }
}