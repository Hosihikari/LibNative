# LibNative
Native part of native interop

# Update `funchook`
`git clone https://github.com/kubo/funchook.git`
`cd funchook && mkdir build && cd build`
`cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_POSITION_INDEPENDENT_CODE=ON  -DCMAKE_INSTALL_PREFIX=[path to]/LibNative -DFUNCHOOK_DISASM=zydis ../../funchook`
