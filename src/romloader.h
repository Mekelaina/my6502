#ifndef MY6502_ROMLOADER
#define MY6502_ROMLOADER

#include "memory.h"
#include "datatype.h"
#include <stdbool.h>

#define SIGNATURE_SIZE 8

/* loads a given rom file into the provided memory struct.
* it will allocate memory itself so just pass an unitiniallized
* struct to hold the value. if successful returns true, else false.
* if false, then mem is still uninitialized.
*/
bool loadrom(Mem *memory, char *filepath);

#endif //MY6502_ROMLOADER