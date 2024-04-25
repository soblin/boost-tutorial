function(add_demo target)
  add_executable(multi_index_${target} ${target}.cpp)
  target_include_directories(multi_index_${target} PUBLIC ${Boost_INCLUDE_DIRS})
  set_target_properties(multi_index_${target} PROPERTIES OUTPUT_NAME ${target})
  add_custom_target(
    run_multi_index_${target}
    COMMAND multi_index_${target}
  )
endfunction()

add_demo(set_with_insertion_order)
add_demo(tagged_index)
add_demo(multi_key_map)
add_demo(bidirectional_map)
