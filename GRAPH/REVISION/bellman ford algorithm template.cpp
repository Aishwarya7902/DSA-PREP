for(int count=1;count<=V-1;count++){
            for(auto &edge:edges){
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                if(result[u]!=1e8){
                    if(result[u]+wt<result[v]){
                        result[v]=result[u]+wt;
                    }
                }
            }
        }
