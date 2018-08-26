#ifndef TD_ERROR_H
#define TD_ERROR_H

#include <stdlib.h>
#include <errno.h>

extern size_t td_errno;

#define TD_ENONE 0
#define TD_EEND 256
#define TD_EINDEX 257
#define TD_EINVAL 258

#endif
