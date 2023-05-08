#include "romloader.h"
#include "datatype.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <linux/limits.h>
#include <stdlib.h>


typedef struct {
    size_t size;
    Byte* content;
} ROM; 

const Byte ROM_SIGNATURE[] = {0x4D,0x59,0x36,0x35,0x30,0x32,0xFF,0xFF};


static int getFileSize(FILE *fp){
    int prev = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz = ftell(fp);
    fseek(fp, prev, SEEK_SET);
    return sz;
}

static char* resolvepath(char *relativepath){
    //char buf[PATH_MAX];
    char *res = realpath(relativepath, NULL);
    if(res){
        return res;
    } else {
        printf("Error: could not resolve file [%s]", relativepath);
        return NULL;
    }
}

static bool readBinFile(Mem *mem, char* filepath){
    char *path = resolvepath(filepath);
    if(path != NULL){
        FILE *fp = fopen(path, "rb");
        if(fp == NULL){
            printf("%s:%s", "Error opening file", path);
            free(path);
            return false;
        }
        
        int fsize = getFileSize(fp);
        Byte *content = malloc(sizeof(Byte) * fsize);

        if(content == NULL){
            printf("ERROR: Could not allocate necessary memory.\n");
            fclose(fp);
            free(path);
            return false;
        }

        fread(content, sizeof(Byte), fsize, fp);

        fclose(fp);
        free(path);

        mem->size = fsize;
        mem->m = content;
        return true;
    }
    free(path);
    printf("%s", "path null");
    return false;
}


bool loadrom(Mem *memory, char *filepath){
    
    if(readBinFile(memory, filepath)){
        return true;
    }
    return false;
    
}