project('data-structures', 'c')

sources = ['src/array_list.c', 'src/hashmap.c', 'src/linked_list.c', 'src/optional.c', 'src/slice.c', 'src/util.c']
includes = include_directories('include')

math_dep = meson.get_compiler('c').find_library('m', required: false)

lib = shared_library('data-structures', sources, include_directories: includes, dependencies: math_dep)
