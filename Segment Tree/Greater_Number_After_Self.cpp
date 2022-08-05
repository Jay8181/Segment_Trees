class Solution {
public:
    vector<int>SegmentTree;
    void update(int ind, int s, int e, int val)
    {
        if(s > e)
             return;
        if(s == e)
        {
            SegmentTree[ind]++;
            return;
        } 
        int mid = s + (e-s)/2;
        if(val<=mid)
            update(2*ind+1,s,mid,val);
        else
            update(2*ind+2,mid+1,e,val);
        SegmentTree[ind] = SegmentTree[2*ind+1] + SegmentTree[2*ind+2]; 
    }
    
    
    int query(int ind, int s, int e, int qs,int qe)
    {
        if(s > e || qe < s || qs > e)
            return(0);
        if(s >= qs && e<=qe)
            return(SegmentTree[ind]);
        int mid = s + (e-s)/2;
        int l = query(2*ind+1, s, mid, qs, qe);
        int r = query(2*ind+2, mid+1, e, qs, qe);
        return(l+r);
        
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        
        int maxi = INT_MIN;
        vector<int>vect(nums.size(),0);
        for(int i = 0;i<nums.size();i++)
        {
            nums[i]+=10000;
            maxi = max(maxi,nums[i]);
        }
        SegmentTree.resize((maxi + 1) * 4,0);
        int sz = nums.size();
        for(int i = sz-1;i>=0;i--)
        {
            cout<<nums[i]<<endl;
            update(0,0,maxi,nums[i]);
            cout<<nums[i]<<endl;
            int l = nums[i]+1; int r = maxi;
           int val = query(0,0,maxi,l,r);
           vect[i] = val;
        }
      return(vect);
    }
};