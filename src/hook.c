#include "funchook.h"

int hook(void *rva, void *hook, void **org, funchook_t **funchook) {
    *org = rva;
    funchook_t *instance = funchook_create();
    int rv;
    rv = funchook_prepare(instance, org, hook);
    if (rv != 0) {
        funchook_destroy(instance);
        return rv;
    }
    rv = funchook_install(instance, 0);
    if (rv != 0) {
        funchook_destroy(instance);
        return rv;
    }
    *funchook = instance;
    return 0;
}

int unhook(void **org, funchook_t **funchook) {
    int rv;
    rv = funchook_uninstall(*funchook, 0);
    if (rv != 0) {
        return rv;
    }
    funchook_destroy(*funchook);
    *funchook = 0;
    *org = hook;
    return 0;
}
