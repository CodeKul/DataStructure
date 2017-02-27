//
//  StructDemo.c
//  
//
//  Created by Varun on 17/02/17.
//
//

#include <stdio.h>

struct myStruct {
    
    int a;      // 4 bytes
    float f;    // 4 bytes
    char c;     // 1 byte
};              // 4 + 4 + 1 = 9 bytes

union myUnion {
    int a;      // 4 bytes
    float f;    // 4 bytes
    char c;     // 1 byte
};

void display(struct myStruct s1) {
    
    printf("a : %d\nf : %f\nc : %c\n",s1.a,s1.f,s1.c);
    return;
}

struct myStruct setData(int a, float f, char c) {
    
    struct myStruct s1;
    
    s1.a = a;
    s1.f = f;
    s1.c = c;
    
    return s1;
}


int main() {
    
    struct myStruct s;
    
    printf("size : %lu\n", sizeof(s));
    s = setData(12, 3.16, 'P');
    
//    printf("struct : %p\ns.a : %p\n",&s, &(s.a));
    
//    printf("a : %d\nf : %f\nc : %c\n",s1.a,s1.f,s1.c);
    
    
//    s.a = 33;
//    s.f = 10.78;
//    
//    printf("a : %f\n",s.f);
//    
//    s.c = 'd';
//    
//    printf("a : %c\n",s.c);
//    
//    printf("a : %f\n",s.f);
//
//    printf("a : %d\n",s.a);

    display(s);
    
    return 0;
}

