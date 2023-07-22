#include "funchook.h"

int hook(void *rva, void *hook, void **org)
{
    *org = rva;
    funchook_t *funchook = funchook_create();
    int rv;
    // Prepare hooking.
    rv = funchook_prepare(funchook, org, hook);
    if (rv != 0)
    {
        return rv;
    }
    // Install hooks.
    // The first 5-byte code of org are changed respectively.
    rv = funchook_install(funchook, 0);
    if (rv != 0)
    {
        return rv;
    }
    return 0;
}
// int unhook(void *hook, void **org) {
//
// }