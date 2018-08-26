#include <stdio.h>

#include <owl/list.h>
#include <owl/error.h>

int main(int argc, char *argv[]) {
    td_list_t l;
    double numbers[] = {1, 2, 3 , 4, 5};

    td_list_init(&l);
    for (size_t i = 0; i < sizeof(numbers) / sizeof(double); ++i) {
        td_list_pushback(&l, &numbers[i]);
        if (td_errno != TD_ENONE)
            return 1;
    }

    double *item;
    td_list_slot_t *slot;
    td_list_slot_t *end;

    slot = td_list_begin(&l); 
    end = td_list_end(&l);

    for (; slot != end; slot = td_list_next(slot)) {
        item = (double *) td_list_item(slot);
        printf("%f\n", *item);
    }

    td_list_free(&l);
}
