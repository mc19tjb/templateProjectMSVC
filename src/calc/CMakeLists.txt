add_library(calc)
target_sources(calc
PRIVATE
calc.cpp
PUBLIC
FILE_SET HEADERS
FILES
calc.h)

install(
    TARGETS calc
    FILE_SET HEADERS
  )
