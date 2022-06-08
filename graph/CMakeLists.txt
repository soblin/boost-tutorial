function(add_demo target)
  add_executable(${target} ${target}.cpp)
  target_include_directories(${target} PUBLIC ${Boost_INCLUDE_DIRS})
endfunction()

add_demo(create)
add_demo(property)
