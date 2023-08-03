class Node{
    public:
    Node*lists[26]={NULL};
    bool flag=false;

    bool containsKey(char ch){
        return lists[ch-'a']!=NULL;
    }
    void put(char ch,Node*node){
        lists[ch-'a']=node;
    }
    Node* moveAhead(char ch){
        return lists[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }

};
class Trie {
public:
Node*root;
    Trie() {
        root=new Node();
    }
    
    void insert(string& word) {
        Node*temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(temp->containsKey(ch)==0){
                 temp->put(ch,new Node());
            }
             temp=temp->moveAhead(ch);
        }
        temp->setEnd();
    }
    
    bool search(string& word) {
        Node*temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(temp->containsKey(ch)==0)return false;
            temp=temp->moveAhead(ch);
        }
        return temp->isEnd();
    }
    
    bool startsWith(string& word) {
         Node*temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(temp->containsKey(ch)==0)return false;
            temp=temp->moveAhead(ch);
        }
        return true;
    }
};