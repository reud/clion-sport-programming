#include "../tasks/FPotion.cpp"

#include <bits/stdc++.h>
using namespace std;

namespace jhelper {

    struct Test {
        string input;
        string output;
        bool active;
        bool has_output;
    };

    bool check(string expected, string actual) {
        while(!expected.empty() && isspace(*--expected.end()))
            expected.erase(--expected.end());
        while(!actual.empty() && isspace(*--actual.end()))
            actual.erase(--actual.end());
        return expected == actual;
    }

} // namespace jhelper

signed main() {
    vector<jhelper::Test> tests = {
            {"3 9999999999\n3 6 8\n", "4999999994\n", true, true},{"1 1000000000000000000\n1\n", "999999999999999999\n", true, true},
    };
    bool allOK = true;
    int testID = 0;
    cout << fixed;
    double maxTime = 0.0;
    cout << endl;
    for(const jhelper::Test& test: tests ) {
        cout << "\033[4m" << "Test #" << ++testID << "\033[m" << endl;
        cout << "Input: \n" << test.input << endl;
        if (test.has_output) {
            cout << "Expected output: \n" << test.output << endl;
        }
        else {
            cout << "Expected output: \n" << "N/A" << endl;
        }
        if (test.active) {
            stringstream in(test.input);
            ostringstream out;
            clock_t start = clock();
            FPotion solver;
            solver.solve(in, out);
             clock_t finish = clock();
            double currentTime = double(finish - start) / CLOCKS_PER_SEC;
            maxTime = max(currentTime, maxTime);
            cout << "Actual output: \n" << out.str() << endl;
            if (test.has_output) {
                bool result = jhelper::check(test.output, out.str());
                allOK = allOK && result;

                if (result) {
                    cout << "Result: " << "\033[32m OK \033[m" << endl;
                }
                else {
                    cout << "Result: " << "\033[31m WA \033[m" << endl;
                }
            }
            cout << "Time: " << currentTime << endl;
        }
        else {
            cout << "SKIPPED\n";
        }


        cout << endl;

    }
    if(allOK) {
        cout << "\033[32m" << "All OK" << "\033[m"<< endl;
    }
    else {
        cout << "\033[31m" << "Some cases failed" << "\033[m"<< endl;
    }
    cout << "Maximal time: " << maxTime << "s." << endl;
    return 0;
}