#include "../Includes/IPAddress.h"

int main() {
    Range** ranArr = new Range*[5];

    ranArr[0] = new Range("0.0.0.0/30");
    ranArr[1] = new Range("0.0.0.0/29");
    ranArr[2] = new Range("0.0.0.0/28");
    ranArr[3] = new Range("0.0.0.0/17");
    ranArr[4] = new Range("0.0.0.0/26");

    for(int i = 0; i < 5; i++) {
        if(ranArr[i]->isValid()) {
            std::cout << ranArr[i]->findMax()->asString() << '\n';
        }
    }

    return 0;
}