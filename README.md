BLOCKIT's godot remake
on ubisoft system make sure to use the nativescript1.1 branch for building

- [ ] steps to build
    - [ ] cd godot-cpp then scons platform=windows bits=64 generate_bindings=yes target=debug
    - [ ] then make sure that in godot-cpp/bin/godot-cpp.windows.debug.64.lib (for target=debug) or appropriate library bindings are generated
    - [ ] cd blockit_godot then scons platform=windows target=debug
- [ ] for now target=debug only works
    - [ ] may be beacuse of -MDd in SConstruct CCFLAGS