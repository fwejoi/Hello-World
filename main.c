#include <stdio.h>
#include "Hashtable.h"

void init_table() {
    for (int i = 0; i < MAX_BUCKETS; i++) {
        table[i] = NULL;
    }
}

int main() {
    init_table();
    file_read_ht();
    file_write_ht();
    search_ht();
    
    return 0;
}
