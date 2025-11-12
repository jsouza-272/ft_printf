/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsouza <jsouza@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:34:02 by jsouza            #+#    #+#             */
/*   Updated: 2025/11/12 09:43:51 by jsouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

#define CREST "\033[0m"
#define OK "\033[38;2;0;255;0m✓"CREST""
#define KO "\033[38;2;255;0;0m✗"CREST""
#define CTST "\033[1;38;2;51;153;255m"
#define HEAD "\033[38;2;0;179;255m"
#define RED "\033[38;2;255;0;0m"


/**fazer testes sem as flags
 * fclose
 * freopen /dev/tty <-- terminal em processo
 * teste com uma %
*/
void test_char()
{
    char c = 'c';
    
    printf("\n"HEAD"╔════════════════════════════════════════════════════╗"CREST"\n");
	printf(""HEAD"║                   TESTE CHAR                       ║"CREST"\n");
	printf(""HEAD"╚════════════════════════════════════════════════════╝"CREST"\n");

    int o=0, f=0, i=1;
    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    o = printf("c");
    printf("\t");
    fflush(stdout);
    f = ft_printf("c");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    o = printf("%c", c);
    printf("\t");
    fflush(stdout);
    f = ft_printf("%c", c);
    printf("\n\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    o = printf("%c", '\033');
    printf("\t");
    fflush(stdout);
    f = ft_printf("%c", '\033');
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    c = '\n';
    o = printf("%c", c);
    printf("\t");
    fflush(stdout);
    f = ft_printf("%c", c);
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    c = 'A';
    o = printf("%c %c %c", c, c, c);
    printf("\t");
    fflush(stdout);
    f = ft_printf("%c %c %c", c, c, c);
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    c = 'A';
    printf(RED"Close"CREST"\n");
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

    printf("\n"HEAD"╔════════════════════════════════════════════════════╗"CREST"\n");
	printf(""HEAD"║                   TESTE STRINGS                    ║"CREST"\n");
	printf(""HEAD"╚════════════════════════════════════════════════════╝"CREST"\n");

    int o=0, f=0, i=1;
    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    o = printf("Hello World");
    printf("\t");
    fflush(stdout);
    f = ft_printf("Hello World");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    o = printf("%s","Hello World");
    printf("\t");
    fflush(stdout);
    f = ft_printf("%s", "Hello World");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);
    
    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    o = printf("ola%s", s);
    printf("\t");
    fflush(stdout);
    f = ft_printf("ola%s", s);
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    o = printf("%s", "");
    printf("\t");
    fflush(stdout);
    f = ft_printf("%s", "");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    o = printf("%s", "Hello mundo caravan com K24 e zf8 essa linha e muito grande para fazer qualquer coisa");
    printf("\t");
    fflush(stdout);
    f = ft_printf("%s", "Hello mundo caravan com K24 e zf8 essa linha e muito grande para fazer qualquer coisa");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    o = printf("%s%s%s%s", s, "oi", "olas", "zero");
    printf("\t");
    fflush(stdout);
    f = ft_printf("%s%s%s%s", s, "oi", "olas", "zero");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);
/*
    NAO SEI SE TESTA
    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    o = printf("%%%");
    printf("\t");
    fflush(stdout);
    f = ft_printf("%%%");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    UNDEFINED
    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);
    
    s = "hello";
    printf(RED"Close"CREST"\n");
    fclose (stdout);
    o = printf("%s %s %s", s, s, s);
    printf("\t");
    fflush(stderr);
    f = ft_printf("%s %s %s", s, s, s);
    fprintf(stderr,"\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);
    stdout = fopen("/dev/tty", "w"); 

    TEST SEM AS FLAGS
    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    o = printf("%s %yssring", "Hello mundo caravan com K24 ");
    printf("\t");
    fflush(stdout);
    f = ft_printf("%s %yssring", "Hello mundo caravan com K24 ");
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO); */
}

void test_pointer()
{
    char *s = NULL;
    printf("\n"HEAD"╔════════════════════════════════════════════════════╗"CREST"\n");
	printf(""HEAD"║                   TESTE POINTER                    ║"CREST"\n");
	printf(""HEAD"╚════════════════════════════════════════════════════╝"CREST"\n");

    int o=0, f=0, i=1;
    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    o = printf("%p", s);
    printf("\t");
    fflush(stdout);
    f = ft_printf("%p", s);
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    o = printf("%p", NULL);
    printf("\t");
    fflush(stdout);
    f = ft_printf("%p", NULL);
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    s = "ola";
    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    o = printf("%p", s);
    printf("\t");
    fflush(stdout);
    f = ft_printf("%p", s);
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    int l[] = {10, 20, 30};
    o = printf("%p", &l);
    printf("\t");
    fflush(stdout);
    f = ft_printf("%p", &l);
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    o = printf("%p%p%p", s, &i, NULL);
    printf("\t");
    fflush(stdout);
    f = ft_printf("%p%p%p", s, &i, NULL);
    printf("\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);

    printf("\n\n"CTST" ===================TEST%d==================="CREST"\n\n", i++);

    printf(RED"Close"CREST"\n");
    fclose(stdout);
    o = printf("%p", s);
    printf("\t");
    fflush(stdout);
    f = ft_printf("%p", s);
    fprintf(stderr, "\noriginal:%d\tCopia:%d\t%s\n", o, f, o == f ? OK : KO);
    stdout = fopen("/dev/tty", "w");
}

void test_decimal()
{
    printf("\n"HEAD"╔════════════════════════════════════════════════════╗"CREST"\n");
	printf(""HEAD"║                   TESTE DECIMAL                    ║"CREST"\n");
	printf(""HEAD"╚════════════════════════════════════════════════════╝"CREST"\n");
}

void test_integer()
{
    printf("\n"HEAD"╔════════════════════════════════════════════════════╗"CREST"\n");
	printf(""HEAD"║                   TESTE INTEGER                    ║"CREST"\n");
	printf(""HEAD"╚════════════════════════════════════════════════════╝"CREST"\n");
}

void test_unsigned()
{
    printf("\n"HEAD"╔════════════════════════════════════════════════════╗"CREST"\n");
	printf(""HEAD"║                   TESTE UNSIGNED                   ║"CREST"\n");
	printf(""HEAD"╚════════════════════════════════════════════════════╝"CREST"\n");
}

void test_hexa()
{
    printf("\n"HEAD"╔════════════════════════════════════════════════════╗"CREST"\n");
	printf(""HEAD"║                   TESTE HEXA                       ║"CREST"\n");
	printf(""HEAD"╚════════════════════════════════════════════════════╝"CREST"\n");
}

void test_uperhexa()
{
    printf("\n"HEAD"╔════════════════════════════════════════════════════╗"CREST"\n");
	printf(""HEAD"║                   TESTE UPERHEXA                   ║"CREST"\n");
	printf(""HEAD"╚════════════════════════════════════════════════════╝"CREST"\n");
}

void test_percent()
{
    printf("\n"HEAD"╔════════════════════════════════════════════════════╗"CREST"\n");
	printf(""HEAD"║                   TESTE PERCENT                    ║"CREST"\n");
	printf(""HEAD"╚════════════════════════════════════════════════════╝"CREST"\n");
}

int main ()
{    
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
