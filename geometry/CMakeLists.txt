function(add_demo target)
  add_executable(geometry_${target} ${target}.cpp)
  target_include_directories(geometry_${target} PUBLIC ${Boost_INCLUDE_DIRS})
  set_target_properties(geometry_${target} PROPERTIES OUTPUT_NAME ${target})
  add_custom_target(
    run_geometry_${target}
    COMMAND geometry_${target}
  )
endfunction()

add_demo(disjoint)
add_demo(within)
add_demo(area)
add_demo(equals)
add_demo(scale)
add_demo(centroid)
add_demo(convex_hull)
add_demo(distance)
add_demo(set_operation)
add_demo(envelope)
add_demo(rotate)
