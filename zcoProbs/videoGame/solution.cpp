#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,h;
	cin >> n >> h;
	vector<int> stacks(n);
	for (int i = 0; i<n; i++){
	    cin >> stacks[i];
	}
	bool craneBusy = false;
	int pos = 1;
    while(true){
        int command;
        cin >> command;
        if (command == 0) break;
        switch (command){
            case 1:
                if (pos != 1){
                    pos--;
                }
                break;
            case 2:
                if (pos != n){
                    pos++;
                }
                break;
            case 3:
                if (!craneBusy && stacks[pos-1] > 0){
                    craneBusy = true;
                    stacks[pos-1]--;
                }
                break;
            case 4:
                if (craneBusy && stacks[pos-1] < h){
                    stacks[pos-1]++;
                    craneBusy = false;
                }
                break;
            default:
                break;
        }
    }
    for(int i = 0; i<n; i++){
        cout << stacks[i] << ' ';
    }
}
