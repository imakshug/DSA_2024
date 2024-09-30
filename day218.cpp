//1381. Design a Stack With Increment Operation

class CustomStack {
public:
    vector<int> arr;
    int n ;
    int top=-1;

    CustomStack(int maxSize) {
      n =maxSize;
             
    }
    
    void push(int x) {
       if(top< n-1){
        arr.push_back(x);
        top++;
       } 
       return;
    }
    
    int pop() {
        int poped =-1;
        if (top>=0){
             poped = arr[top];
            arr.pop_back();
            top--;
        }
        return poped;
        
    }
    
    void increment(int k, int val) {
        if(top<0){
            return;
        }
        if(k>top){
        for(int i=0; i<=top; i++){
            arr[i]=arr[i]+val;
        }}
        else{
            for(int i=0; i<k; i++){
            arr[i]=arr[i]+val;
        }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
