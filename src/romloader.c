#include "romloader.h"

#include "datatype.h"
#include "filereader.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

const Byte ROM_SIGNATURE[] = {0x4D,0x59,0x36,0x35,0x30,0x32,0xFF,0xFF};

static bool verifyRom(Reader *reader){
    int fs = reader->filesize;
    size_t diff = fs - SIGNATURE_SIZE;
    if(diff != MAX_MEM){
        printf("filesize wrong: got %d, extpected %d\n", reader->filesize, MAX_MEM);
        return false;
    }

    for(int i = 0; i < fs; ++i){
        if(i < 8){
            if((Byte)(reader->content[i]) != ROM_SIGNATURE[i]){
                printf("incorrect byte in header: got: %d, expected: %d\n", reader->content[i], ROM_SIGNATURE[i]);
                return false;
            }
        } 
        else {
            break;
        }    
    }
    return true;
}


//TODO fix copying the data from reader to memory
static void mapRom(Reader *reader, Mem *memory){
    for(int i = SIGNATURE_SIZE; i < MAX_MEM; ++i){
        memory->m[i] = reader->content[i + SIGNATURE_SIZE - 1];
    }
}

bool loadrom(Mem *memory, char *filepath){
    Reader reader;
    initReader(&reader);
    setFile(&reader, filepath);
    readBinaryFile(&reader);
    if(verifyRom(&reader)){
        if(!initMem(memory, MAX_MEM)){
            fprintf(stderr, "ERROR: Couldnt allocate memory. %s", strerror(errno));
            freeReader(&reader);
            return false;
        }
        mapRom(&reader, memory);
        freeReader(&reader);
        return true;
    } 

    freeReader(&reader);
    return false;
}