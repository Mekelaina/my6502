#ifndef MY6502_FILEREADER
#define MY6502_FILEREADER

#include <stdio.h>
#include <stdbool.h>
#include "datatype.h"

typedef struct {
    FILE *file;
    char *filepath;
    int filesize;
    char *content;
} Reader;

void initReader(Reader *reader);
void freeReader(Reader *reader);
bool setFile(Reader *reader, char *filepath);
bool readFile(Reader *reader);
bool readBinaryFile(Reader *reader);
bool readFileFromPath(Reader *reader, char *filepath);

#endif //MY6502_FILEREADER