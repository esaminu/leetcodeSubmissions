class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> hp2;
    priority_queue<int> hp1;
public:
    void addNum(int num) {
        if(!hp1.size() || num < hp1.top()) {
            hp1.push(num);
        } else {
            hp2.push(num);
        }
        int diff = abs((int)(hp2.size() - hp1.size()));
        if(diff > 1) {
            if(hp2.size() > hp1.size()) {
                while(abs((int)(hp2.size() - hp1.size()))) {
                    hp1.push(hp2.top());
                    hp2.pop();
                }
            } else {
                while(abs((int)(hp2.size() - hp1.size()))) {
                    hp2.push(hp1.top());
                    hp1.pop();
                }
            }
        }
    }
    
    double findMedian() {
        if(hp1.size() > hp2.size()) {
            return hp1.top();
        } else if(hp2.size() > hp1.size()) {
            return hp2.top();
        } else {
            return (double)(hp1.top() + hp2.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */