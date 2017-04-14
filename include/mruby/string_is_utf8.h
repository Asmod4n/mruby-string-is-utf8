#ifndef MRB_STRING_IS_UTF8_H
#define MRB_STRING_IS_UTF8_H

#include <mruby.h>
#include <mruby/string.h>

MRB_BEGIN_DECL

MRB_API mrb_bool mrb_str_is_utf8(mrb_value str);
MRB_API mrb_int mrb_str_is_utf8_raw(mrb_value str);

MRB_END_DECL

#endif
