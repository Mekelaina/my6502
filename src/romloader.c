#include "romloader.h"

#include "datatype.h"
#include "filereader.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

const Byte ROM_SIGNATURE[] = {0x4D,0x59,0x36,0x35,0x30,0x32,0xFF,0xFF};

static bool verifyRom(Reader *reader){

    if(reader->filesize != MAX_MEM){
        printf("filesize wrong: got %d, extpected %d\n", reader->filesize, MAX_MEM);
        return false;
    }
    return true;
}


//TODO fix copying the data from reader to memory
static void mapRom(Reader *reader, Mem *memory){
    printf("mapping mem\n");
    char* temp = reader->content;
    for(int i = 0; i < MAX_MEM; ++i){
        char t = reader->content[i];
        memory->m[i] = (Byte)t;
    }
    reader->content = temp;
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
        //printf("mapping mem\n");
        //memcpy(memory->m, reader.content, MAX_MEM);
        
        freeReader(&reader);
        return true;
    } 
    printf("loop\n");
    freeReader(&reader);
    return false;
}