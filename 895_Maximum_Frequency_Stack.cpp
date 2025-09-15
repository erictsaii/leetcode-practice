class FreqStack {
public:
    unordered_map<int, stack<int>> freq_to_stack; // freq, that freq's stack  
    unordered_map<int, int> freq; // val, freq
    int max_freq = 0;

    FreqStack() {}
    
    void push(int val) {
        int f = ++freq[val];
        max_freq = max(max_freq, f);
        freq_to_stack[f].push(val);
    }
    
    int pop() {
        int rtn = freq_to_stack[max_freq].top();
        freq[rtn]--;
        freq_to_stack[max_freq].pop();
        if (freq_to_stack[max_freq].empty()) max_freq--;
        return rtn;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
