function(add_demo target)
  add_executable(scope_exit_${target} ${target}.cpp)
  target_include_directories(scope_exit_${target} PUBLIC ${Boost_INCLUDE_DIRS})
  set_target_properties(scope_exit_${target} PROPERTIES OUTPUT_NAME ${target})
  add_custom_target(
    run_scope_exit_${target}
    COMMAND scope_exit_${target}
  )
endfunction()

add_demo(for_loop)
