#include "BUIDFinder.h"
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int findValidBUIDs() {
    ifstream inFile("BigData.txt");

    if (!inFile.is_open()) {
        cerr << "Unable to open file." << endl;
        return -1;
    }

    char ch, nextCh;
    int total = 0, count = 0;
    bool eight = false;

    while (inFile.get(ch)) {
        eight = false;

        if (ch == 'U') {
            total = 0;

            for (int i = 1; i <= 8; i++) {
                if (!inFile.get(nextCh)) break;
                if (isdigit(nextCh)) {
                    total += (nextCh - '0');
                } else {
                    total = 0;
                    break;
                }
                if (i == 8) eight = true;
            }

            if (total > 28 && eight && !isdigit(inFile.peek())) {
                count++;
            }
        }
    }

    inFile.close();
    return count;
}
