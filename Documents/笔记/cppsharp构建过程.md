1. 二进制的cppsharp官方下载不到。
2. cppsharp没有cmakelists.txt，自己写起来也比较麻烦。
3. 自己下载llvm，然后安装，避免了需要翻墙和llvm下载包找不到等问题。
4. 需要将build.sh的 download_llvm 这一行注释掉，避免它又去下载。
5. 在llvm/llvm.lua里修改get_vs_version 直接返回你需要的vs版本。
6. 在llvm.lua里searchLLVM里将LLVMRootDirDebug， LLVMRootDirRelease修改为你安装llvm的路径。
7. 按照GettingStarted.mk里的指令执行build.sh