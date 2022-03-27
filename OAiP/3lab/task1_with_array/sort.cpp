#include "list.h"


void swap(Call* l, Call* r)
{
    Call temp = *l;
    *l = *r;
    *r = temp;
}

void quickSort(vector<Call> data, int first, int last)
{
    int f = first, l = last;
    int middle = data[(f + l) / 2].code, temp;
    do {
        while (data[f].code < middle) f++;
        while (data[l].code > middle) l--;
        if (f <= l) {
            swap(&data[f], &data[l]);
            f++; l--;
        }
    } while (f < l);
    if (first < l) quickSort(data, first, l);
    if (f < last) quickSort(data, f, last);
}
