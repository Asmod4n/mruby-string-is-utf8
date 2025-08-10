#include "simdutf.h"
#include <mruby/string_is_utf8.h>

MRB_API mrb_bool
mrb_str_is_utf8(mrb_value str)
{
  return simdutf::validate_utf8(RSTRING_PTR(str), RSTRING_LEN(str));
}

MRB_API mrb_int
mrb_str_is_utf8_raw(mrb_value str)
{
  simdutf::result res = simdutf::validate_utf8_with_errors(RSTRING_PTR(str), RSTRING_LEN(str));
  if(res.error == simdutf::error_code::SUCCESS) {
    return 0;
  } else {
    return res.count;
  }
}

static mrb_value
mrb_string_is_utf8(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(mrb_str_is_utf8(self));
}

static mrb_value
mrb_string_is_utf8_raw(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(mrb_str_is_utf8_raw(self));
}

MRB_BEGIN_DECL
void mrb_mruby_string_is_utf8_gem_init(mrb_state* mrb)
{
  mrb_define_method(mrb, mrb->string_class, "is_utf8?", mrb_string_is_utf8, MRB_ARGS_NONE());
  mrb_define_method(mrb, mrb->string_class, "is_utf8_raw", mrb_string_is_utf8_raw, MRB_ARGS_NONE());
}

void mrb_mruby_string_is_utf8_gem_final(mrb_state* mrb) {}
MRB_END_DECL