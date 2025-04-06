class Router {
    pair<queue<vector<int>>, int> q;  // \U0001f448 Declare as class member
    unordered_map<int, deque<int>> destMap;
    unordered_set<long long> set;
public:
    long long encode(int source, int destination, int timestamp){
        return (long long)source<<44 | (long long)destination<<24 | timestamp;
    }
    // bool checkDup(queue<vector<int>> q, vector<int> packet){
    //     while(!q.empty()){
    //         vector<int> front = q.front();
    //         q.pop();
    //         int i;
    //         for(i=0; i<3; i++){
    //             if(front[i]!=packet[i]){
    //                 break;
    //             }
    //         }
    //         if(i==3) return true;
    //     }
    //     return false;
    // }


    Router(int memoryLimit) {
        // pair<queue<vector<int>>, int> q;
        q.second = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        long long encoded = encode(source, destination, timestamp);
        if(set.count(encoded)){
            return false;
        }else{
            q.first.push({source, destination, timestamp});
            set.insert(encoded);
            destMap[destination].push_back(timestamp);
            if(q.first.size()>q.second){
                vector<int> front = q.first.front();
                long long encoded = encode(front[0], front[1], front[2]);
                q.first.pop();
                destMap[front[1]].pop_front();
                set.erase(encoded);
            }
            return true;
        }
    }
    
    vector<int> forwardPacket() {
        if(!q.first.empty()){
            vector<int> front = q.first.front();
            q.first.pop();
            destMap[front[1]].pop_front();
            long long encoded = encode(front[0], front[1], front[2]);
            set.erase(encoded);
            return front;
        }else{
            return {};
        }
    }
    
    int getCount(int destination, int startTime, int endTime) {
        // return getTheCount(q.first, {destination, startTime, endTime});
        auto &dq = destMap[destination];
        auto l = lower_bound(dq.begin(), dq.end(), startTime);
        auto r = upper_bound(dq.begin(), dq.end(), endTime);
        return r - l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */