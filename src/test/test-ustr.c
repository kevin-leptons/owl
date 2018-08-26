#include <stdio.h>

#include <owl/ustr.h>
#include <owl/error.h>

int main(int argc, char *argv[]) {
    td_ustr_t s1;
    td_ustr_t s2;
    td_ustr_t s3;

    td_ustr_init_seqc(&s1, "string 001", 10);
    td_ustr_init_seqc(&s2, "string 002", 10);

    printf("%ls\n%ls\n", s1.slots, s2.slots);

    td_ustr_ins_seqc(&s1, "A ", 0, 2);
    printf("%ls\n", s1.slots);
    td_ustr_ins_seqc(&s1, " Z", s1.size, 2);
    printf("%ls\n", s1.slots);
    td_ustr_ins_seqc(&s1, " @ ", s1.size - 1, 3);
    printf("%ls\n", s1.slots);
    td_ustr_cat_seqc(&s1, " @ ", 3);
    printf("%ls\n", s1.slots);
    td_ustr_pubc(&s1, '#');
    printf("%ls\n", s1.slots);

    td_ustr_cat(&s1, &s2);
    printf("%ls\n", s1.slots);

    td_ustr_init(&s3, 0);
    td_ustr_sub(&s3, &s1, 1, 11);
    if (td_errno)
        return 1;
    printf("'%ls'\n", s3.slots);

    td_ustr_erase(&s3, 7, 4);
    printf("'%ls'\n", s3.slots);

    td_ustr_clean(&s3);
    printf("'%ls'\n", s3.slots);

    td_ustr_upper(&s1);
    printf("'%ls'\n", s1.slots);
    td_ustr_lower(&s1);
    printf("'%ls'\n", s1.slots);

    printf("%lc\n", td_ustr_get(&s1, 3));
    td_ustr_set(&s1, 3, '#');
    printf("%lc\n", td_ustr_get(&s1, 3));

    td_ustr_free(&s1);
    td_ustr_free(&s2);
}
