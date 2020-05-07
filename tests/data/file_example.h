#ifndef EXAMPLE_H
#define EXAMPLE_H

static int sum_ints(int a, int b) {
    return a + b;
}

/**
 * Foo does foo stuff.
 * @param a: some value
 * @param bar: the name of a good bar
 */
void foo(int *out_cnt, int a, const char *bar);

#endif //EXAMPLE_H