# Writes build_info.h with the commit the exe is built from and its date, so the logs and the
# frame rate overlay can name the build.
# Run at every build (see CMakeLists.txt); the file is only rewritten when the commit changes.
execute_process(COMMAND git rev-parse --short HEAD
    WORKING_DIRECTORY ${SOURCE_DIR} OUTPUT_VARIABLE commit OUTPUT_STRIP_TRAILING_WHITESPACE ERROR_QUIET)
execute_process(COMMAND git diff --quiet --ignore-submodules HEAD
    WORKING_DIRECTORY ${SOURCE_DIR} RESULT_VARIABLE dirty OUTPUT_QUIET ERROR_QUIET)
execute_process(COMMAND git log -1 --format=%cs
    WORKING_DIRECTORY ${SOURCE_DIR} OUTPUT_VARIABLE commit_date OUTPUT_STRIP_TRAILING_WHITESPACE ERROR_QUIET)
if (commit STREQUAL "")
    set(commit "unknown")
endif()
if (dirty EQUAL 1)
    set(commit "${commit} with local changes")
endif()
set(content "#define TOOIE_GIT_COMMIT \"${commit}\"\n#define TOOIE_GIT_DATE \"${commit_date}\"\n")
if (EXISTS ${OUT})
    file(READ ${OUT} old)
endif()
if (NOT old STREQUAL content)
    file(WRITE ${OUT} "${content}")
endif()
