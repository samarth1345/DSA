string manachers(string s){
        string temp=s;
        string new_s="#";
        for(char i:s){
            new_s+=i;
            new_s+='#';
        }
        s=new_s;
        int center=0,left=0,right=0,idx=0;
        vector<int> d(s.length());
        while(idx < s.length()){
            //mirroring
            if(idx < right && (idx+d[2*center-idx] < right)){
                d[idx]=d[2*center-idx];
                idx++;
                continue;
            }
            int i=1;
            //expanding
            for(;i<s.length();i++){
                if(idx-i<0 || idx+i>=s.length() || s[idx-i]!=s[idx+i])
                    break;
            }
            d[idx]=i-1;
            //changing center
            if(idx+right > center+right){
                center=idx;
                left=idx-i+1;
                right=idx+i-1;
            }
            idx++;
        }
        int mx_i=0,mx=0;
        for(int i=0;i<d.size();i++){
            if(mx<d[i]){
                mx=d[i];
                mx_i=i;
            }
        }
        return temp.substr((mx_i/2)-(mx/2),mx);
    }
