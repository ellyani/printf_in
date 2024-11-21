#include "ft_printf.h"

int print_char(int c){
    return (write(1, &c ,1));
}
int print_str(char *str){
    int count;
    count = 0;
    while (*str){
        print_char((int )*str);
        ++count;
        ++str;
    }
    return (count);
}
int print_digit(long n,int base){

    int count ;
    char *symbols = "0123456789abcdef";
    if (n < 0)
    {
        write(1 ,"-",1);
        return print_digit(-n, base) + 1;
    }
    else if(n < base){
        return print_char(symbols[n]);
    }
    else {
        count = print_digit(n / base, base);
        return (count + print_digit(n % base, base));
    } 

}
int print_format(char specifier , va_list ap){

    int count ;
    count = 0;
    if(specifier == 'c')
        count += print_char(va_arg(ap, int));
    else if (specifier == 's')
        count += print_str(va_arg(ap, char *));
    else if (specifier == 'd')
        count += print_digit( (long) va_arg(ap , int), 10);
    else if (specifier == 'x')
        count += print_digit( (long)va_arg(ap , unsigned int), 16);
    else 
        write(1, &specifier, 1);
    return  (count);    

}

int ft_printf(const char *format , ...){
    va_list ap;
    int     count;

    va_start (ap ,format);
    count = 0 ;
    while (*format)
    {
        if (*format  == '%')
        
            count +=print_format(*(++format) , ap);
        else 
            count += write(1,&format ,1);
    ++format;
    }
    va_end(ap);
    return (count);

}
int main(){
    int count ;
    count = ft_printf("hello %s\n", "jhon");
    ft_printf("The char written are %d\n", count);

    // count = ft_printf("%d\n",42);
    // ft_printf("the chars written are %d\n" , count);

    //  count = ft_printf("%x\n",10);
    // ft_printf("the chars written are %x\n" , count);

    // count = ft_printf("Char-> %c\n", 'a');
	// ft_printf("\n%dchars\n", count);

    // count =ft_printf("Nbr-> %d\n", -42);
	// ft_printf("\n%d chars\n", count);

    // count = ft_printf("Hex-> %x\n", -1);
	// ft_printf("\n%d chars\n", count);

    // ft_printf("\n\n");
	// puts("REAL PRINTF");
}



