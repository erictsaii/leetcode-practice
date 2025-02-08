class NumberContainers {
    public:
        unordered_map <int, int> idx_to_num;
        unordered_map <int, set<int>> num_to_idxs;
        NumberContainers() {}
        
        void change(int index, int number) {
            if (idx_to_num.count(index)) {
                num_to_idxs[idx_to_num[index]].erase(index);
            }
            idx_to_num[index] = number;
            num_to_idxs[number].insert(index);
        }
        
        int find(int number) {
            if (num_to_idxs[number].size() == 0) return -1;
            else return *num_to_idxs[number].begin();
        }
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */