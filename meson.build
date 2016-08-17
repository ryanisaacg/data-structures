project('data-structures', 'c')

ds_sources = ['src/hashmap.c', 'src/linked_list.c', 'src/optional.c', 'src/slice.c', 'src/util.c']
ds_includes = include_directories('include')

math_dep = meson.get_compiler('c').find_library('m', required: false)

ds_lib = shared_library('data-structures', ds_sources, include_directories: ds_includes, dependencies: math_dep)
