int find(int x,vector<int>&parent){
    if(i==parent[i])
     return i;

    return parent[i]=find(parent[i],parent);

}

void Union(int x,int y, vector<int>&parent, vector<int>&rank){
    int x_parent=find(x,parent);
    int y_parent=find(y,parent);

    if(x_parent==y_parent){
        //if both parent are same it means wo dono same set me hain
        return;
    }

    if(rank[x_parent]>rank[y_parent]){
        // jiska rank jyada hai wo papa banega ...but uske rank me koi change ni aayega 
        parent[y_parent]=x_parent;
    }

    else if(rank[x_parent]<rank[y_parent]){
        // jiska rank jyada hai wo papa banega ...but uske rank me koi change ni aayega 
        parent[x_parent]=y_parent;
    }
    else{
        //agar rank same hai to kisi ko bhi papa bana do...aur jo papa banega uska rank ek badh jayega
        parent[x_parent]=y_parent;
        rank[y_parent]+=1;
    }
}
