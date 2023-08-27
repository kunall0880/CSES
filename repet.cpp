
#include <iostream>
#include <string>

int main() {
    std::string a;
    int i = 0, maxCount = 1;
    std::getline(std::cin, a);

    int l = a.length();
    if (l == 0) {
        std::cout << "0" << std::endl;
        return 0;
    }

    char currentChar = a[0];
    int currentCount = 1;

    for (i = 1; i < l; i++) {
        if (a[i] == currentChar) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
            currentChar = a[i];
            currentCount = 1;
        }
    }

    if (currentCount > maxCount) {
        maxCount = currentCount;
    }

    std::cout << maxCount << std::endl;

    return 0;
}
