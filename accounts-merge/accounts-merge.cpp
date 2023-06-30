class DisjointSet{
    public:
    vector<int> size, parent;

    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i =0 ; i< n; i++)   parent[i] = i;
    }

    int findPar(int node){
        if(node == parent[node])    return node;

        return parent[node] = findPar(parent[node]); 
    }

    void unionBySize(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if(ulp_u == ulp_v)  return;
        else if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += ulp_v;
        }
    }
};

class Solution {
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        // creating the mapping of emails to their corresponding indexes and if already mapped then
        //  joining  them to the ultimate parent in the disjoint set

        unordered_map<string, int> mailToNode;

        for(int i = 0 ; i< n ; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];

                if(mailToNode.find(mail) == mailToNode.end()){
                    mailToNode[mail] = i;
                }
                else{
                    ds.unionBySize(i, mailToNode[mail]);
                }
            }
        }

        // creating a string vector and pushing the mail to the corresponding index by finding ultimate parent
        vector<string> mergedMails[n];

        for(auto it: mailToNode){
            string mail = it.first;
            int index = ds.findPar(it.second);

            mergedMails[index].push_back(mail);
        }


        // create a 2d ans vector and a temp array(for each iteation) and first push the original name in temp and then push the sorted mails one by one in the temp array and finally push each temp vector into the ans array and return the ans;

        vector<vector<string>> ans;

        for(int i = 0 ; i < n ; i++){

            if(mergedMails[i].size() == 0)   continue;

            vector<string> temp;
            sort(mergedMails[i].begin(), mergedMails[i].end());

            temp.push_back(accounts[i][0]); //name of account holder

            for(auto it: mergedMails[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);

        }

        return ans;
    }
};