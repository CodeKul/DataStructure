//
//  Recursion.c
//  
//
//  Created by Varun on 15/02/17.
//
//

#include <stdio.h>

int fact(int a) {
    
    static int f = 1;
    
    if (a == 1) {
        return f;
    }
    f *= a;
    a--;
    fact(a);
    
    return f;
}

int main() {

    int c = fact(4);
    
    printf("Result : %d\n",c);
    
    return 0;
}

