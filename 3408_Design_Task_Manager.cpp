class TaskManager {
public:
    priority_queue<tuple<int, int, int>> pq; // priority, task, user
    unordered_map<int, int> task_to_priority;
    unordered_map<int, int> task_to_user;


    TaskManager(vector<vector<int>>& tasks) { // user, task, priority
        for (auto& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];

            task_to_priority[taskId] = priority;
            task_to_user[taskId] = userId;
            pq.push({priority, taskId, userId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        task_to_priority[taskId] = priority;
        task_to_user[taskId] = userId;
        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        task_to_priority[taskId] = newPriority;
        int userId = task_to_user[taskId];
        pq.push({newPriority, taskId, userId});
    }
    
    void rmv(int taskId) {
        task_to_priority[taskId] = -1;
        task_to_user[taskId] = -1;
    }
    
    int execTop() {
        while (!pq.empty() && get<0>(pq.top()) != task_to_priority[get<1>(pq.top())]) {
            pq.pop();
        }

        if (pq.empty()) return -1;
        
        int taskId = get<1>(pq.top());
        int userId = get<2>(pq.top());
        task_to_priority[taskId] = -1;
        task_to_user[taskId] = -1;

        pq.pop();
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
