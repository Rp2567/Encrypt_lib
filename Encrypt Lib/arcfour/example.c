#include "arcfour.h"

#define F fflush(stdout)

// int main(void);

// ef20 ac12

void printbinary(int8 *input, const int16 size){
    int16 i;
    int8 *p;

    assert(size > 0); // checks if predicate function is true if not then program halts.



    for(i=size, p=input; i; i--, p++){
        if(!(i%2)) 
             printf(" ");
        printf("%.02x", *p);
    }

    printf("\n");
    return;


}

int main() {
    Arcfour *rc4;
    int16 skey, stext;
    char  *key, *from;
    int8 *encrypted, *decrypted;

    key = "potatoes";
    skey = (int16)strlen(key);
    from = "Thou shall sow as thou shall reap?";
    stext = (int16)strlen(from);

    printf("Initializing encryption...."); F;
    rc4 = rc4init((int8 *)key,skey);
    printf("done\n");

    printf("'%s'\n ->", from);
    encrypted = rc4encrypt(rc4, (int8 *)from, &stext);
    printbinary(encrypted, stext);
    rc4uninit(rc4);

    printf("Initializing encryption...."); F;
    rc4 = rc4init((int8 *)key,skey);
    printf("done\n");

    decrypted = rc4decrypt(rc4, encrypted, &stext);
    printf("  ->'%s'\n", decrypted);
    rc4uninit(rc4);

    return 0;

}