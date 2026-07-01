typedef struct symbol {
    void * function;
    char * name;
} symbol;

void trace(const symbol *symbols,int n,const char *msg);