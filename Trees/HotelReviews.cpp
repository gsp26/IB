struct TrieNode
{
    TrieNode * children[26];
    bool eow;
};

TrieNode * getNode()
{
    TrieNode * pNode = new TrieNode;
    pNode->eow = false;
    for(int i=0;i<26;i++)
        pNode->children[i]= NULL;
    
    return pNode;
}

void insert(TrieNode *root,string key)
{
    TrieNode * pCrawl = root;
    for(int i=0;i<key.length();i++)
    {
        int index = key[i] - 'a';
        if(!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->eow = true;
}

bool search(TrieNode * root,string key)
{
    TrieNode * pCrawl = root;
    for(int i=0;i<key.length();i++)
    {
        int index = key[i] - 'a';
        if(!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->eow);
}

bool comp(pair<int,int> a,pair<int,int> b)
{
    if(a.second == b.second)
        return a.first<b.first;
    return a.second>b.second;
    
}
vector<int> Solution::solve(string A, vector<string> &B) {
    //create trie
    TrieNode * root = getNode();
    int start = 0;
    int end= 0;
    for(int i=0;i<A.length();i++)
    {
        if(A[i] == '_')
        {
            string key = A.substr(start,i-start);
            insert(root,key);
            start = i+1;
            end = i-1;
        }
        else
            continue;
    }
    string key = A.substr(start,A.size()-start+1);
    //cout << "Inserting : "  << key << endl;
    insert(root,key);

    vector<pair<int,int> > count; //index and good count 
    
    int ct = 0;
    for(int i=0;i<B.size();i++)
    {
        start = 0;
        string str = B[i];
        for(int j=0;j<str.size();j++)
        {
            if(str[j] == '_')
            {
                string key = str.substr(start,j-start);
                if(search(root,key))
                    ct++;
                start = j+1;
                end = j-1;
            }
        }
        string key = str.substr(start,str.size()-start);
        //cout << "Searching key : " << key << endl;
        if(search(root,key))
        {
            ct++;
            //cout << "Found key : " << key << endl;
        }

        count.push_back(make_pair(i,ct));
        ct = 0;
    }
    sort(count.begin(),count.end(),comp);
    vector<int> res;
    for(int i=0;i<count.size();i++)
        res.push_back(count[i].first);
    return res;
    
}
