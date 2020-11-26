#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, digito[1005];
    cin >> N;

    for( int i = 0; i < N; i++ )
    cin >> digito[i];

    int zero_mais_esquerda = -1; // zero mais a esquerda
    int cinco_mais_direita = -1; // cinco mais a direita
    int zero_ou_cinco_mais_esquerda = -1; // zero ou cinco, mais a esquerda

    for( int i = 0; i < N; i++ ){
    if ( digito[i] == 0 && zero_mais_esquerda == -1 ) zero_mais_esquerda = i;
    if ( digito[i] == 5 ) cinco_mais_direita = i;
    if ( (digito[i] == 5 || digito[i] == 0) && zero_ou_cinco_mais_esquerda == -1 ) zero_ou_cinco_mais_esquerda = i; 
    }

    // nenhum digito 0, nem digito 5
    if ( zero_ou_cinco_mais_esquerda == -1 ){
    cout << -1 << endl;
    return 0;
    }

    if ( digito[N-1] < 5 ){ // digito da unidade: 1, 2, 3 ou 4
        if ( zero_mais_esquerda != -1 ){
            swap( digito[zero_mais_esquerda], digito[N-1] );
        } else {
            swap( digito[cinco_mais_direita], digito[N-1] );
        }
    } else { // digito da unidade: 6, 7, 8 ou 9
        swap( digito[zero_ou_cinco_mais_esquerda], digito[N-1] );
    }

    for( int i = 0; i < N; i++ ){
        cout << digito[i];
    if ( i < N-1 ) cout << " ";
    }
        cout << endl;
    return 0;
}