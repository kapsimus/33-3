#include <iostream>
#include <string>
#include "Registry.h"

int main() {
    Registry<std::string, int> registry;
    registry.add("aa", 10);
    registry.add("bb", 20);
    registry.add("aa", 30);
    registry.add("cc", 40);
    registry.print();
    std::vector<Record<std::string, int>> find;
    registry.find(find, "aa");
    if (!find.empty()) {
        std::cout << "Records found:" << std::endl;
        for (Record<std::string, int> rec: find) {
            std::cout << "Key: " << rec.key << "\t\t" << "Value: " << rec.value << std::endl;
        }
    }
    std::cout << "remove cc" << std::endl;
    registry.remove("cc");
    registry.print();
    return 0;
}
