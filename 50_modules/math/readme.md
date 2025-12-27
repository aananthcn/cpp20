# Step 1
/opt/homebrew/opt/llvm/bin/clang++ -std=c++20 -x c++-module -c math.cppm -fmodule-output=math.pcm


# Step 2
/opt/homebrew/opt/llvm/bin/clang++ -std=c++20 math.cpp -fprebuilt-module-path=. math.pcm -o module_math
