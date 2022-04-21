class MyHashSet {
public:
    vector<int>m;
    MyHashSet() {
        m.resize(1000001,0);
    }
    
    void add(int key) {
        m[key]++;
    }
    
    void remove(int key) {
        if(m[key]==0) return;
        m[key]=0;
    }
    
    bool contains(int key) {
        if(m[key]>0) return 1;
        return 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */