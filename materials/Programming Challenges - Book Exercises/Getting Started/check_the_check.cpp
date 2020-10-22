#include <iostream>


using namespace std;
char tab[8][8];

bool white = false;
bool black = false;

void solve(int i, int j){
    if(tab[i][j] == 'k' || tab[i][j] == 'K'){
        int movI[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int movJ[8] = {-1, 0, 1, 1, 1, 0, -1 ,-1};
        for(int k = 0; k < 8; k++){
            int new_i = i + movI[k], new_j = j + movJ[k];
            if(new_i < 0 || new_i > 7 || new_j < 0 || new_j > 7) continue;
            if(tab[i][j] == 'k' && tab[new_i][new_j] == 'K'){
                white = true;
                return;
            }
            if(tab[i][j] == 'K' && tab[new_i][new_j] == 'k'){
                black = true;
                return;
            }
        }
    }
    if(tab[i][j] == 'p' || tab[i][j] == 'P'){
        if(tab[i][j] == 'p'){
            int movI[2] = {1, 1};
            int movJ[2] = {-1, 1};
            for(int k = 0; k < 2; k++){
                int new_i = i + movI[k], new_j = j + movJ[k];
                if(new_i < 0 || new_i > 7 || new_j < 0 || new_j > 7) continue;
                if(tab[new_i][new_j] == 'K'){
                    white = true;
                    return;
                }
            }
        }else{
            int movI[2] = {-1, -1};
            int movJ[2] = {-1, 1};
            for(int k = 0; k < 2; k++){
                int new_i = i + movI[k], new_j = j + movJ[k];
                if(new_i < 0 || new_i > 7 || new_j < 0 || new_j > 7) continue;
                if(tab[new_i][new_j] == 'k'){
                    black = true;
                    return;
                }
            }
        }
    }
    
    if(tab[i][j] == 'n' || tab[i][j] == 'N'){
        int movI[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int movJ[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        for(int k = 0; k < 8; k++){
            int new_i = i + movI[k], new_j = j + movJ[k];
            if(new_i < 0 || new_i > 7 || new_j < 0 || new_j > 7) continue;
            if(tab[i][j] == 'n' && tab[new_i][new_j] == 'K'){
                white = true;
                return;
            }
            if(tab[i][j] == 'N' && tab[new_i][new_j] == 'k'){
                black = true;
                return;
            }
        }
    }

    if(tab[i][j] == 'r' || tab[i][j] == 'R'){
       
        for(int k = 1; k < 8; k++){
            int mov_top = i - k;
            
            if(mov_top < 0 || tab[mov_top][j] != '.'){
                if(mov_top < 0) break;
                if(tab[i][j] == 'r' && tab[mov_top][j] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'R' && tab[mov_top][j] == 'k'){
                    black = true;
                    
                    return;
                }
                break;
            }
        }
       
        for(int k = 1; k < 8; k++){
            int mov_botton = i + k;
            
            if(mov_botton > 7 || tab[mov_botton][j] != '.'){
                if(mov_botton > 7) break;
                if(tab[i][j] == 'r' && tab[mov_botton][j] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'R' && tab[mov_botton][j] == 'k'){
                    
                    black = true;
                    return;
                }
                break;
            }
        }
 
        for(int k = 1; k < 8; k++){
            int mov_right = j + k;
            
            if(mov_right > 7 || tab[i][mov_right] != '.'){
                if(mov_right > 7) break;
                if(tab[i][j] == 'r' && tab[i][mov_right] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'R' && tab[i][mov_right] == 'k'){
                    black = true;
                    
                    return;
                }
                break;
            }
        }
   
        for(int k = 1; k < 8; k++){
            int mov_left = j - k;
            
            if(mov_left < 0 || tab[i][mov_left] != '.'){
                if(mov_left < 0) break;
                if(tab[i][j] == 'r' && tab[i][mov_left] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'R' && tab[i][mov_left] == 'k'){
                    black = true;
                 
                    return;
                }
                break;
            }
        }
    }

    if(tab[i][j] == 'b' || tab[i][j] == 'B'){
        for(int k = 1; k < 8; k++){
            int mov_i_top_left = i - k, mov_j_top_left = j - k;
            
            if(mov_i_top_left < 0 || mov_j_top_left < 0 || tab[mov_i_top_left][mov_j_top_left] != '.'){
                if(mov_i_top_left < 0 || mov_j_top_left < 0) break;
                if(tab[i][j] == 'b' && tab[mov_i_top_left][mov_j_top_left] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'B' && tab[mov_i_top_left][mov_j_top_left] == 'k'){
                    black = true;
                    return;
                }
                break;
            }
        }

        for(int k = 1; k < 8; k++){
            int mov_i_botton_right = i + k, mov_j_botton_right = j + k;
            if(mov_i_botton_right > 7 || mov_j_botton_right > 7 || tab[mov_i_botton_right][mov_j_botton_right] != '.'){
                if(mov_i_botton_right > 7 || mov_j_botton_right > 7) break;
                if(tab[i][j] == 'b' && tab[mov_i_botton_right][mov_j_botton_right] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'B' && tab[mov_i_botton_right][mov_j_botton_right] == 'k'){
                    black = true;
                    return;
                }
                break;
            }
        }

        for(int k = 1; k < 8; k++){
            int mov_i_top_right = i - k, mov_j_top_right = j + k;
            if(mov_j_top_right > 7 || mov_i_top_right < 0 || tab[mov_i_top_right][mov_j_top_right] != '.'){
                if(mov_j_top_right > 7 || mov_i_top_right < 0) break;
                if(tab[i][j] == 'b' && tab[mov_i_top_right][mov_j_top_right] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'B' && tab[mov_i_top_right][mov_j_top_right] == 'k'){
                    black = true;
                    return;
                }
                break;
            }
        }
        for(int k = 1; k < 8; k++){
            int mov_i_botton_left = i + k, mov_j_botton_left = j - k;
           
            if(mov_j_botton_left < 0 || mov_i_botton_left > 7 || tab[mov_i_botton_left][mov_j_botton_left] != '.'){
                if(mov_j_botton_left < 0 || mov_i_botton_left > 7) break;
                if(tab[i][j] == 'b' && tab[mov_i_botton_left][mov_j_botton_left] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'B' && tab[mov_i_botton_left][mov_j_botton_left] == 'k'){
                    black = true;
                    return;
                }
                break;
            }
        }
    }
    if(tab[i][j] == 'q' || tab[i][j] == 'Q'){
        for(int k = 1; k < 8; k++){
            int mov_i_top_left = i - k, mov_j_top_left = j - k;
            if(mov_i_top_left < 0 || mov_j_top_left < 0 || tab[mov_i_top_left][mov_j_top_left] != '.'){
                if(mov_i_top_left < 0 || mov_j_top_left < 0) break;
                if(tab[i][j] == 'q' && tab[mov_i_top_left][mov_j_top_left] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'Q' && tab[mov_i_top_left][mov_j_top_left] == 'k'){
                    black = true;
                    return;
                }
                break;
            }
        }

        for(int k = 1; k < 8; k++){
            int mov_i_botton_right = i + k, mov_j_botton_right = j + k;
            if(mov_i_botton_right > 7 || mov_j_botton_right > 7 || tab[mov_i_botton_right][mov_j_botton_right] != '.'){
                if(mov_i_botton_right > 7 || mov_j_botton_right > 7) break;
                if(tab[i][j] == 'q' && tab[mov_i_botton_right][mov_j_botton_right] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'Q' && tab[mov_i_botton_right][mov_j_botton_right] == 'k'){
                    black = true;
                    return;
                }
                break;
            }
        }

        for(int k = 1; k < 8; k++){
            int mov_i_top_right = i - k, mov_j_top_right = j + k;
            if(mov_j_top_right > 7 || mov_i_top_right < 0 || tab[mov_i_top_right][mov_j_top_right] != '.'){
                if(mov_j_top_right > 7 || mov_i_top_right < 0) break;
                if(tab[i][j] == 'q' && tab[mov_i_top_right][mov_j_top_right] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'Q' && tab[mov_i_top_right][mov_j_top_right] == 'k'){
                    black = true;
                    return;
                }
                break;
            }
        }
        for(int k = 1; k < 8; k++){
            int mov_i_botton_left = i + k, mov_j_botton_left = j - k;
            if(mov_j_botton_left < 0 || mov_i_botton_left > 7 || tab[mov_i_botton_left][mov_j_botton_left] != '.'){
                if(mov_j_botton_left < 0 || mov_i_botton_left > 7) break;
                if(tab[i][j] == 'q' && tab[mov_i_botton_left][mov_j_botton_left] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'Q' && tab[mov_i_botton_left][mov_j_botton_left] == 'k'){
                    black = true;
                    return;
                }
                break;
            }
        }
        int movI[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int movJ[8] = {-1, 0, 1, 1, 1, 0, -1 ,-1};
        for(int k = 0; k < 8; k++){
            int new_i = i + movI[k], new_j = j + movJ[k];
            if(new_i < 0 || new_i > 7 || new_j < 0 || new_j > 7) continue;
            if(tab[i][j] == 'q' && tab[new_i][new_j] == 'K'){
                white = true;
                return;
            }
            if(tab[i][j] == 'Q' && tab[new_i][new_j] == 'k'){
                black = true;
                return;
            }
        }
        for(int k = 1; k < 8; k++){
            int mov_top = i - k;
            if(mov_top < 0 || tab[mov_top][j] != '.'){
                if(mov_top < 0) break;
                if(tab[i][j] == 'q' && tab[mov_top][j] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'Q' && tab[mov_top][j] == 'k'){
                    black = true;
                    return;
                }
                break;
            }
        }

        for(int k = 1; k < 8; k++){
            int mov_botton = i + k;
            if(mov_botton > 7 || tab[mov_botton][j] != '.'){
                if(mov_botton > 7) break;
                if(tab[i][j] == 'q' && tab[mov_botton][j] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'Q' && tab[mov_botton][j] == 'k'){
                    black = true;
                    return;
                }
                break;
            }
        }

        for(int k = 1; k < 8; k++){
            int mov_right = j + k;
            if(mov_right > 7 || tab[i][mov_right] != '.'){
                if(mov_right > 7) break;
                if(tab[i][j] == 'q' && tab[i][mov_right] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'Q' && tab[i][mov_right] == 'k'){
                    black = true;
                    return;
                }
                break;
            }
        }
        for(int k = 1; k < 8; k++){
            int mov_left = j - k;
            if(mov_left < 0 || tab[i][mov_left] != '.'){
                if(mov_left < 0) break;
                if(tab[i][j] == 'q' && tab[i][mov_left] == 'K'){
                    white = true;
                    return;
                }
                if(tab[i][j] == 'Q' && tab[i][mov_left] == 'k'){
                    black = true;
                    return;
                }
                break;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int c = 1;
   
    while (true){

        bool ok = true;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                cin >> tab[i][j];
                if(tab[i][j] != '.') ok = false;
            }
        }
        if(ok == true) break;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(tab[i][j] != '.') solve(i, j);
                if(white == true) break;
                if(black == true) break;
               
            }
        }
        if(white == true){
            cout << "Game #" << c << ": white king is in check." << endl;
        }else if(black == true){
            cout << "Game #" << c << ": black king is in check." << endl;
        }else{
            cout << "Game #" << c << ": no king is in check." << endl;
        }
        white = false;
        black = false; 
        c++;
        cin.ignore();
    }

    
    return 0;
}

