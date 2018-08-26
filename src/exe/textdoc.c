#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <textdoc/builder.h>

void print_help_to(FILE *out) {
        fprintf(out, "USAGE\n");
        fprintf(out, "  textdoc COMMAND src dest\n");

        fprintf(out, "\nCOMMANDS\n");
        fprintf(out, "  html    Build HTML document\n");
        fprintf(out, "  pdf     Build PDF document\n");

        fprintf(out, "\nARGUMENTS\n");
        fprintf(out, "  src     Path to .textdoc file\n");
        fprintf(out, "  dest    Path to output file or directory\n");
}

void exit_help_error() {
        print_help_to(stderr);
        exit(1);
}

void print_help() {
        print_help_to(stdout);
}

int main(int argc, char *argv[]) {
        if (argc != 4)
                exit_help_error();

        if (strcmp(argv[1], "html") == 0)
                td_build_html(argv[2], argv[3]);
        else if (strcmp(argv[1], "pdf") == 0)
                td_build_pdf(argv[2], argv[3]);
        else
                exit_help_error();

        return 0;
}
