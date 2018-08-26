#include <stdio.h>
#include <string.h>

void print_help_to(FILE *out) {
    fprintf(out, "USAGE \n");
    fprintf(out, "  str-to-ascii OPTIONS string\n");
    fprintf(out, "\nOPTIONS\n");
    fprintf(out, "  -d print output in decimal format, default\n");
    fprintf(out, "  -x print ouput in hex format\n");
}

void exit_help_error(void) {
    print_help_to(stderr);
}

void print_help(void) {
        print_help_to(stdout);
}

void print_dec_str(char *str) {
    size_t str_size = strlen(str);
    for (size_t i = 0; i < str_size; ++i) {
        if (i == 0)
            printf("%i", str[i]);
        else
            printf(".%i", str[i]);
    }
    printf("\n");
}

void print_hex_str(char *str) {
    size_t str_size = strlen(str);
    for (size_t i = 0; i < str_size; ++i) {
        if (i == 0)
            printf("%X", str[i]);
        else
            printf(" %X", str[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3)
        print_help();

    if (argc == 3) {
        if (strcmp(argv[1], "-d") == 0)
            print_dec_str(argv[2]);
        else if (strcmp(argv[1], "-x") == 0)
            print_hex_str(argv[2]);
        else
            exit_help_error();
    } else if (argc == 2) {
        print_dec_str(argv[1]);
    } else {
        exit_help_error();
    }
}
