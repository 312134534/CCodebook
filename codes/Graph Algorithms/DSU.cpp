void initialise(int n,int parent[]){
    for (int i=0;i<n;i++){
        parent[i]=i;
    }
}

int find(int x,int parent[]){
    if (parent[x]==x){
        return x;
    }
    else{
        return parent[x]=find(parent[x],parent);
    }
}

void merge (int x,int y,int parent[]){
    int x_root=find(x,parent);
    int y_root=find(y,parent);
    parent[x_root]=y_root;   
}
