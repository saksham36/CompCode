class MyCircularQueue {
private:
    int size_;
    int filled_;
    int head_;
    int back_;
    vector<int> queue_;
public:
    MyCircularQueue(int k) {
        vector<int>q(k);
        this->queue_ = q;
        this->size_ = k;
        this->filled_ = 0;
        this->head_ = -1;
        this->back_ = -1;
        
    }
    
    bool enQueue(int value) {
        if(this->filled_ == this->size_) return false;
        if(this->isEmpty()) this->head_ = 0;
        this->back_ = (this->head_ + this->filled_) %this->size_;
        this->queue_[this->back_] = value;
        this->filled_ ++;
        return true;
        
    }
    
    bool deQueue() {
        if(this->isEmpty()) return false;
        // this->back_ = (this->head_ + this->filled_) %this->size_;
        if(this->head_== this->back_){
            this->head_--;
            this->back_--;
        }
        // if(this->head_ < this->back_) 
        this->head_ = (this->head_ + 1)%this->size_;
        // else
            
        this->filled_ -= 1;
        return true;
        
    }
    
    int Front() {
        if(this->isEmpty()) return -1;
        return this->queue_[this->head_];
        
        
    }
    
    int Rear() {
        if(this->isEmpty()) return -1;
        return this->queue_[this->back_];
        
    }
    
    bool isEmpty() {
        if(this->filled_) return false;
        return true;
        
    }
    
    bool isFull() {
        if(this->filled_ == this->size_) return true;
        return false;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */