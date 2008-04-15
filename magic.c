/*
 * magic.c
 */

#include "magic.h"

/*
 * The following function is a dummy one; replace it for
 * your C function definitions.
 */

ScmObj test_magic(void)
{
    return SCM_MAKE_STR("magic is working");
}

/*
 * Module initialization function.
 */
extern void Scm_Init_magiclib(ScmModule*);

void Scm_Init_magic(void)
{
    ScmModule *mod;

    /* Register this DSO to Gauche */
    SCM_INIT_EXTENSION(magic);

    /* Create the module if it doesn't exist yet. */
    mod = SCM_MODULE(SCM_FIND_MODULE("magic", TRUE));

    /* Register stub-generated procedures */
    Scm_Init_magiclib(mod);
}
