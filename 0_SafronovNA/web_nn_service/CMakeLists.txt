cmake_minimum_required(VERSION 3.12)
project(web_nn_service)

set(CMAKE_CXX_STANDARD 11) #do not change!

find_package(Boost REQUIRED COMPONENTS system thread)

add_executable(tcp_SERVER server/tcp_server.cpp
        tf_model/engine.cpp tf_model/engine.h
        tf_model/postprocess_utils.cpp tf_model/postprocess_utils.h
        utils/structures.h utils/config.h)
include_directories(tcp_SERVER ${Boost_INCLUDE_DIRS})
link_directories(tcp_SERVER ${Boost_LIBRARY_DIRS})
target_link_libraries(tcp_SERVER ${Boost_LIBRARIES} -lpthread -ljpeg -ltensorflow)


add_executable(tcp_CLIENT client/tcp_client.cpp
        utils/structures.h)
include_directories(tcp_CLIENT ${Boost_INCLUDE_DIRS})
link_directories(tcp_CLIENT ${Boost_LIBRARY_DIRS})
target_link_libraries(tcp_CLIENT ${Boost_LIBRARIES} -lpthread -ljpeg)


add_executable(test_image z_experiments/image/test_image.cpp)
include_directories(test_image ${Boost_INCLUDE_DIRS})
link_directories(test_image ${Boost_LIBRARY_DIRS})
target_link_libraries(test_image ${Boost_LIBRARIES} -ljpeg)


add_executable(engine tf_model/engine.cpp tf_model/engine.h
        tests/tf_engine_test/tf_engine_test.cpp
        tf_model/postprocess_utils.cpp tf_model/postprocess_utils.h
        utils/structures.h utils/config.h)
include_directories(engine ${Boost_INCLUDE_DIRS})
link_directories(engine ${Boost_LIBRARY_DIRS})
target_link_libraries(engine ${Boost_LIBRARIES} -ljpeg -ltensorflow)


add_executable(engine_test2 tf_model/engine.cpp tf_model/engine.h
        tests/tf_engine_test/postprocess_utils_test.cpp
        tf_model/postprocess_utils.cpp tf_model/postprocess_utils.h
        utils/structures.h utils/config.h)
include_directories(engine_test2 ${Boost_INCLUDE_DIRS})
link_directories(engine_test2 ${Boost_LIBRARY_DIRS})
target_link_libraries(engine_test2 ${Boost_LIBRARIES} -ljpeg -ltensorflow)
