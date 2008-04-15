/*
 * magic.h
 */

/* Prologue */
#ifndef GAUCHE_MAGIC_H
#define GAUCHE_MAGIC_H

#include <gauche.h>
#include <gauche/extend.h>
#include <magic.h>

SCM_DECL_BEGIN

typedef struct ScmMagicRec {
    SCM_HEADER;
    magic_t magic;
} ScmMagic;

SCM_CLASS_DECL(Scm_MagicClass);
#define SCM_CLASS_MAGIC (&Scm_MagicClass)
#define SCM_MAGIC(obj)  ((ScmMagic*)obj)

extern ScmObj test_magic(void);
extern ScmObj Scm_OpenMagic();

/* Epilogue */
SCM_DECL_END

#endif  /* GAUCHE_MAGIC_H */

/**
 * vim: tabstop=4 shiftwidth=4 expandtab softtabstop=4 
 */
