#set(core_SRCS ADD ALL SOURCE FILES HERE)
#add_library(core ${core_SRCS})
add_executable(exe main.c)
target_link_libraries(exe core)

