#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    fs:: directory_entry cur(".");

    for (const auto& file : fs::directory_iterator(cur)) {
        std::cout << file.path() << std::endl;
    }

    return 0;
}
