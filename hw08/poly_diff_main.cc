#include <iostream>
#include "poly_diff.h"

using namespace std;

int main(void) {
    string str;
    while(true) {
        cin >> str;
        if (str == "quit") {
            break;
        } else {
        	Differ differ;  	
        	differ.Spliting(str);
        	
        	int x;
        	cin >> x;
        	cout << differ.sumValue(x) << endl;
            
        }
    }
    return 0;
}
