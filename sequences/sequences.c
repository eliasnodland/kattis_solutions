#include <stdio.h>
#include <stdlib.h>

int main() {
    const unsigned int M = 1000000007;

    int z = 0;
    int p = 1;
    int count = 0;
    char c;
    
    while (1) {
        c = getchar_unlocked();

        if (c == '?'){
            count <<= 1;
            count += z;
            z <<= 1;
            z += p;
            p <<= 1;
            
            count %= M;
            z %= M;
            p %= M;
            continue;
        }
        
        if(c == '0') {
            count += z;
            count %= M;
            continue;
        }
        
        if (c == '1') {
            z += p;
            z %= M;
            continue;
        }
        
        
        printf("%u\n", count);
        return 0;
    }
}
