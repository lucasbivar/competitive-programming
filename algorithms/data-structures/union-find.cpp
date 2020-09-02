#define MAXN 100100

int father[MAXN]; // create the vector that will store the parents

// function find: return the patriarch of an element x
int find(int x){ 

    // if he is the father of himself, he is the patriarch
    if(father[x]==x) return x;

    // if not, return the value of your father's patriarch
    return father[x]=find(father[x]); //but remember to save him in father[x]
}

// function join: joins the sets of elements x and y
void join(int x, int y){
    
    // just make the patriarch of one become the father of the patriarch of the other
    father[find(x)]=find(y);
}