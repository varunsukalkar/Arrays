class Node
{
    public:
    string data;
    Node * next;
    Node * back;
    Node(){
        data="0";
        next =nullptr;
        back=nullptr;

    }
    Node(string x){
        data=x;
        next =nullptr;
        back=nullptr;
    }
    Node(string x,Node * nex , Node * random){
        data=x;
        next = nex;
        back=random;
    }

};


class BrowserHistory {
public:
Node * currentpage;
    BrowserHistory(string homepage) {
        currentpage = new Node (homepage);

    }
    
    void visit(string url) {
    Node * newnode = new Node(url);
    currentpage->next = newnode;
    newnode->back=currentpage;
    currentpage=newnode;
    }
    
    string back(int steps) {
        while(steps){
            if(currentpage->back){
                currentpage=currentpage->back;
            }
            else{
                break;
            }
            steps--;
        }
        return currentpage->data;
    }

    
    string forward(int steps) {
        while(steps){
            if(currentpage->next){
                currentpage= currentpage->next;
            }
            else{
                break;
            }
            steps--;
        }
        return currentpage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */