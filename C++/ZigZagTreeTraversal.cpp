 vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	
    	bool ltr=true;
    	vector<int>ans;
    	if(root==NULL) return ans;
    	queue<Node*>q;
    	q.push(root);
    	while(!q.empty())
    	 {
    	    
    	     int size=q.size();
    	     vector<int>res(size);
    	     for(int i=0;i<size;i++)
    	       {
    	           auto node=q.front();
    	           q.pop();
    	           
    	           int ind=ltr?i:(size-i-1);
    	           
    	           res[ind]=node->data;
    	           if(node->left) q.push(node->left);
    	           if(node->right)q.push(node->right);
    	           
    	           
    	       }
    	      ltr=abs(ltr-1);
    	      for(auto it:res)ans.push_back(it);
    	  }
    	 return ans;
    	
    
    	
    }
