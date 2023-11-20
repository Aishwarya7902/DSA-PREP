/*WE ALREADY SOLVED THIS QUESTION USING PRIORITY QUEUE ...THEN WHY TO DO THE SAME THING USING SET....?????????🤔💭
Answer : coz when we solve using priority queue then we may have to process the same node with a higher cost in the latter part...
now the thing is if u already have a lower cost to reach that node , then why are u considering the higher cost?
hence we delete it ....which is possible only in set not in priority queue


*/


PROBLEM:https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=3qIoYIMidpc&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=25

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int source)
    {
        // Code here
        vector <int>result(V,INT_MAX);
        set<pair<int,int>>st;
        
        result[source]=0;
        st.insert({0,source});
        
        while(!st.empty()){
            auto &it=*st.begin();
            int d=it.first;
            int node=it.second;
            
            st.erase(it);
            
            //exploring adjacent nodes
            for(auto &vec:adj[node]){
                int adjNode=vec[0];
                int adjDist=vec[1];
                
                if(d+adjDist<result[adjNode]){
                    
                    if(result[adjNode]!=INT_MAX){ //if greater distance for that node exists in set....delete it coz it is of no use
                        st.erase({result[adjNode],adjNode});
                        
                        /*METHOD 2 TO ERASE IN SET
                        auto iterartor=st.find({result[adjNode],adjNode});
                        st.erase(iterator);
                        */
                    }
                    result[adjNode]=d+adjDist;
                    st.insert({d+adjDist,adjNode});
                }
            }
        }
        
        return result;
        
    }
};
