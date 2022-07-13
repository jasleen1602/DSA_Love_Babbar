
int runCustomerSimulation(int n, string s){
    int ans = 0;
    int unoccupied = n;
    map<char, int> mp;
    for(int i=0; i<s.size(); i++){
        if(!mp[s[i]]){ 
            mp[s[i]]=1;
            if(unoccupied!=0){
                unoccupied--;
                mp[s[i]]=2;
            }
            else
                ans++;
        }
        else if(mp[s[i]]==2)
            unoccupied++;
            mp[s[i]]=0;
        }
        else 
            mp[s[i]]=0;
    }
    return ans;
}