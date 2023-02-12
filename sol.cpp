
class intStPq
{

public:
  bool operator() (const pair<int, int> lhs, const pair<int, int> rhs) const
  {
      if (lhs.second == rhs.second) { return lhs.first < rhs.first; }
      return (lhs.second < rhs.second);
  }
};


class MaxStack {
private:
    pair<int, int> getTop() {
        if (s.empty()) { return pair(-1, -1); }
        pair<int, int> p = s.top();
        while (!s.empty() && m.find(p.first) == m.end()) {
            s.pop();
            p = s.top();
        }
        return p;
    }
    pair<int, int> getMax() {
        if (pq.empty()) { return pair(-1, -1); }
        pair<int, int> p = pq.top();
        while (!pq.empty() && m.find(p.first) == m.end()) {
            pq.pop();
            p = pq.top();
        }
        return p;
    }
public:
    unordered_map<int, int> m;
    stack<pair<int, int>> s;
    priority_queue<pair<int,int> , vector<pair<int, int>>, intStPq> pq;
    int time = 0;
    MaxStack() {
        m.clear();
    }
    
    void push(int x) {
        pair<int, int> p = pair(time, x);
        m[time] = x;
        s.push(p);
        pq.push(p);
        time++;
    }
    
    int pop() {
        pair<int, int> p = getTop();
        if (p.first == -1) { return -1; }
        
        m.erase(p.first);
        s.pop();
        return p.second;
    }
    
    int top() {
        pair<int, int> p = getTop();
        if (p.first == -1) { return -1; }
        return p.second;
    }
    
    int peekMax() {
        pair<int, int> p = getMax();
        if (p.first == -1) { return -1; }
        return p.second;
    }
    
    int popMax() {
        pair<int, int> p = getMax();
        if (p.first == -1) { return -1; }
        
        m.erase(p.first);
        pq.pop();
        return p.second;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
