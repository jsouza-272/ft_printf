/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsouza <jsouza@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:34:02 by jsouza            #+#    #+#             */
/*   Updated: 2025/11/11 14:22:43 by jsouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

#define OK "\033[38;2;0;255;0m✓\033[0m"
#define KO "\033[38;2;255;0;0m✗\033[0m"


/**fazer testes sem as flags
 * fclose
 * freopen /dev/tty <-- terminal em processo
 * teste com uma %
*/
void test_char()
{
    char c = 'c';
    
    printf("\n\033[38;2;0;179;255m╔════════════════════════════════════════════════════╗\033[0m\n");
	printf("\033[38;2;0;179;255m║                   TESTE CHAR                       ║\033[0m\n");
	printf("\033[38;2;0;179;255m╚════════════════════════════════════════════════════╝\033[0m\n");

    int o=0, f=0, i=0;
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);

    o = printf("c");
    printf("\t");
    fflush(stdout);
    f = ft_printf("c");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);

    o = printf("%c", c);
    printf("\t");
    fflush(stdout);
    f = ft_printf("%c", c);
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);

    o = printf("%c", '\033');
    printf("\t");
    fflush(stdout);
    f = ft_printf("%c", '\033');
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);

    c = '\n';
    o = printf("%c", c);
    printf("\t");
    fflush(stdout);
    f = ft_printf("%c", c);
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);

    c = 'A';
    o = printf("%c %c %c", c, c, c);
    printf("\t");
    fflush(stdout);
    f = ft_printf("%c %c %c", c, c, c);
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);

    c = 'A';
    printf("Close\n");
    fclose (stdout);
    o = printf("%c %c %c", c, c, c);
    printf("\t");
    fflush(stderr);
    f = ft_printf("%c %c %c", c, c, c);
    fprintf(stderr,"\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);
    stdout = fopen("/dev/tty", "w");
}

void test_string()
{
    char *s= NULL;

    printf("\n\033[38;2;0;179;255m╔════════════════════════════════════════════════════╗\033[0m\n");
	printf("\033[38;2;0;179;255m║                   TESTE STRINGS                    ║\033[0m\n");
	printf("\033[38;2;0;179;255m╚════════════════════════════════════════════════════╝\033[0m\n");

    int o=0, f=0, i=0;
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);

    o = printf("Hello World");
    printf("\t");
    fflush(stdout);
    f = ft_printf("Hello World");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);

    o = printf("%s","Hello World");
    printf("\t");
    fflush(stdout);
    f = ft_printf("%s", "Hello World");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);
    
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);

    o = printf("ola%s", s);
    printf("\t");
    fflush(stdout);
    f = ft_printf("ola%s", s);
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);

    o = printf("%s", "");
    printf("\t");
    fflush(stdout);
    f = ft_printf("%s", "");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);

    o = printf("%s", "Hello mundo caravan com K24 e zf8 essa linha e muito grande para fazer qualquer coisa");
    printf("\t");
    fflush(stdout);
    f = ft_printf("%s", "Hello mundo caravan com K24 e zf8 essa linha e muito grande para fazer qualquer coisa");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);

    o = printf("%s%s%s%s", s, "oi", "olas", "zero");
    printf("\t");
    fflush(stdout);
    f = ft_printf("%s%s%s%s", s, "oi", "olas", "zero");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);

    o = printf("%%%");
    printf("\t");
    fflush(stdout);
    f = ft_printf("%%%");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);
/*
    UNDEFINED
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);
    
    s = "hello";
    printf("Close\n");
    fclose (stdout);
    o = printf("%s %s %s", s, s, s);
    printf("\t");
    fflush(stderr);
    f = ft_printf("%s %s %s", s, s, s);
    fprintf(stderr,"\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);
    stdout = fopen("/dev/tty", "w"); 

    TEST SEM AS FLAGS
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);

    o = printf("%s %yssring", "Hello mundo caravan com K24 ");
    printf("\t");
    fflush(stdout);
    f = ft_printf("%s %yssring", "Hello mundo caravan com K24 ");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO); */
}

void test_pointer()
{
    printf("\n\033[38;2;0;179;255m╔════════════════════════════════════════════════════╗\033[0m\n");
	printf("\033[38;2;0;179;255m║                   TESTE POINTER                    ║\033[0m\n");
	printf("\033[38;2;0;179;255m╚════════════════════════════════════════════════════╝\033[0m\n");
}

void test_decimal()
{
    printf("\n\033[38;2;0;179;255m╔════════════════════════════════════════════════════╗\033[0m\n");
	printf("\033[38;2;0;179;255m║                   TESTE DECIMAL                    ║\033[0m\n");
	printf("\033[38;2;0;179;255m╚════════════════════════════════════════════════════╝\033[0m\n");
}

void test_integer()
{
    printf("\n\033[38;2;0;179;255m╔════════════════════════════════════════════════════╗\033[0m\n");
	printf("\033[38;2;0;179;255m║                   TESTE INTEGER                    ║\033[0m\n");
	printf("\033[38;2;0;179;255m╚════════════════════════════════════════════════════╝\033[0m\n");
}

void test_unsigned()
{
    printf("\n\033[38;2;0;179;255m╔════════════════════════════════════════════════════╗\033[0m\n");
	printf("\033[38;2;0;179;255m║                   TESTE UNSIGNED                   ║\033[0m\n");
	printf("\033[38;2;0;179;255m╚════════════════════════════════════════════════════╝\033[0m\n");
}

void test_hexa()
{
    printf("\n\033[38;2;0;179;255m╔════════════════════════════════════════════════════╗\033[0m\n");
	printf("\033[38;2;0;179;255m║                   TESTE HEXA                       ║\033[0m\n");
	printf("\033[38;2;0;179;255m╚════════════════════════════════════════════════════╝\033[0m\n");
}

void test_uperhexa()
{
    printf("\n\033[38;2;0;179;255m╔════════════════════════════════════════════════════╗\033[0m\n");
	printf("\033[38;2;0;179;255m║                   TESTE UPERHEXA                   ║\033[0m\n");
	printf("\033[38;2;0;179;255m╚════════════════════════════════════════════════════╝\033[0m\n");
}

void test_percent()
{
    printf("\n\033[38;2;0;179;255m╔════════════════════════════════════════════════════╗\033[0m\n");
	printf("\033[38;2;0;179;255m║                   TESTE PERCENT                    ║\033[0m\n");
	printf("\033[38;2;0;179;255m╚════════════════════════════════════════════════════╝\033[0m\n");
}

int main ()
{
/*     int i = 1;
    int o = 0, f=0;
    char *s = "ola";
    char *str = "hello";
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);
    printf("Original com \033[1;38;2;0;255;0m%%s\033[0m:\t%s\n", "Hello World");
    ft_printf("Copia com \033[1;38;2;0;255;0m%%s\033[0m:\t\t%s\n", "Hello World");
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);
    printf("Original com \033[1;38;2;0;255;0m%%s NULL\033[0m:\t%s\n", s);
    ft_printf("Copia com \033[1;38;2;0;255;0m%%s NULL\033[0m:\t%s\n", s);
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);
    printf("Original com \033[1;38;2;0;255;0m%%p \033[0m:\t%p\n", str);
    ft_printf("Copia com \033[1;38;2;0;255;0m%%p \033[0m:\t\t%p\n", str);
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);
    printf("Original com \033[1;38;2;0;255;0m%%p NULL\033[0m:\t%p\n", NULL);
    ft_printf("Copia com \033[1;38;2;0;255;0m%%p NULL\033[0m:\t%p\n", NULL);
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);
    printf("Original com \033[1;38;2;0;255;0m%%c\033[0m:\t%c\n", 'H');
    ft_printf("Copia com \033[1;38;2;0;255;0m%%c\033[0m:\t\t%c\n", 'H');
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);
    printf("Original com \033[1;38;2;0;255;0m%%d\033[0m:\t%d\n", -10);
    ft_printf("Copia com \033[1;38;2;0;255;0m%%d\033[0m:\t\t%d\n", -10);
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);
    printf("Original com \033[1;38;2;0;255;0m%%x\033[0m:\t%x\n", -10);
    ft_printf("Copia com \033[1;38;2;0;255;0m%%x\033[0m:\t\t%x\n", -10);
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);
    printf("Original com \033[1;38;2;0;255;0m%%X\033[0m:\t%X\n", -10);
    ft_printf("Copia com \033[1;38;2;0;255;0m%%X\033[0m:\t\t%X\n", -10);
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);
    printf("Original com \033[1;38;2;0;255;0m%%u\033[0m:\t%u\n", -10);
    ft_printf("Copia com \033[1;38;2;0;255;0m%%u\033[0m:\t\t%u\n", -10);
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);
    printf("Retorno do Original:\t%d\n", printf("%%%%%%\n"));
    ft_printf("Retorno da Copia:\t%d\n", ft_printf("%%%%%%\n"));
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);
    printf("Undefined Behavior\n");
    printf("Retorno do Original:\t%d\n", printf("%%\n"));
    ft_printf("Retorno da Copia:\t%d\n", ft_printf("%%\n"));
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);
    printf("Retorno do Original:\t%d\n", printf("%d\n", -12345));
    ft_printf("Retorno da Copia:\t%d\n", ft_printf("%d\n", -12345));
    printf("\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);
    printf("Com terminal fechado usando \033[1;38;2;255;0;0mfclose\033[0m\n");
    fclose(stdout);
    fprintf(stderr, "Original:\t%d\n", printf("isso deve retornar -1"));
    fprintf(stderr, "Copia:\t\t%d\n", ft_printf("isso deve retornar -1"));
    fprintf(stderr, "\n\n\033[1;38;2;51;153;255m===================TEST%d===================\033[0m\n\n", i++);
    fprintf(stderr, "Com terminal fechado usando \033[1;38;2;255;0;0mfclose\033[0m\n");
    fprintf(stderr, "Original:\t%d\n", printf("isso deve retornar -1"));
    fprintf(stderr, "Copia:\t\t%d\n", ft_printf("%s", "isso deve retornar -1"));


    printf("\n%i\n", printf(" %p %p %p", s,&s,NULL));
    printf("\n%i", ft_printf(" %p %p %p", s,&s,NULL));
    
    stdout = fopen("/dev/tty", "w"); */
    
    test_char();
    test_string();
    test_pointer();
    test_decimal();
    test_integer();
    test_unsigned();
    test_hexa();
    test_uperhexa();
    test_percent();
    
    
}
