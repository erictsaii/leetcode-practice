class ProductOfNumbers {
    public:
        vector<int> v;
        int recent_zero = -1;
        int product = 1;
        ProductOfNumbers() {
            v.push_back(1);
        }
        
        void add(int num) {
            if (num == 0) {
                v = {1};
            }
            else {
                v.push_back(v.back() * num);
            }
        }
        
        int getProduct(int k) {
            int n = v.size() - 1;
            if (k > n) return 0;
            else return v[n] / v[n - k];
        } 
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */