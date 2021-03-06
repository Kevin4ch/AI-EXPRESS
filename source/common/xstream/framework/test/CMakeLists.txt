include_directories(
  ${PROJECT_SOURCE_DIR}/include
  include
  include/method
  include/hobotxstream
)
# x86 architecture
if (${X86_ARCH})
  if (${X86_CENTOS})
    include_directories(
      ${XSTREAM_CURRENT_DIR}/framework/third_party/x86/centos/hobotlog/include/
      ${XSTREAM_CURRENT_DIR}/framework/third_party/x86/centos/jsoncpp/include/
      ${XSTREAM_CURRENT_DIR}/framework/third_party/x86/centos/gtest/include/
      ${XSTREAM_CURRENT_DIR}/vision_type/include/
      ${RELEASE_ROOT_DIR}/deps/opencv/include/
    )
    link_directories(
      ${XSTREAM_CURRENT_DIR}/framework/third_party/x86/centos/hobotlog/lib
      ${XSTREAM_CURRENT_DIR}/framework/third_party/x86/centos/jsoncpp/lib/
      ${XSTREAM_CURRENT_DIR}/framework/third_party/x86/centos/gtest/lib/
    )
  else ()
    include_directories(
      ${XSTREAM_CURRENT_DIR}/framework/third_party/x86/ubuntu/hobotlog/include/
      ${XSTREAM_CURRENT_DIR}/framework/third_party/x86/ubuntu/jsoncpp/include/
      ${XSTREAM_CURRENT_DIR}/framework/third_party/x86/ubuntu/gtest/include/
      ${XSTREAM_CURRENT_DIR}/vision_type/include/
      ${RELEASE_ROOT_DIR}/deps/opencv/include/
    )
    link_directories(
      ${XSTREAM_CURRENT_DIR}/framework/third_party/x86/ubuntu/hobotlog/lib
      ${XSTREAM_CURRENT_DIR}/framework/third_party/x86/ubuntu/jsoncpp/lib/
      ${XSTREAM_CURRENT_DIR}/framework/third_party/x86/ubuntu/gtest/lib/
    )
  endif()
else()
  include_directories(
    ${RELEASE_ROOT_DIR}/deps/jsoncpp/include/
    ${RELEASE_ROOT_DIR}/deps/hobotlog/include/
    ${RELEASE_ROOT_DIR}/deps/opencv/include/
    ${RELEASE_ROOT_DIR}/deps/gtest/include/
    ${XSTREAM_CURRENT_DIR}/vision_type/include/
  )
  link_directories(
    ${RELEASE_ROOT_DIR}/deps/hobotlog/lib/
    ${RELEASE_ROOT_DIR}/deps/jsoncpp/lib/
    ${RELEASE_ROOT_DIR}/deps/gtest/lib/
  )
endif()

set(METHOD_FILES
  src/method/bbox_filter.cpp
  src/method/MultiSourceTestMethod.cpp
)

set(SOURCE_FILES ${METHOD_FILES}
  gtest_main.cc
  method_factory.cpp
)
set(BASE_LIBRARIES xstream hobotlog jsoncpp gtest pthread)

add_executable(method_init_test ${SOURCE_FILES} method_init_test.cpp)
target_link_libraries(method_init_test
  PUBLIC ${BASE_LIBRARIES}
)

if(XSTREAM_HOBOTSDK_ENGINE)
  message("XSTREAM_HOBOTSDK_ENGINE is:${XSTREAM_HOBOTSDK_ENGINE}")
else()
  add_executable(timer_test ${SOURCE_FILES} timer_test.cpp)
  target_link_libraries(timer_test
    PUBLIC ${BASE_LIBRARIES}
)
endif()

add_executable(xstream_unit_test ${SOURCE_FILES} method_cb.cpp)
target_link_libraries(xstream_unit_test
  PUBLIC ${BASE_LIBRARIES}
)

add_executable(cpp_api_test ${SOURCE_FILES}  cpp_api_test.cc)
target_link_libraries(cpp_api_test
  PUBLIC ${BASE_LIBRARIES}
)

add_executable(xstream_test ${SOURCE_FILES} xstream_test.cpp)
target_link_libraries(xstream_test
  PUBLIC ${BASE_LIBRARIES}
)

add_executable(node_test ${SOURCE_FILES} node_test.cpp)
target_link_libraries(node_test
  PUBLIC ${BASE_LIBRARIES}
)

add_executable(workflow_test ${SOURCE_FILES} subworkflow_test.cpp)
target_link_libraries(workflow_test
  PUBLIC ${BASE_LIBRARIES}
)

#add_executable(c_api_test c_api_test.cc gtest_main.cc)
#target_link_libraries(c_api_test bbox_filter gtest pthread)

set(THREAD_MODEL_SOURCES ${SOURCE_FILES}
  thread_model.cpp
  src/method/bbox_filter.cpp
  src/data_types/array.cpp
)
add_executable(xstream_threadmodel_test ${THREAD_MODEL_SOURCES})
target_link_libraries(xstream_threadmodel_test
  PUBLIC ${BASE_LIBRARIES}
)

set(THREAD_ORDER_SOURCES ${SOURCE_FILES}
  thread_order.cpp
  src/data_types/orderdata.cpp
)
add_executable(xstream_threadorder_test ${THREAD_ORDER_SOURCES})
target_link_libraries(xstream_threadorder_test
  PUBLIC ${BASE_LIBRARIES}
)

set(THREAD_SAFE_SOURCES ${SOURCE_FILES}
  thread_safe.cpp
  src/data_types/orderdata.cpp
)
add_executable(xstream_threadsafe_test ${THREAD_SAFE_SOURCES})
target_link_libraries(xstream_threadsafe_test
  PUBLIC ${BASE_LIBRARIES}
)

set(MULTISOURCE_TEST_SOURCES ${SOURCE_FILES}
  multisource_test.cpp
)
add_executable(xstream_multisource_test ${MULTISOURCE_TEST_SOURCES})
target_link_libraries(xstream_multisource_test
  PUBLIC ${BASE_LIBRARIES}
)

add_executable(config_test ${SOURCE_FILES} config_test.cpp)
target_link_libraries(config_test
  PUBLIC ${BASE_LIBRARIES}
)

set(THREAD_PRIORITY_SOURCES ${SOURCE_FILES}
  thread_priority_test.cpp
)
add_executable(xstream_thread_priority_test ${THREAD_PRIORITY_SOURCES})
target_link_libraries(xstream_thread_priority_test
  PUBLIC ${BASE_LIBRARIES}
)

set(THREAD_MANAGER_SOURCES ${SOURCE_FILES}
  thread_manager_test.cpp
)
add_executable(xstream_thread_manager_test ${THREAD_MANAGER_SOURCES})
target_link_libraries(xstream_thread_manager_test
  PUBLIC ${BASE_LIBRARIES}
)

set(XTHREAD_POOL_SOURCES ${SOURCE_FILES}
  xthread_pool_test.cpp
)
add_executable(xstream_xthread_pool_test ${XTHREAD_POOL_SOURCES})
target_link_libraries(xstream_xthread_pool_test
  PUBLIC ${BASE_LIBRARIES}
)

set(XTHREAD_SOURCES ${SOURCE_FILES}
  xthread_test.cpp
)
add_executable(xstream_xthread_test ${XTHREAD_SOURCES})
target_link_libraries(xstream_xthread_test
  PUBLIC ${BASE_LIBRARIES}
)
