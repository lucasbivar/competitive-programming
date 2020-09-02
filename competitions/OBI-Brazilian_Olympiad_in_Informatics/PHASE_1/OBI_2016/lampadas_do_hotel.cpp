#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int IA, IB, FA, FB;
    cin >> IA >> IB >> FA >> FB;
    if(IA == FA && IB == FB){
        cout << "0" << endl;
    }else if (IA == IB && FA == FB){
        if (IA != FA){
            cout << "1" << endl;
        }else{
            cout << "0" << endl;
        }
    }else if(IA == IB && FA != FB){
        if(IA == 0){
            if(FA < FB){
                cout << "2" << endl;
            }else{
                cout << "1" << endl;
            }
        }else{
            if(FA < FB){
                cout << "1" << endl;
            }else{
                cout << "2" << endl;
            }
        }
        
    }else if(IA != IB && FA == FB){
        if(FA == 0){
            if(IA > IB){
                cout << "1" << endl;
            }else{
                cout << "2" << endl;
            }
        }else{
            if(IA > IB){
                cout << "2" << endl;
            }else{
                cout << "1" << endl;
            }
        }
    }else if(IA != IB && FA != FB){
        if(IA < IB){
            if(FA > FB){
                cout << "1" << endl;
            }else{
                cout << "0" << endl;
            }
        }else{
            if(FA > FB){
                cout << "0" << endl;
            }else{
                cout << "1" << endl;
            }
        }
    }

    return 0;
}