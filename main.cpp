#include <iostream>

enum AssetType {
    CURRENCY, CRYPTO, METAL, BANK
};

struct Rate {
    double buy;
    double sell;
    double count;
    AssetType type;
};

struct RateMetal {
    double buy;
    double sell;
    double weight;
    AssetType type;
};

int main() {
    return 0;
}
