#include <malloc.h>
#include <linux/limits.h>
#include <stdlib.h>

#include "filereader.h"

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


void initReader(Reader *reader){
    reader->file = NULL;
    reader->filepath = NULL;
    reader->filesize = 0;
    reader->content = NULL;
}

void freeReader(Reader *reader){
    printf("freeing filepath\n");
    free(reader->filepath);
    printf("freeing content\n");
    free(reader->content);
}

bool setFile(Reader *reader, char *filepath){
    char *path = resolvepath(filepath);
    if(path != NULL){
        reader->filepath = path;
        return true;
    } else {
        printf("%s", "path null");
        reader->filepath = NULL;
        return false;
    }
}

bool readBinaryFile(Reader *reader){
        if(reader->filepath == NULL){
        return false;
    }

    FILE *fp = fopen(reader->filepath, "rb");

    if(fp == NULL){
        printf("%s:%s", "Error opening file", reader->filepath);
        return false;
    }

    int fsize = getFileSize(fp);
    char *content = malloc(sizeof(char) * (fsize + 1));

    if(content == NULL){
        printf("ERROR: Could not allocate necessary memory.\n");
        fclose(fp);
        exit(1);
    }

    for(int i = 0; i < fsize + 1; i++){
        int c = fgetc(fp);
        if(feof(fp)){
            break;
        }
        content[i] = c;
    }

    content[fsize] = '\0';

    fclose(fp);
    
    reader->file = fp;
    reader->filesize = fsize;
    reader->content = content;

    return true;
}
//!TODO: rework reader for propper binary file support
bool readFile(Reader *reader){

    if(reader->filepath == NULL){
        return false;
    }

    FILE *fp = fopen(reader->filepath, "r");

    if(fp == NULL){
        printf("%s:%s", "Error opening file", reader->filepath);
        return false;
    }

    int fsize = getFileSize(fp);
    char *content = malloc(sizeof(char) * (fsize + 1));

    if(content == NULL){
        printf("ERROR: Could not allocate necessary memory.\n");
        fclose(fp);
        exit(1);
    }

    for(int i = 0; i < fsize + 1; i++){
        int c = fgetc(fp);
        if(feof(fp)){
            break;
        }
        content[i] = c;
    }

    content[fsize] = '\0';

    fclose(fp);
    
    reader->file = fp;
    reader->filesize = fsize;
    reader->content = content;

    return true;
}

bool readFileFromPath(Reader *reader, char *filepath){
    if(!setFile(reader, filepath)) return false;
    if(!readFile(reader)) return false;
    return true;
}
