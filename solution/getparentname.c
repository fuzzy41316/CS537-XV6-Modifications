#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
    char parentbuf[256];
    char childbuf[256];

    if (getparentname(parentbuf, childbuf, 256, 256)) printf(1, "XV6_TEST_OUTPUT Parent name: %s Child name: %s", parentbuf, childbuf);

    exit();
}
