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
#define SCM_MAGICP(obj) SCM_XTYPEP(obj, SCM_CLASS_MAGIC)

extern ScmObj Scm_MagicOpen(int flags);
extern ScmObj Scm_MagicClose(ScmMagic* cookie);
extern ScmObj Scm_MagicFile(ScmMagic* cookie, const char* filename);
extern ScmObj Scm_MagicBuffer(ScmMagic* cookie, const char* buffer, int length);
extern ScmObj Scm_MagicError(ScmMagic* cookie);
extern ScmObj Scm_MagicErrno(ScmMagic* cookie);
extern ScmObj Scm_MagicSetFlags(ScmMagic* cookie, int flags);
extern ScmObj Scm_MagicCheck(ScmMagic* cookie, const char* filename);
extern ScmObj Scm_MagicCompile(ScmMagic* cookie, const char* filename);
extern ScmObj Scm_MagicLoad(ScmMagic* cookie, const char* filename);

/* Epilogue */
SCM_DECL_END

#endif  /* GAUCHE_MAGIC_H */

/**
 * vim: tabstop=4 shiftwidth=4 expandtab softtabstop=4 
 */
