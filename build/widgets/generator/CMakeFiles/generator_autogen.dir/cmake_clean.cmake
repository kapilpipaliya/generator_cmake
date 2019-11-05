file(REMOVE_RECURSE
  "CMakeFiles/generator_autogen"
  "controller1.cc"
  "controller1.h"
  "controller_empty.cc"
  "controller_empty.h"
  "dgraph_schema.cc"
  "dgraph_schema.h"
  "generator_autogen/mocs_compilation.cpp"
  "js_class.cc"
  "js_class.h"
  "service_cc.cc"
  "service_cc.h"
  "service_h.cc"
  "service_h.h"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/generator_autogen.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
