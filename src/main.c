#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "globals.h"
#include "utils.h"
#include "assemble.h"
#include "label.h"
#include "stdint.h"
#include "macro.h"
#include "mos-interface.h"

int main(int argc, char *argv[])
{
    if(argc < 2){
        printf("Usage: asm <filename> [-l]\n\r");
        return 0;
    }

    prepare_filenames(argv[1]);
    if(!openfiles()) return 0;

    if((argc == 3) && (strcmp(argv[2], "-l") == 0)) consolelist_enabled = true;

    // Init tables
    initGlobalLabelTable();
    initLocalLabelTable();
    initAnonymousLabelTable();
    initMacros();
    
    // Assemble input to output
    assemble();
    if(global_errors) {
        mos_del(filename[FILE_OUTPUT]);
        printf("Error in input\r\n");
    }
    else printf("Done\r\n");
 
    closeAllFiles();   
    return 0;
}