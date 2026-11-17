add_executable(main)
target_sources(main
PRIVATE
main.cpp
)
target_link_libraries(main
PUBLIC
calc)
install(
    TARGETS main
  )
add_subdirectory(calc)