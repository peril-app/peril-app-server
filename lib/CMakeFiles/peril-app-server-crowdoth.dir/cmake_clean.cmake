file(REMOVE_RECURSE
  "libperil-app-server-crowdoth.a"
  "libperil-app-server-crowdoth.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/peril-app-server-crowdoth.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
