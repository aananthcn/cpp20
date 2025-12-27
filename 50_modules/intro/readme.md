# Step 1
/opt/homebrew/opt/llvm/bin/clang++ -std=c++20 -x c++-module -c intro.cppm -fmodule-output=intro.pcm


# Step 2
/opt/homebrew/opt/llvm/bin/clang++ -std=c++20 module_intro.cpp -fprebuilt-module-path=. intro.pcm -o module_intro
