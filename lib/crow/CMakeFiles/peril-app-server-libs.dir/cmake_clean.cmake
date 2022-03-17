file(REMOVE_RECURSE
  "libperil-app-server-libs.a"
  "libperil-app-server-libs.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/peril-app-server-libs.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
