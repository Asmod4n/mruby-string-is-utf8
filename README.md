# mruby-string-is-utf8

Checks if a string is valid utf8

Ruby Example
============
```ruby

"hallo".is_utf? # returns true or false

"hallo".is_utf8_raw # returns 0 if true or the position where a offending char is found
```

C Example
=========
```c
str = mrb_str_new_lit(mrb, "hallo");

mrb_string_is_utf8(str); // returns TRUE or FALSE

mrb_string_is_utf8_raw(str); // returns 0 if true or the position where a offending char is found
```
