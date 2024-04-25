function(add_demo target)
  add_executable(uuid_${target} ${target}.cpp)
  target_include_directories(uuid_${target} PUBLIC ${Boost_INCLUDE_DIRS})
  set_target_properties(uuid_${target} PROPERTIES OUTPUT_NAME ${target})
  add_custom_target(
    run_uuid_${target}
    COMMAND uuid_${target}
  )
endfunction()

add_demo(uuid)
add_demo(uuid_hashmap)
