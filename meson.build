project('GTASA Fixes', 'cpp')

cc = meson.get_compiler('cpp')

lib_root = 'D:\Libraries' # your lib root

dep_detours = declare_dependency(
    include_directories: include_directories(lib_root / 'Detours\include'),
    dependencies: [cc.find_library('detours', dirs: lib_root / 'Detours\lib.X86'), cc.find_library('syelog', dirs: lib_root / 'Detours\lib.X86')],
)

shared_library('Fixes.dll', 'src/main.cpp', 
include_directories: ['D:\\Sources\\gta-reversed\\source\\game_sa', 
'D:\\Sources\\gta-reversed\\source\\game_sa\\RenderWare', 
'D:\\Sources\\gta-reversed\\source\\game_sa\\Core',
'D:\\Sources\\gta-reversed\\source\\'], 
 dependencies: [dep_detours])