#include <stdio.h>

enum {BOLD = 0b0001, ITALIC = 0b0010, UNDERLINE = 0b0100};


union {
    struct
    {
        unsigned char isBold : 1;  // :1 - кол-во бит которые поле занимет в структуре
        unsigned char isItalic : 1;
        unsigned char isUnderline : 1;
    };
    
    char flag;
}text_flag;




int print(char, char*);

int print(char a, char *operation){
    printf(operation);
    for (int i = 0; i < 8; i++) {
        printf("%c", (a & 0x80) ? '1' : '0');
        a <<= 1;
    }
     printf("\n");
     return 0;
}

int main(void){

    char a = 0b1111;
    print(a, "                          a = ");

    print(~a, "                          ~a =");

    print(a >> 2, "                     a >> 2 = ");
    print(a << 2, "                     a << 2 = ");

    print(a & 0b01, "                   a & 0b01 = ");
    print(a | 0b01, "                   a | 0b01 = ");

    print(a | 1 << 6  | 1 << 5 , "       a | 1 << 6  | 1 << 5 = ");
    print(a  & ~(1 << 3 | 1 << 0), "    a  & ~(1 << 3 | 1 << 0) = ");

    //a = a & ~1 << 3;
    if (a & (1 << 3)){
        printf("\nTrue");
    }   
    else{
        printf("\nFalse");
    }

    printf("\n\n");
    char text = BOLD | UNDERLINE;
    print(text, "    text = BOLD | UNDERLINE = ");
    text &=  ~UNDERLINE;
    print(text, "                text = BOLD = ");
    text |= ITALIC;
    print(text, "       text = BOLD | ITALIC = ");
    if (text & BOLD){
        printf("\nText BOLD");
    }
    if (!(text & UNDERLINE)){
        printf("\nText not UNDERLINE");
    }

    text_flag.isBold = 1;
    text_flag.isItalic = 1;

    if (text_flag.isBold){
        printf("\nText_flag isBold");
    }
    text_flag.isBold = 0;
    if (!text_flag.isBold){
        printf("\nText_flag not Bold");
    }
    printf("\n");
    text_flag.flag = BOLD | UNDERLINE | ITALIC;
    print(text_flag.flag, "              text_flag.flag =");
    text_flag.flag &= ~UNDERLINE;
    print(text_flag.flag, "text_flag.flag not underline =");
    text_flag.isItalic = 0;
    print(text_flag.flag, "    text_flag.flag only Bold =");
    text_flag.isUnderline = 1;
    text_flag.flag |= ITALIC;
    if (text_flag.flag & (BOLD | ITALIC | UNDERLINE)){
        if (text_flag.isBold && text_flag.isItalic && text_flag.isUnderline){
            print(text_flag.flag, "              text_flag.flag =");
        }
    }

    return 0;
}