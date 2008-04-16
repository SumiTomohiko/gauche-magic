/*
 * magic.c
 */

#include "magic.h"

static void magic_print(ScmObj obj, ScmPort *port, ScmWriteContext *ctx) 
{
    Scm_Printf(port, "#<magic>");
}

SCM_DEFINE_BUILTIN_CLASS_SIMPLE(Scm_MagicClass, magic_print);

ScmObj Scm_MagicOpen(int flags)
{
    ScmMagic* magic = SCM_NEW(ScmMagic);
    SCM_SET_CLASS(magic, SCM_CLASS_MAGIC);
    magic->magic = magic_open(flags);
    return SCM_OBJ(magic);
}

ScmObj Scm_MagicClose(ScmMagic* cookie)
{
    magic_close(cookie->magic);
    return SCM_TRUE;
}

#define RETURN_STR_OR_FALSE(s)  do { \
    if (s != NULL) { \
        return SCM_MAKE_STR_COPYING(s); \
    } \
    else { \
        return SCM_FALSE; \
    } \
} while (0)

ScmObj Scm_MagicFile(ScmMagic* cookie, const char* filename) 
{
    const char* s = magic_file(cookie->magic, filename);
    RETURN_STR_OR_FALSE(s);
}

ScmObj Scm_MagicBuffer(ScmMagic* cookie, const char* buffer, int length) 
{
    const char* s = magic_buffer(cookie->magic, buffer, length);
    RETURN_STR_OR_FALSE(s);
}

ScmObj Scm_MagicError(ScmMagic* cookie) 
{
    const char* s = magic_error(cookie->magic);
    RETURN_STR_OR_FALSE(s);
}

#undef RETURN_STR_OR_FALSE

ScmObj Scm_MagicErrno(ScmMagic* cookie) 
{
    int r = magic_errno(cookie->magic);
    return SCM_MAKE_INT(r);
}

ScmObj Scm_MagicSetFlags(ScmMagic* cookie, int flags) 
{
    int r = magic_setflags(cookie->magic, flags);
    return SCM_MAKE_INT(r);
}

ScmObj Scm_MagicCheck(ScmMagic* cookie, const char* filename) 
{
    int r = magic_check(cookie->magic, filename);
    return SCM_MAKE_INT(r);
}

ScmObj Scm_MagicCompile(ScmMagic* cookie, const char* filename) 
{
    int r = magic_compile(cookie->magic, filename);
    return SCM_MAKE_INT(r);
}

ScmObj Scm_MagicLoad(ScmMagic* cookie, const char* filename) 
{
    const char* s;
    if (filename[0] == '\0') {
        s = NULL;
    }
    else {
        s = filename;
    }
    int r = magic_load(cookie->magic, s);
    return SCM_MAKE_INT(r);
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
