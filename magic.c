/*
 * magic.c
 */

#include "magic.h"

static void 
magic_print(ScmObj obj, ScmPort *port, ScmWriteContext *ctx) 
{
    ScmMagic* magic = SCM_MAGIC(obj);
    Scm_Printf(port, "#<magic>");
}

SCM_DEFINE_BUILTIN_CLASS_SIMPLE(Scm_MagicClass, magic_print);

ScmObj Scm_OpenMagic()
{
    ScmMagic* magic = SCM_NEW(ScmMagic);
    SCM_SET_CLASS(magic, SCM_CLASS_MAGIC);
    magic->magic = magic_open(MAGIC_NONE);
    return SCM_OBJ(magic);
}

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

/**
 * vim: tabstop=4 shiftwidth=4 expandtab softtabstop=4
 */
