# Step 1
/opt/homebrew/opt/llvm/bin/clang++ -std=c++20 -x c++-module -c math.cppm -fmodule-output=math.pcm


# Step 2
/opt/homebrew/opt/llvm/bin/clang++ -std=c++20 math.cpp math_impl.cpp -fprebuilt-module-path=. math.pcm -o math
