#include "money.h"
#include <stdio.h>
#include <errno.h>
#include <limits.h>

/* only main should be in this file, to make all other functions in
   the prograble testable by Check.  in order to test main(), use a
   whole program testing framework like Autotest.
*/

int
main (int argc, char** argv)
{
  if (argc != 3) {
    printf("Usage: money cur amount\n");
    return 1;
  }

  char *end = argv[2];
  errno = 0;
  long amt = strtol(argv[2], &end, 10);
  if (errno || *end) {
    printf("Could not parse %s\n", argv[2]);
    return 2;
  }
  if (amt > INT_MAX || amt < INT_MIN) {
    printf("Amount %ld too large for int\n", amt);
    return 3;
  }

  Money *m = money_create((int) amt, argv[1]);
  printf("%s %d\n", money_currency(m), money_amount(m));
  money_free(m);

  return 0;
}
