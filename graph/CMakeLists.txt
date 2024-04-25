function(add_demo target)
  add_executable(graph_${target} ${target}.cpp)
  target_include_directories(graph_${target} PUBLIC ${Boost_INCLUDE_DIRS})
  set_target_properties(graph_${target} PROPERTIES OUTPUT_NAME ${target})
  add_custom_target(
    run_graph_${target}
    COMMAND graph_${target}
  )
endfunction()

add_demo(create)
add_demo(property)
