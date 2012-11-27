#include "libepc.h"
#include <stdlib.h>

extern void llmultiply(QWORD64 l1, QWORD64 l2, unsigned char *result);

int main()
{
    int crsr_cnt = 0;
    unsigned char result[16];//array to store the result of the multiplication

    QWORD64 L1;
    QWORD64 L2;

    L1 = 0x12FF353C;
    L2 = 0x5A2F12AF;

    ClearScreen(0x07);
    SetCursorPosition(crsr_cnt++, 0);

    llmultiply(L1,L2,result);//call assembly routine with the needed args, compiler takes care of passing params and ret val
    PutString("the result is\n");

    SetCursorPosition(crsr_cnt++, 0);
    PutUnsigned(*result,16,16);

    return 0;
}