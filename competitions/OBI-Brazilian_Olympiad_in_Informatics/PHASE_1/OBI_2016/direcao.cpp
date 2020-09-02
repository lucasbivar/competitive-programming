#include <iostream>
#include <string>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    string A, B;
    cin >> A >> B;
    if(A == "norte"){
        if(B == "sul"){
            cout << "180" << endl;
        }else if(B == "leste"){
            cout << "90" << endl;
        }else if(B == "norte"){
            cout << "0" << endl;
        }else if(B == "oeste"){
            cout << "90" << endl;
        }
    }else if(A == "sul"){
        if(B == "sul"){
            cout << "0" << endl;
        }else if(B == "leste"){
            cout << "90" << endl;
        }else if(B == "norte"){
            cout << "180" << endl;
        }else if(B == "oeste"){
            cout << "90" << endl;
        }
    }else if(A == "leste"){
        if(B == "sul"){
            cout << "90" << endl;
        }else if(B == "leste"){
            cout << "0" << endl;
        }else if(B == "norte"){
            cout << "90" << endl;
        }else if(B == "oeste"){
            cout << "180" << endl;
        }
    }else if(A == "oeste"){
        if(B == "sul"){
            cout << "90" << endl;
        }else if(B == "leste"){
            cout << "180" << endl;
        }else if(B == "norte"){
            cout << "90" << endl;
        }else if(B == "oeste"){
            cout << "0" << endl;
        }
    }
    return 0;
}