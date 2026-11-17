find_package(Doxygen REQUIRED)
if(NOT Doxygen_FOUND)
message(WARNING "Doxygen Not Found : 
generation will continue but no documentation will be generated")

else()
set(DOXYGEN_FILE_PATTERNS *.h *.cpp)
set(DOXYGEN_QUIET YES)
set(DOXYGEN_VERBATIM_HEADERS NO)
set(DOXYGEN_MARKDOWN_ID_STYLE GITHUB)
# You want this set explicitly, as cmake sometimes won't remove
# the full path to the file implicitly, leaving you with
# a cluttered file list.
set(DOXYGEN_STRIP_FROM_PATH ${PROJECT_SOURCE_DIR})
set(DOXYGEN_GENERATE_RTF YES)
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "${PROJECT_SOURCE_DIR}/README.md")
set(DOXYGEN_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/docs)
# set(DOXYGEN_EXCLUDE_PATTERNS */Test/* /cmake* ${PROJECT_BINARY_DIR}/* */third_party/* */exports/* */vcpkg_installed/*)

doxygen_add_docs(docs ${PROJECT_SOURCE_DIR}/src README.md LICENSE.txt CONTRIBUTING.md LICENSE.txt
WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
ALL
COMMENT Generating Doxygen Docs) 

# Install Logic
# Warning: The documentation being generated must have been built before
# installing, otherwise there may be errors during installation as 
# cmake tries to install files that don't exist.
install(DIRECTORY ${PROJECT_BINARY_DIR}/docs/html
DESTINATION docs)
install(DIRECTORY ${PROJECT_BINARY_DIR}/docs/rtf
DESTINATION docs)

endif()