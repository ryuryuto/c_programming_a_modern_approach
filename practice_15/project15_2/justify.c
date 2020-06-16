/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* justify.c (Chapter 15, page 363) */
/* Formats a file of text */

#include <string.h>
#include "line.h"
#include "word.h"


int main(void) {
    char word[MAX_WORD_LEN + 2];
    int word_len;

    clear_line();
    for (;;) {
        word_len = read_word(word);
        if (word_len == 0) {
            flush_line();
            return 0;
        }

        if (word_len > space_remaining()) {
            write_line();
            clear_line();
        }
        add_word(word);
    }
}